# Google data catalog demo

First create a sink in Bigquery with the following filters to receive all schema change messages

Documentation for creating the sink is found at:
https://cloud.google.com/logging/docs/reference/tools/gcloud-logging

``` sh

gcloud pubsub topics create datacatalog-sink-topic

gcloud logging sinks create datacatalog-sink pubsub.googleapis.com/projects/anand-bq-test-2/topics/datacatalog-sink-topic --log-filter='resource.type="bigquery_resource" (protoPayload.methodName="tableservice.insert" OR protoPayload.methodName="tableservice.update")'

gcloud pubsub topics add-iam-policy-binding datacatalog-sink-topic --member serviceAccount:p701417641712-341816@gcp-sa-logging.iam.gserviceaccount.com --role roles/pubsub.publisher

gcloud logging sinks list

gcloud logging sinks describe datacatalog-sink

```
Once the messages are flowing to pubsub topic you can trigger a cloud function to do additional processing on it.

https://cloud.google.com/functions/docs/calling/pubsub



