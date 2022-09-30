import subprocess
from google.cloud import bigquery
import io
import json
import re

from google.cloud import storage

# Install latest version of google-cloud-storage
# python3 -m pip install google-cloud-storage     

# Initialise a client
storage_client = storage.Client("anand-bq-test-2")
# Create a bucket object for our bucket
bucket = storage_client.get_bucket("anand-bq-test-2")
# Create a blob object from the filepath
#blob = bucket.blob("HCA_TEST/Clinical/*.xml")
# Download the file to a destination
#blob.download_to_filename(destination_file_name)
delimiter=None
all_blobs = bucket.list_blobs(prefix="HCA_TEST/Clinical/HCA/",delimiter=delimiter)

# Note: The call returns a response only when the iterator is consumed.

bigquery_client = bigquery.Client(project='anand-bq-test-2')
dataset_id = "hca_clinical"
dataset_ref = bigquery_client.dataset(dataset_id)
table_ref = dataset_ref.table('clinical_3')
table = bigquery_client.get_table(table_ref)  # API call
job_config = bigquery.LoadJobConfig()
job_config.source_format = bigquery.SourceFormat.NEWLINE_DELIMITED_JSON


print("CCDA Documents processing :")
for blob in all_blobs:
    
    if blob.name.endswith('.xml'):
        print("Processing CCDA XML file",blob.name)
        destination_uri = "{}/{}".format('.', "current.xml") 
        blob.download_to_filename(destination_uri)

        path_to_file = 'current.xml'
        # if node isn't on your path, the first arg should instead be a path to the node bin
        cmd_list = ['node', 'hca_test.js', path_to_file]

        p = subprocess.Popen(cmd_list, stdout=subprocess.PIPE,
            stdin=subprocess.PIPE, stderr=subprocess.PIPE)
        result, error = p.communicate()
        p.stdin.close()

        if p.returncode != 0:
            print(error)
            raise ValueError("Failed to parse clinical XML at %s" % \
                path_to_file)

        result = result.decode('utf-8').replace("\n","")

        stringio_data = io.StringIO(result)

        load_job = bigquery_client.load_table_from_file(stringio_data, table, job_config = job_config)
        print(load_job.job_id)
QUERY = ("SELECT * FROM `anand-bq-test-2.hca_clinical.clinical_3` ")
query_job = bigquery_client.query(QUERY)  
rows = query_job.result()  
print("Total CCDA files processed:", rows.total_rows)

#return result