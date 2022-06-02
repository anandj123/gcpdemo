from datetime import datetime
from airflow import models
from google.cloud import storage
import logging
from airflow.operators.bash_operator import BashOperator
from airflow.contrib.operators.bigquery_operator import BigQueryOperator
from airflow.models import Variable
            
with models.DAG(
    "call_bq_sql_dynamic",
    schedule_interval=None,
	 template_searchpath='/home/airflow/gcs/data/',
    start_date=datetime(2021, 1, 1),
	 ) as dag:
      
    job_start = BashOperator(
        task_id='job_started',
        bash_command='echo job started.'
    )  
      
    call_bq_sql = BigQueryOperator(
        task_id="call_bq_sql",
		  sql=Variable.get('dag_sql_file_name1'),
        use_legacy_sql=False,
    )
   
    job_end = BashOperator(
        task_id='job_completed',
        bash_command='echo job completed.'
    )
   
    job_start >> call_bq_sql >> job_end
