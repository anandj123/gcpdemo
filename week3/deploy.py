import os, sys, getopt
import logging
import os,json
from google.cloud import storage

# Global variables
bq_schema_file = ''
pubsub_topic = ''
job_name = ''
udf_location = ''
udf_file_name = ''
pipeline_folder = ''
project_id = ''
deploy_bucket = ''
bq_table_name = ''
working_folder = ''
# use service account
#export GOOGLE_APPLICATION_CREDENTIALS="/home/user/Downloads/[FILE_NAME].json"

def main(argv):
    inputfile = ''
    outputfile = ''
    try:
        opts, args = getopt.getopt(argv,"hi:",["ifile="])
    except getopt.GetoptError:
        print('deploy.py -i <inputfile>')
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print('deploy.py -i <inputfile> ')
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
    print('\nInput file is :' + inputfile)
    print('-------------------------------------------------------------------')
    read_file(inputfile)

def read_file(filename):
    global bq_schema_file, pubsub_topic, job_name, udf_file_name
    global pipeline_folder,project_id,deploy_bucket,udf_location
    global bq_table_name, working_folder
    
    # Instantiates a client
    storage_client = storage.Client()
    bucket_name = filename.replace('gs://','').split('/')[0]
    bucket = storage_client.get_bucket(bucket_name)

    config_folder_name = filename.replace('gs://','').replace(bucket_name,'')[1:]
    #print("bucket = " + bucket_name + ' config folder name = ' + config_folder_name)
    for blob in bucket.list_blobs(prefix=config_folder_name):
        
        #print('blob name = ' + blob.name)
        arr = str(blob.name).split('/')
        file_name = arr[len(arr)-1].replace('>','')
        if file_name > '':
            print("Dowloading file = " + file_name)
            file_blob = storage.Blob(blob.name, bucket)
            with open(file_name, 'w') as file_obj:
                file_obj.write(file_blob.download_as_string())
                file_obj.close()
    # Load global variables for the configurations
    with open('./config.json') as f:
        system_json = json.load(f)
        
        bq_schema_file = system_json['user_config']['bq_schema_file']
        pubsub_topic = system_json['user_config']['pubsub_topic']
        job_name = system_json['user_config']['job_name']
        udf_file_name = system_json['user_config']['udf_file_name']
        pipeline_folder = system_json['system_config']['pipeline_folder']
        project_id = system_json['system_config']['project_id']
        deploy_bucket = system_json['system_config']['deploy_bucket']
        udf_location = system_json['system_config']['udf_location']
        bq_table_name = system_json['user_config']['bq_table_name']

def create_dataflow_job():

    #PROJECT_ID=anand-bq-test-2
    #BUCKET_NAME=anand-bq-test-2
    #PIPELINE_FOLDER=gs://${BUCKET_NAME}/dataflow/pipelines/pubsub-to-bigquery
    #USE_SUBSCRIPTION=false
    #RUNNER=DataflowRunner
    #JOB_NAME=pubsub-to-bigquery-$USER-`date +"%Y%m%d-%H%M%S%z"`

    print('\nCreating dataflow job = ' + job_name)
    print('-------------------------------------------------------------------')
    dataflow_command = 'gcloud dataflow jobs run ' + job_name + ' --gcs-location=gs://' + \
                        pipeline_folder + ' --zone=us-east1-d   --parameters   ' +  \
                        '"inputTopic=projects/' + project_id + '/topics/' + pubsub_topic + \
                        ',javascriptTextTransformFunctionName=transform,' + \
                        'javascriptTextTransformGcsPath=gs://' + deploy_bucket + '/' + \
                        udf_location + '/' + udf_file_name + \
                        ',outputTableSpec=' + bq_table_name + \
                        ',outputDeadletterTable=' + bq_table_name + '_error_records"'
    os.system(dataflow_command)

def upload_udf():
    upload_to = 'gs://' + deploy_bucket + '/' + udf_location + '/' + udf_file_name
    print('\nUploading UDF from = ' + udf_file_name + ' = ' + upload_to)
    print('-------------------------------------------------------------------')
    os.system('gsutil cp ' + udf_file_name + ' ' + upload_to)
def create_pubsub_topic():
    print('\nCreating pubsub topic = ' + pubsub_topic)
    print('-------------------------------------------------------------------')
    os.system("gcloud pubsub topics create " + pubsub_topic)

def create_bq_table(): 
    print('\nCreating Bigquery table from schema file = ' + bq_schema_file)
    print('-------------------------------------------------------------------')
    with open(bq_schema_file, 'r') as f:
        sql = f.read()
        os.system("bq query --nouse_legacy_sql '" + sql + "'")


if __name__ == "__main__":
   main(sys.argv[1:])
   create_bq_table()
   create_pubsub_topic()
   upload_udf()
   create_dataflow_job()
