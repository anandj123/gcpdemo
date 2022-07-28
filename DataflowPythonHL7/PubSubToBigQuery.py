# Copyright 2019 Google LLC.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


'''
Run the following command to deploy the code to GCP dataflow
-----------------------------------------------------------

python3 PubSubToBigQuery.py \
--project=$PROJECT_ID \
--bigquery_project=$BIGQUERY_PROJECT_ID \
--region=us-central1 \
--input_topic=$TOPIC_ID \
--output_dataset=$DATASET_ID \
--output_table=$TABLE_ID \
--runner=DataflowRunner \
--window_size=1 \
--temp_location=$BUCKET_ID/temp

Test messages
------------------
ADT:SEGMENTS&MSH:201601190838:HL7CDMADT:COCQA1A,0001|COCQA1A|MT_COCQA1A_ADT_QA1AGTADM.1.229576.567|J000423598|J500217|J00021004053||^~\&||MT_COCQA1A|||COCQA1A|||DBM||||||||201601190838||ADT|A02|||D|||2.1||||||||||||||||||||||||||||||||||||||||||||||||KYA||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||HL7CDMADT    
ADT:SEGMENTS&EVN:201601190838:HL7CDMADT:COCQA1A,0002|COCQA1A|MT_COCQA1A_ADT_QA1AGTADM.1.229576.567|J000423598|J500217|J00021004053||A02|201601190838||||||||||||||||||||||||||1TSQBE8554||HAMMOCK|||||BRITTANY||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||HL7CDMADT
MSH|^~\&|MT_COCQA1A|COCQA1A|DBM||201601190838||ADT^A02|MT_COCQA1A_ADT_QA1AGTADM.1.229576.567|D|2.1||KYA
EVN|A02|201601190838|||1TSQBE8554^HAMMOCK^BRITTANY^JACK^WARREN^^


Create tables
-------------------
bq mk --table anand-bq-test-2:hca_test.hl7pubsub bq_hl7pubsub_schema.json
bq mk --table anand-bq-test-2:hca_test.hl7pubsub_dlq bq_hl7pubsub_dlq_schema.json


'''


# [START pubsub_to_bigquery]
import argparse
import datetime
import json
import logging

import apache_beam as beam
import apache_beam.transforms.window as window
from apache_beam.options.pipeline_options import PipelineOptions
from google.cloud import bigquery
import json

class phone(dict):
    def __init__(self, name,phone):
        dict.__init__(self, name=name,phone=phone)
class address(dict):
    def __init__(self, addr,state,zip):
        dict.__init__(self, addr=addr,state=state,zip=zip)
class record(dict):
    def __init__(self, hl7):
        segs = hl7["message_body"].split("|")
        ph1 = []
        ad1 = []
        if segs[0] == "MSH":
            for m in segs[8].split('^'):
                ph1.append(phone(segs[2],m))
        elif segs[0] == "EVN":
            for m in segs[5].split('^'):
                if m == "": continue
                ad1.append(address(segs[1],segs[2],m))
        dict.__init__(self, type=segs[0],phone=ph1,address=ad1)

class GroupWindowsIntoBatches(beam.PTransform):
    """A composite transform that groups Pub/Sub messages based on publish
    time and outputs a list of dictionaries, where each contains one message
    and its publish timestamp.
    """

    def __init__(self, window_size):
        # Convert minutes into seconds.
        self.window_size = int(window_size * 60)

    def expand(self, pcoll):
        return (
            pcoll
            # Assigns window info to each Pub/Sub message based on its
            # publish timestamp.
            | "Window into Fixed Intervals"
            >> beam.WindowInto(window.FixedWindows(self.window_size))
            | "Add timestamps to messages" >> beam.ParDo(AddTimestamps())
            # Use a dummy key to group the elements in the same window.
            # Note that all the elements in one window must fit into memory
            # for this. If the windowed elements do not fit into memory,
            # please consider using `beam.util.BatchElements`.
            # https://beam.apache.org/releases/pydoc/current/apache_beam.transforms.util.html#apache_beam.transforms.util.BatchElements
            | "Add Dummy Key" >> beam.Map(lambda elem: (None, elem))
            | "Groupby" >> beam.GroupByKey()
            | "Abandon Dummy Key" >> beam.MapTuple(lambda _, val: val)
        )


class AddTimestamps(beam.DoFn):
    def process(self, element, publish_time=beam.DoFn.TimestampParam):
        """Processes each incoming windowed element by extracting the Pub/Sub
        message and its publish timestamp into a dictionary. `publish_time`
        defaults to the publish timestamp returned by the Pub/Sub server. It
        is bound to each element by Beam at runtime.
        """

        yield {
            "message_body": element.decode("utf-8"),
            "publish_time": datetime.datetime.utcfromtimestamp(
                float(publish_time)
            ).strftime("%Y-%m-%d %H:%M:%S.%f"),
        }


class WriteBatchesToBigQuery(beam.DoFn):
    def __init__(self, bigquery_project,output_dataset,output_table):
        self.bigquery_project = bigquery_project
        self.output_dataset = output_dataset
        self.output_table = output_table

    def process(self, batch, window=beam.DoFn.WindowParam):
        client = bigquery.Client(project=self.bigquery_project)
        
        table = client.get_table( \
            client.dataset(self.output_dataset).table(self.output_table))
        table_dlq = client.get_table( \
            client.dataset(self.output_dataset).table(self.output_table + "_dlq"))
        
        rows_to_insert = []
        rows_to_insert_dlq = []

        for element in batch:
            try:
                rows_to_insert.append(json.loads(json.dumps(record(element))))
            except:
                rows_to_insert_dlq.append(element)

        if len(rows_to_insert) > 0:
            client.insert_rows_json(table, rows_to_insert)
        
        
        if len(rows_to_insert_dlq) > 0:
            client.insert_rows_json(table_dlq, rows_to_insert_dlq)
        
def run(input_topic, bigquery_project,output_dataset,output_table, \
    window_size=1.0, pipeline_args=None):
    # `save_main_session` is set to true because some DoFn's rely on
    # globally imported modules.
    pipeline_options = PipelineOptions(
        pipeline_args, streaming=True, save_main_session=True
    )

    with beam.Pipeline(options=pipeline_options) as pipeline:
        (
            pipeline
            | "Read PubSub Messages"
            >> beam.io.ReadFromPubSub(topic=input_topic)
            | "Window into" >> GroupWindowsIntoBatches(window_size)
            | "Write to BigQuery" >> beam.ParDo(WriteBatchesToBigQuery( \
                bigquery_project,output_dataset,output_table))
        )


if __name__ == "__main__":  # noqa
    logging.getLogger().setLevel(logging.INFO)

    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--input_topic",
        help="The Cloud Pub/Sub topic to read from.\n"
        '"projects/<PROJECT_NAME>/topics/<TOPIC_NAME>".',
    )
    parser.add_argument(
        "--window_size",
        type=float,
        default=1.0,
        help="Output file's window size in number of minutes.",
    )
    parser.add_argument(
        "--output_dataset",
        help="BigQuery dataset name.",
    )
    parser.add_argument(
        "--output_table",
        help="BigQuery table name.",
    )
    parser.add_argument(
        "--bigquery_project",
        help="BigQuery project id.",
    )
    known_args, pipeline_args = parser.parse_known_args()

    run(
        known_args.input_topic,
        known_args.bigquery_project,
        known_args.output_dataset,
        known_args.output_table,
        known_args.window_size,
        pipeline_args,
    )
# [END pubsub_to_bigquery]
