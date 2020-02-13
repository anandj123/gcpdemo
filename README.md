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
(Create a dataset in your project if not already available](https://cloud.google.com/bigquery/docs/datasets)
### Create a bigquery table to hold the streaming data

### Create a GCS bucket for holding errors

### Instanstiate dataflow pipeline for streaming insert

### Create custom pipeline from templates

[Commands for custom pipeline template](./pubsubToBigquery-compile-run-commands.sh)


