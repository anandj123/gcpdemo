# Google cloud platform demo of data pipelines

## GCP demo for real time data pipeline using pubsub, dataflow templates and BigQuery

### Prerequisites

* GCP project is available
* GCP Cloud shell is enabled

### GCP VM setup
[Login to the cloud shell and follow these instruction to create a vm](https://cloud.google.com/compute/docs/instances/create-start-instance#startinstancegcloud)

### Login to created vm
gcloud compute ssh lab-1

### Login using user account for permission
gcloud auth login

### Create pubsub topic
gcloud pubsub topics list
gcloud pubsub topics create demo

### Create a dataset in bigquery
[Create a dataset in your project if not already available](https://cloud.google.com/bigquery/docs/datasets)

### Create a bigquery table to hold the streaming data
[Create a table to hold the streaming data](https://cloud.google.com/bigquery/docs/tables)

### Create a GCS bucket for holding errors
[Create a bucket to hold the errors](https://cloud.google.com/storage/docs/creating-buckets#storage-create-bucket-gsutil)

### Instanstiate dataflow pipeline for streaming insert
[Create streaming pipeline](https://cloud.google.com/dataflow/docs/guides/templates/provided-streaming#cloud-storage-text-to-bigquery-stream)

### Create custom pipeline from templates

[Commands for custom pipeline template](./pubsubToBigquery-compile-run-commands.sh)


