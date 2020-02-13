export GOOGLE_APPLICATION_CREDENTIALS=/mnt/chromeos/MyFiles/Downloads/anand-bq-test-2-4cda899168a4.json 

PROJECT_ID=anand-bq-test-2
BUCKET_NAME=anand-bq-test-2
PIPELINE_FOLDER=gs://${BUCKET_NAME}/dataflow/pipelines/pubsub-to-bigquery
USE_SUBSCRIPTION=false
RUNNER=DataflowRunner

mvn compile exec:java \
-Dexec.mainClass=com.google.cloud.teleport.templates.PubSubToBigQuery \
-Dexec.cleanupDaemonThreads=false \
-Dexec.args=" \
--project=${PROJECT_ID} \
--stagingLocation=${PIPELINE_FOLDER}/staging \
--tempLocation=${PIPELINE_FOLDER}/temp \
--templateLocation=${PIPELINE_FOLDER}/template \
--runner=${RUNNER} \
--useSubscription=${USE_SUBSCRIPTION}"

JOB_NAME=pubsub-to-bigquery-$USER-`date +"%Y%m%d-%H%M%S%z"`

 gcloud dataflow jobs run ${JOB_NAME} \
  --gcs-location=${PIPELINE_FOLDER}/template \
  --zone=us-east1-d \
  --parameters \
  "inputTopic=projects/${PROJECT_ID}/topics/demo,\
javascriptTextTransformFunctionName=transform,\
javascriptTextTransformGcsPath=gs://${PROJECT_ID}/dataflow/functions/test.js,\
outputTableSpec=${PROJECT_ID}:Anand_BQ_Test_1.demo_pubsub,\
outputDeadletterTable=${PROJECT_ID}:Anand_BQ_Test_1.demo_pubsub_error_records"

