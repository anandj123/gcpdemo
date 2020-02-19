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

### Overview of Cloud KMS

### Overview of Cloud DLP

