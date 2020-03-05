# Google cloud platform demo of data pipelines

## GCP demo for real time data pipeline using pubsub, dataflow templates and BigQuery

### Prerequisites

* GCP project is available
* GCP Cloud shell is enabled
* Week 1 is done
* Week 2 is done
* Week 3 is done

### Create a view dataset for provisioning Bigquery data for user consumption.
https://cloud.google.com/bigquery/docs/views

### Create an authorized view of data provisioning.
https://cloud.google.com/bigquery/docs/authorized-views

### Creating partitioned tables
https://cloud.google.com/bigquery/docs/partitioned-tables

### Creating clustered tables
https://cloud.google.com/bigquery/docs/clustered-tables

### Bigquery cost optimization
https://cloud.google.com/bigquery/docs/best-practices-costs

### Bigquery BI Engine
https://cloud.google.com/bi-engine/docs/getting-started-data-studio

### Bigquery reservation API
https://cloud.google.com/bigquery/docs/reservations-workload-management

### Overview of the Bigquery monitoring and logging tools.
https://cloud.google.com/bigquery/docs/monitoring

### Create stackdriver export for Bigquery logging.
https://cloud.google.com/logging/docs/export/aggregated_exports

### Overview of the org wide monitoring tool.
https://github.com/meganzhao/professional-services/tree/org-wide-bq-job-top/examples/bigquery-org-wide-running-jobs

### Overview of bigquery tagging
https://github.com/anandj123/professional-services/tree/bigquery-tagging/tools/bigquery-tagging

```sql
SELECT 
  t0.project_id, 
  t0.totalBilledBytes, 
  t0.totalProcessedBytes, 
  t0.totalSlotMs,
  t0.hash_code,
  t0.jobId
FROM (SELECT 
      resource.labels.project_id,
      protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobStatistics.totalBilledBytes,
      protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobStatistics.totalSlotMs,
      protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobStatistics.totalProcessedBytes, 
      protopayload_auditlog.authenticationInfo.principalEmail,
      protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobStatistics.createTime, 
      protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobStatistics.startTime,
      protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobStatistics.endTime,
      a.timestamp, 
      protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobStatus.state , 
      protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobName.jobId,  
      protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobConfiguration.query.query, 
      cast(b.hash   as STRING) hash_code
FROM `anand-bq-test-2.Anand_BQ_Test_1.cloudaudit_googleapis_com_data_access_*` a
inner join `anand-bq-test-2.Anand_BQ_Test_1.query_tag` b
ON protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobName.jobId = b.job_id 
where protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobStatus.state = 'DONE'
AND protopayload_auditlog.servicedata_v1_bigquery.jobGetQueryResultsResponse.job.jobStatistics.totalBilledBytes is not null) AS t0; 

```
### Bigquery utilities
https://github.com/GoogleCloudPlatform/bigquery-utils


### Monitoring slot usage in Bigquery
[Practical approach to slot usage in Bigquery](https://cloud.google.com/blog/products/data-analytics/monitoring-resource-usage-in-a-cloud-data-warehouse)

```sql
SELECT
COUNT(*) TOTAL_QUERIES,     
SUM(total_slot_ms/TIMESTAMP_DIFF(end_time,creation_time,MILLISECOND)) AVG_SLOT_USAGE,
SUM(TIMESTAMP_DIFF(end_time,creation_time,SECOND)) TOTAL_DURATION_IN_SECONDS,
AVG(TIMESTAMP_DIFF(end_time,creation_time,SECOND)) AVG_DURATION_IN_SECONDS,
SUM(total_bytes_processed*10e-12) TOTAL_PROCESSED_TB,
EXTRACT (DATE FROM creation_time) AS EXECUTION_DATE,
user_email as USER
FROM `anand-bq-test-2.region-us.INFORMATION_SCHEMA.JOBS_BY_PROJECT`
WHERE state='DONE'
AND statement_type='SELECT'
AND creation_time BETWEEN TIMESTAMP_SUB(CURRENT_TIMESTAMP(), INTERVAL 30 DAY) AND CURRENT_TIMESTAMP()
GROUP BY EXECUTION_DATE, USER
ORDER BY EXECUTION_DATE,AVG_SLOT_USAGE
```
### Bigquery INFORMATION_SCHEMA
https://cloud.google.com/bigquery/docs/information-schema-intro



