# Google cloud platform demo of data pipelines

## GCP demo for real time data pipeline using pubsub, dataflow templates and BigQuery

### Prerequisites

* GCP project is available
* GCP Cloud shell is enabled
* Week 1 is done

### Configuring Cloud KMS
[Cloud KMS quickstart](https://cloud.google.com/kms/docs/quickstart)

```sh
gcloud kms keyrings create test --location global

gcloud kms keys create quickstart --location global \
  --keyring test \
  --purpose encryption

gcloud kms keys list \
  --location global \
  --keyring test  
gcloud kms encrypt --location global \
  --keyring demo-keyring --key demo-key1 \
  --plaintext-file mysecret.txt \
  --ciphertext-file mysecret.txt.encrypted

gcloud kms decrypt --location global \
  --keyring demo-keyring --key demo-key1 \
  --plaintext-file mysecret.txt.decrypted \
  --ciphertext-file mysecret.txt.encrypted

gcloud kms keys versions list --location global \
  --keyring demo-keyring --key demo-key1  
```

### Service account setup for Dataflow for reading from pubsub and writing to Bigquery

### Configuring message encryption pubsub CMEK setup

[Configuring message encryption for pubsub](https://cloud.google.com/pubsub/docs/encryption)

```sh
gcloud pubsub topics describe demo

```

### Pubsub restricting resource locations
[Configuring resource location for pubsub](https://cloud.google.com/pubsub/docs/resource-location-restriction)

### GCS CMEK setup


### Bigquery CMEK setup

### Bigquery client project setup for accessing central dataset repository

### Bigquery authorized views setup (row and column level access control)

### Overview of Cloud DLP
[Using DLP action to scan a Bigquery table](https://cloud.google.com/dlp/docs/concepts-actions)

[Redacting using Cloud DLP REST API](https://cloud.google.com/dlp/docs/redacting-sensitive-data)


```sh
export PROJECT_ID=anand-bq-test-2
export GOOGLE_APPLICATION_CREDENTIALS=/mnt/chromeos/MyFiles/Downloads/anand-bq-test-2-4cda899168a4.json 

gcloud auth activate-service-account --key-file /mnt/chromeos/MyFiles/Downloads/anand-bq-test-2-4cda899168a4.json 

gcloud auth print-access-token

gcloud auth list
gcloud config list

curl -s -H "Authorization: Bearer ya29.c.KpQBvwcb6jHyS3V5l8K2Idmu48H99ztTE_bkhvls5uSmkjVgN0TteMoRlDwIy6LK85G6iZwgiz0pxtNVqIaoy_4MlMjS-iMSJDAQ5UL6SqLbxit-c5rK1ndQK0jQoiXpFQrTrRg-b6XF4ZmCSjd7zk6oNn7PE6uIVrEgY7cMykKchl7vwyjkrhSt_C58G0n3obPR9Y4orw" -H "Content-Type: application/json" https://dlp.googleapis.com/v2/projects/$PROJECT_ID/content:deidentify -d @redact-input.json


curl -s -H 'Content-Type: application/json' \
  -H 'Authorization: Bearer ya29.c.KpQBvwcb6jHyS3V5l8K2Idmu48H99ztTE_bkhvls5uSmkjVgN0TteMoRlDwIy6LK85G6iZwgiz0pxtNVqIaoy_4MlMjS-iMSJDAQ5UL6SqLbxit-c5rK1ndQK0jQoiXpFQrTrRg-b6XF4ZmCSjd7zk6oNn7PE6uIVrEgY7cMykKchl7vwyjkrhSt_C58G0n3obPR9Y4orw' \
  'https://dlp.googleapis.com/v2/infoTypes'


```
   