# Google cloud platform demo of data pipelines

## GCP demo for Bigquery ELT pipeline for nested and repeated fields 

#### For ingestion layer design upload the files to GCS (gzip) and create external tables
* gzip txt files to upload to GCS
* gunzip txt files to upload to GCS
* upload files to GCS
* create definition json for external tables (could be automated to generate those)
* edit definition files to take care of header rows
* create external tables

``` sh
gzip *.txt

gunzip *.txt.gz

#upload gzip files to gcs
gsutil cp *.gz gs://anand-bq-test-2/data/bbby-data

# Create a definition json for the external table
bq mkdef --autodetect --source_format="CSV" "gs://anand-bq-test-2/data/bbby-data/cust.txt" > cust.json
bq mkdef --autodetect --source_format="CSV" "gs://anand-bq-test-2/data/bbby-data/items.txt" > items.json
bq mkdef --autodetect --source_format="CSV" "gs://anand-bq-test-2/data/bbby-data/ord_dtl.txt" > ord_dtl.json
bq mkdef --autodetect --source_format="CSV" "gs://anand-bq-test-2/data/bbby-data/ord_hdr.txt" > ord_hdr.json

# Edit the definition to add other configurations like "skipLeadingRows": 1

# Run the following command to create the external table
bq mk --external_table_definition=cust.json anand-bq-test-2:bbby_data.cust 
bq mk --external_table_definition=items.json anand-bq-test-2:bbby_data.items 
bq mk --external_table_definition=ord_dtl.json anand-bq-test-2:bbby_data.ord_dtl 
bq mk --external_table_definition=ord_hdr.json anand-bq-test-2:bbby_data.ord_hdr 

# Show the table definition of the table that got created
bq show --format=prettyjson anand-bq-test-2:bbby_data.cust
bq show --format=prettyjson anand-bq-test-2:bbby_data.items
bq show --format=prettyjson anand-bq-test-2:bbby_data.ord_dtl
bq show --format=prettyjson anand-bq-test-2:bbby_data.ord_hdr
bq show --format=prettyjson anand-bq-test-2:bbby_data.orders

# Query the table for records
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.cust`'
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.items`'
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.ord_dtl`'
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.ord_hdr`'

``` 

### For creating ELT pipeline 
* Create the table with nested and repeated field 
* Execute the script that creates the stored procedure

```sh
bq mk --table --schema=orders.json anand-bq-test-2:bbby_data.orders      

bq query --nouse_legacy_sql < PopulateOrdersOperationLayer.sql

# Test stored procedure to populate the operational layer table orders
bq query --nouse_legacy_sql 'call `anand-bq-test-2.bbby_data.PopulateOrdersOperationLayer`()'

# Check if the table got populated by the test stored procedure run
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.orders`'

```

### Create authorized views to query the data
```sh
bq query --nouse_legacy_sql < orders_auth_view.sql

bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_views.orders_auth_view`'
```

### Create materialized view for analytics layer

```sh
bq query --nouse_legacy_sql < orders_material_view.sql

bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_views.orders_material_view`'

# For granting access to materialized views follow the documentation
https://cloud.google.com/bigquery/docs/share-access-views#python
```

### Deploy a DAG to trigger the ELT pipeline PopulateOrdersOperationLayer through Cloud Composer

```sh

# Deploy the dag to Cloud Composer environment
gsutil cp start_merge_orders_job.py gs://us-east1-test1-1027d9be-bucket/dags

# Test if DAG got copied
gsutil ls gs://us-east1-test1-1027d9be-bucket/dags

# Test DAG got deployed to Cloud Composer
gcloud composer environments list --locations=us-east1

# List all DAGS that are deployed in the specied environment
gcloud composer environments storage dags list --environment=projects/anand-bq-test-2/locations/us-east1/environments/test1

# Testing purposes truncate the orders table to see if the table is getting populated by the stored proc.
bq query --nouse_legacy_sql 'truncate table `anand-bq-test-2.bbby_data.orders`'

# Trigger the Composer DAG
gcloud composer environments run projects/anand-bq-test-2/locations/us-east1/environments/test1 trigger_dag -- start_merge_orders_job

# Check if the table got populated by the test stored procedure run
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.orders`'
```

### Clean up if need to run again

```sh

bq rm -f -t anand-bq-test-2:bbby_data.cust
bq rm -f -t anand-bq-test-2:bbby_data.items
bq rm -f -t anand-bq-test-2:bbby_data.ord_hdr
bq rm -f -t anand-bq-test-2:bbby_data.ord_dtl
bq rm -f -t anand-bq-test-2:bbby_data.orders
bq rm -f -t anand-bq-test-2:bbby_views.orders_auth_view
bq rm -f -t anand-bq-test-2:bbby_views.orders_material_view
gsutil rm gs://us-east1-test1-1027d9be-bucket/dags/start_merge_orders_job.py

```

