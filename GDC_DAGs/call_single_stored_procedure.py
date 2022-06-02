from airflow.operators.bash_operator import BashOperator
from datetime import datetime
from airflow import models
from airflow.contrib.operators.bigquery_operator import BigQueryOperator
from airflow.models import Variable

with models.DAG(
      "call_bq_sp_static",
      schedule_interval=None,
      start_date=datetime(2021, 1, 1),
   ) as dag:

    job_start = BashOperator(
        task_id='job_started',
        bash_command='echo job started.'
    )
      
    call_bq_sp = BigQueryOperator(
        task_id="travel_policy1",
		  sql=Variable.get('dag_call_sp_bq'),
        use_legacy_sql=False,
    )
   
    job_end = BashOperator(
        task_id='job_completed',
        bash_command='echo job completed.'
    )

    job_start >> call_bq_sp >> job_end
