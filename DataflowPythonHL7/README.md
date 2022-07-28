# Stream Cloud Pub/Sub with Cloud Dataflow

Please refer to [original documentation](https://github.com/GoogleCloudPlatform/python-docs-samples/tree/main/pubsub/streaming-analytics) for installation and configuration.

## Overview
The following python dataflow pipeline: 
* [PubSubToBigquery.py](PubSubToBigQuery.py) 

is for demonstrating how a complex python object can be stored in BigQuery using [Nested and Repeated fields](https://cloud.google.com/bigquery/docs/nested-repeated).

## Setup
1. Get the code from the current Github repo.

   ```sh
   git clone https://github.com/anandj123/gcpdemo.git
   ```
1. Navigate to the sample code directory.

   ```bash
   cd gcpdemo/DataflowPythonHL7 
   ```
1. Install the sample requirements.

  ```bash
  pip install -U -r requirements.txt
  ```

1. Setup environment variables for the following commands
   ```sh
   gcloud auth application-default login

   export PROJECT_ID=$(gcloud config get-value project)
   export BIGQUERY_PROJECT_ID=$(gcloud config get-value project)
   export TOPIC_ID=projects/anand-bq-test-2/topics/hl7
   export BUCKET_ID=gs://anand-bq-test-2/HCA_TEST/HL7  
   export DATASET_ID=hca_test
   export TABLE_ID=hl7pubsub
   ```

1. Install the [Nested and Repeated target tables].

   ```sh
   bq mk --table $PROJECT_ID:$DATASET_ID.$TABLE_ID bq_hl7pubsub_schema.json
   bq mk --table $PROJECT_ID:$DATASET_ID.${TABLE_ID}_dlq bq_hl7pubsub_dlq_schema.json
   ```

1. Create a topic as defined in $TOPIC_ID
   
   ```sh
   gcloud pubsub topics create projects/anand-bq-test-2/topics/hl7
   ```
1. The following example will run a streaming pipeline. It will read messages from a Pub/Sub topic, then window them into fixed-sized intervals, and write one file per window into a GCS location.

+ `--project`: sets the Google Cloud project ID to run the pipeline on
+ `--bigquery_project`: sets the Google Cloud project ID where the BigQuery Dataset for storing the data is located.
+ `--input_topic`: sets the input Pub/Sub topic to read messages from
+ `--output_dataset`: sets the output BigQuery dataset name to write data to.
+ `--output_table`: sets the output BigQuery table name to write data to.
+ `--runner`: specifies the runner to run the pipeline, if not set to `DataflowRunner`, `DirectRunner` is used
+ `--window_size [optional]`: specifies the window size in minutes, defaults to 1.0
+ `--temp_location`: needed for executing the pipeline

```bash
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
```

After the job has been submitted, you can check its status in the [GCP Console Dataflow page].

You can also check the output to your BigQuery console.

## Streaming Analytics

1. To test valid scenario publish a valid message to the pubsub queue.

   ```sh

   gcloud pubsub topics publish projects/anand-bq-test-2/topics/hl7 --message="MSH|^~\&|MT_COCQA1A|COCQA1A|DBM||201601190838||ADT^A02|MT_COCQA1A_ADT_QA1AGTADM.1.229576.567|D|2.1||KYA"

   gcloud pubsub topics publish projects/anand-bq-test-2/topics/hl7 --message="EVN|A02|201601190838|||1TSQBE8554^HAMMOCK^BRITTANY^JACK^WARREN^^"

   #Test to see if the bigquery has the data:
   bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.hca_test.hl7pubsub`'

   #Invalid test case
   gcloud pubsub topics publish projects/anand-bq-test-2/topics/hl7 --message="EVN"

   #Test to see if the bigquery DLQ (dead-letter queue) has the data:
   bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.hca_test.hl7pubsub_dlq`'

   ```


## Cleanup

1. Delete the [Google Cloud Dataflow] job.

    ```bash
    gcloud dataflow jobs list |grep Running 

    #copy the job_id of the running job that you want to cancel.
    gcloud dataflow jobs cancel <job_id>  
    ```

1. `Ctrl+C` to stop the program in your terminal. Note that this does not actually stop the job if you use `DataflowRunner`.

1.  If you use `DirectRunner`, you can skip this step. Stop the Dataflow job in [GCP Console Dataflow page]. Cancel the job instead of draining it. This may take some minutes.

1. Delete the topic. [Google Cloud Dataflow] will automatically delete the subscription associated with the streaming pipeline when the job is canceled.

   ```bash
   gcloud pubsub topics delete $TOPIC_ID
   ```

1. Lastly, to avoid incurring charges to your GCP account for the resources created in this tutorial:

    ```bash
    # Delete only the files created by this sample.
    gsutil -m rm -rf "gs://$BUCKET_NAME/samples/output*"

    # [optional] Remove the Cloud Storage bucket.
    gsutil rb gs://$BUCKET_NAME
    ```
1. Reference documents:

   |Reference|Documentation site|
   |------|-------|
   | Apache Beam | https://beam.apache.org/ |
   | Google Cloud Pub/Sub | https://cloud.google.com/pubsub/docs/ |
   | Google Cloud Dataflow | https://cloud.google.com/dataflow/docs/ |
   | Google Cloud Scheduler | https://cloud.google.com/scheduler/docs/ |
   | App Engine | https://cloud.google.com/appengine/docs/ |
   | Cloud SDK | https://cloud.google.com/sdk/docs/ |
   | Cloud Shell | https://console.cloud.google.com/cloudshell/editor/ |
   | *New Project* page | https://console.cloud.google.com/projectcreate |
   | Enable billing | https://cloud.google.com/billing/docs/how-to/modify-project/ |
   | *Create service account key* page | https://console.cloud.google.com/apis/credentials/serviceaccountkey/ |
   | GCP Console IAM page | https://console.cloud.google.com/iam-admin/iam/ |
   | Granting roles to service accounts | https://cloud.google.com/iam/docs/granting-roles-to-service-accounts/ |
   | Creating and managing service accounts | https://cloud.google.com/iam/docs/creating-managing-service-accounts/ |
   | Install Python and virtualenv | https://cloud.google.com/python/setup/ |
   | GCP Console create Dataflow job page | https://console.cloud.google.com/dataflow/createjob/ |
   | GCP Console Dataflow page | https://console.cloud.google.com/dataflow/ |
   | GCP Console Storage page | https://console.cloud.google.com/storage/ |
