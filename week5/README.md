# Google cloud platform demo of data pipelines

## GCP demo for real time data pipeline using pubsub, dataflow templates and BigQuery

### Prerequisites

* GCP project is available
* GCP Cloud shell is enabled
* Week 4 is done

### Bigquery ML demo
[Working with Bigquery ML](https://cloud.google.com/bigquery-ml/docs/bigqueryml-web-ui-start)

### Schedule a Bigquery query for run

[Schedule Bigquery query](https://cloud.google.com/bigquery/docs/scheduling-queries)

```sh
To use a parameterized query use the following syntax:

bq query --use_legacy_sql=false --parameter=run_time::2020-04-02T00:00:00Z 'SELECT @run_time AS time, title, author, text FROM `bigquery-public-data.hacker_news.stories` LIMIT 3'

For the demo we will use the following query:

bq mk  --transfer_config  --target_dataset=Anand_BQ_Test_1 --display_name='schedule2' --params='{"query":"SELECT current_datetime()","destination_table_name_template":"schedule1","write_disposition":"WRITE_APPEND"}' --data_source=scheduled_query

To show list of scheduled query:

bq ls --transfer_config --transfer_location=us

To show the configuration of the scheduled query:

bq show --transfer_config projects/701417641712/locations/us/transferConfigs/5e885f7b-0000-2885-9364-f4f5e8079c6c

To make the query run for historical date:

bq mk --transfer_run  --start_time='2020-04-06T00:00:00.000000Z'  --end_time='2020-04-06T00:00:00.000000Z'  projects/701417641712/locations/us/transferConfigs/5e885f7b-0000-2885-9364-f4f5e8079c6c

```

### Notes on configuring composer

[Setting up Cloud composer](https://cloud.google.com/composer/docs/how-to/managing/creating#configuring_sendgrid_email_services)

``` sh
gcloud auth print-access-token

gcloud composer environments list --locations=us-east1

gcloud composer environments run composer1 --location=us-east1 list_dags

gcloud composer environments run composer1 --location=us-east1 variables -- --set gcp_bucket gs://anand-bq-test-2-2/

To describe the composer environment (especially dagGcsPrefix)
gcloud composer environments describe composer1 --location=us-east1

gsutil ls gs://us-east1-composer1-dec892c4-bucket/dags

gsutil cp bqml_demo.py gs://us-east1-composer1-dec892c4-bucket/dags

```
### Integrating Bigquery jobs with enterprise schedulers 

```sh
To run all the query files uploaded to a bucket use the following shell script:

./run_bq_test.sh gs://anand-bq-test-2-2/bqdemo

```

