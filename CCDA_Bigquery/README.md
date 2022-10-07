# Overview
This is WIP project that uses blue-button module to ingest CCDA files into BigQuery.

# Setup instructions
1. Install latest version of node.js
2. Install latest version of google-cloud-storage
    - python3 -m pip install google-cloud-storage
3. Install blue-button
    - npm i bluebutton

# Google Cloud setup
Create a GCS folder and copy your example CCDA file to that folder.
A sample [CCDA sample is found at](CCDA_QA_PROCEDURES_SAMPLE.xml)

Upload the above sample to the corrosponding GCS folder.

Update the following variable to appropriate values:
```python

project_id = 'anand-bq-test-2'
data_set_id = 'hca_clinical'
table_id = 'hca_ccda_sample_table'
bucket_name = 'anand-bq-test-2'
folder_name = 'HCA_TEST/Clinical/HCA/'

```

# Run sample
To run the sample use the following command

```sh
python3 ccda_bluebutton.py
```

The output of the command if successful should like the following:

```sh
CCDA Documents processing :
Processing CCDA XML file HCA_TEST/Clinical/HCA/CCDA_QA_Procedures_Sample.xml
dea15f6f-ed75-4133-b2c3-7ee86523b39b
Total CCDA files processed: 1
```