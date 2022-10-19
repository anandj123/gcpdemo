# Steps to load ob data to Bigquery

## First download and load the file to GCS 
```sh
gsutil cp GoogleOBData.txt gs://anand-bq-test-2/HCA_TEST/Clinical/OBData/
```
## Run bq load command to load the file to BigQuery

```sh
bq load --autodetect --source_format=CSV hca_clinical.ob_data gs://anand-bq-test-2/HCA_TEST/Clinical/OBData/*
```
