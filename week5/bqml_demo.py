# Copyright 2018 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""Example Airflow DAG that creates a BigQuery dataset, populates the dataset
by performing a queries for recent popular StackOverflow questions against the
public dataset `bigquery-public-data.stackoverflow.posts_questions`. The DAG
exports the results of the query as a CSV to Cloud Storage, and sends an email
with path to the CSV file and the title and view count of the most popular
question. Lastly, the DAG cleans up the BigQuery dataset.

This DAG relies on three Airflow variables
https://airflow.apache.org/concepts.html#variables
* gcp_project - Google Cloud Project to use for BigQuery.
* gcs_bucket - Google Cloud Storage bucket to use for result CSV file.
  See https://cloud.google.com/storage/docs/creating-buckets for creating a
  bucket.
* email - The email used to receive DAG updates.
"""

import datetime

# [START composer_notify_failure]
from airflow import models
# [END composer_notify_failure]
from airflow.contrib.operators import bigquery_get_data
# [START composer_bigquery]
from airflow.contrib.operators import bigquery_operator
# [END composer_bigquery]
from airflow.contrib.operators import bigquery_to_gcs
# [START composer_bash_bq]
from airflow.operators import bash_operator
# [END composer_bash_bq]
# [START composer_email]
from airflow.operators import email_operator
# [END composer_email]
from airflow.utils import trigger_rule






yesterday = datetime.datetime.combine(
    datetime.datetime.today() - datetime.timedelta(1),
    datetime.datetime.min.time())

# [START composer_notify_failure]
default_dag_args = {
    'start_date': yesterday,
    'retries': 1,
    'retry_delay': datetime.timedelta(minutes=5),
    'project_id': models.Variable.get('gcp_project')
}

with models.DAG(
        'bqml_demo_composer',
        schedule_interval=datetime.timedelta(weeks=4),
        default_args=default_dag_args) as dag:
    # [END composer_notify_failure]

    
    # Create BQML Model
    create_bqml_model = bash_operator.BashOperator(
        task_id='create_bqml_model',
        bash_command='bq query "$(gsutil cat gs://anand-bq-test-2-2/bqdemo/query2.txt)"',
        trigger_rule=trigger_rule.TriggerRule.ALL_DONE)
    


    # Define DAG dependencies.
    (
        create_bqml_model
    )
    
