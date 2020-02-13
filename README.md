# Google cloud platform demo of data pipelines

## GCP demo for real time data pipeline using pubsub, dataflow templates and BigQuery

### Prerequisites

* GCP project is available
* GCP Cloud shell is enabled
### GCP VM setup
Login to the cloud shell and follow these instruction to create a vm
https://cloud.google.com/compute/docs/instances/create-start-instance#startinstancegcloud

### Login to created vm
gcloud compute ssh lab-1

### Login using user account for permission
gcloud auth login

### Create pubsub topic
gcloud pubsub topics list
gcloud pubsub topics create demo

### create a dataset in bigquery

### create a bigquery table to hold the streaming data

### create a GCS bucket for holding errors

### instanstiate dataflow pipeline for streaming insert

### Create custom pipeline from templates

(Commands for custom pipeline template) [pubsubToBigquery-compile-run-commands.sh]


