import os, sys, getopt
import logging
import os
from google.cloud import storage

# use service account
#export GOOGLE_APPLICATION_CREDENTIALS="/home/user/Downloads/[FILE_NAME].json"
def read_file(filename):
    print('Reading the full file contents:\n')
    # Instantiates a client
    storage_client = storage.Client()

    bucket = storage_client.get_bucket('anand-bq-test-2')

    for blob in bucket.list_blobs(prefix='dataflow/functions/'):
        print(str(blob))


    blob = storage.Blob('dataflow/functions/test.js', bucket)
    with open('./test.js', 'w') as file_obj:
        file_obj.write(blob.download_as_string())
        file_obj.close()
        

    

def main(argv):
   inputfile = ''
   outputfile = ''
   try:
      opts, args = getopt.getopt(argv,"hi:",["ifile="])
   except getopt.GetoptError:
      print 'deploy.py -i <inputfile> '
      sys.exit(2)
   for opt, arg in opts:
      if opt == '-h':
         print 'deploy.py -i <inputfile> '
         sys.exit()
      elif opt in ("-i", "--ifile"):
         inputfile = arg
      
   print 'Input file is :', inputfile
   read_file(inputfile)

def create_bq_table():   
    with open('create_table.sql', 'r') as f:
        sql = f.read()
        os.system("bq query --nouse_legacy_sql '" + sql + "'")

if __name__ == "__main__":
   main(sys.argv[1:])
