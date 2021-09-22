# Google cloud platform demo of data pipelines

## GCP demo for Bigquery ELT pipeline

### Nested and Repeated field demo

``` sh
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

# Query the table for records
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.cust`'
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.items`'
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.ord_dtl`'
bq query --nouse_legacy_sql 'select * from `anand-bq-test-2.bbby_data.ord_hdr`'

# Cleanup
bq rm -f -t anand-bq-test-2:bbby_data.cust
bq rm -f -t anand-bq-test-2:bbby_data.items
bq rm -f -t anand-bq-test-2:bbby_data.ord_hdr
bq rm -f -t anand-bq-test-2:bbby_data.ord_dtl



```
