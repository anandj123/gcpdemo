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
bq query --use_legacy_sql=false --parameter=run_time::2020-04-02T00:00:00Z 'SELECT @run_time AS time, title, author, text FROM `bigquery-public-data.hacker_news.stories` LIMIT 3'
```

### Notes on configuring composer

[Setting up Cloud composer](https://cloud.google.com/composer/docs/how-to/managing/creating#configuring_sendgrid_email_services)

``` sh
gcloud auth print-access-token

gcloud composer environments list --locations=us-east1

gcloud composer environments run composer1 --location=us-east1 list_dags

gcloud composer environments run composer1 --location=us-east1 variables -- --set gcp_bucket gs://anand-bq-test-2-2/

gcloud composer environments describe composer1 --location=us-east1

gsutil ls gs://us-east1-composer1-dec892c4-bucket/dags

gsutil cp bqml_demo.py gs://us-east1-composer1-dec892c4-bucket/dags

```
### Integrating Bigquery jobs with enterprise schedulers 

```sh
./run_bq_test.sh gs://anand-bq-test-2-2/bqdemo
```

