# Steps to load ob data to Bigquery

## First download and load the file to GCS 
```sh
gsutil cp GoogleOBData.txt gs://anand-bq-test-2/HCA_TEST/Clinical/OBData/
```
## Run bq load command to load the file to BigQuery

```sh
bq load --autodetect --source_format=CSV hca_clinical.ob_data "gs://anand-bq-test-2/HCA_TEST/Clinical/OBData/*.txt"
```

## How to get BigQuery Job information

```sh
bq show --format=prettyjson --job=true anand-bq-test-2:US.bquxjob_6bdf513c_183c8028f65 > bqjobs.json
```