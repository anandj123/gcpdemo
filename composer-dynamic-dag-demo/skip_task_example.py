import airflow

from airflow import DAG
from airflow.operators.dummy_operator import DummyOperator
from airflow.operators.bash_operator import BashOperator
from airflow.operators.python_operator import PythonOperator
from airflow.contrib.operators.gcs_list_operator import GoogleCloudStorageListOperator
from airflow.models import Variable
from airflow.providers.google.cloud.transfers.gcs_to_gcs import GCSToGCSOperator
from airflow.operators.python_operator import BranchPythonOperator
from airflow.operators.python import get_current_context
import json
import logging
from airflow.providers.google.cloud.transfers.gcs_to_bigquery import GCSToBigQueryOperator

#from airflow.utils.task_group import TaskGroup
from airflow.utils.log.logging_mixin import LoggingMixin
from airflow.providers.google.cloud.operators.bigquery import BigQueryInsertJobOperator
import os
from datetime import datetime, timedelta
args = {
    'owner': 'airflow',
    'start_date': airflow.utils.dates.days_ago(2),
    'provide_context':True    
}
with DAG(dag_id='skip_tasks_example', catchup=False,default_args=args) as dag:
    current_task = 1

    def get_start_task(**kwargs):
        if kwargs['dag_run'] and kwargs['dag_run'].conf and kwargs['dag_run'].conf['start_from_task']:
            print("Remotely received value of {} for key=start_from_task.".
                format(kwargs['dag_run'].conf['start_from_task']))
            Variable.set(key='start_from_task',
                     value=int(kwargs['dag_run'].conf['start_from_task']))
        else:
            print("No parameters passed, starting from begining.")
            Variable.set(key='start_from_task',
                     value=1)

    d1 = PythonOperator(
        task_id='get_start_task',
        python_callable=get_start_task,provide_context=True,trigger_rule='none_failed')

    
    if current_task >= int(Variable.get(key='start_from_task')):
        # logging.critical("start_task_t1" + Variable.get(key='start_from_task'))
        load_csv = GCSToBigQueryOperator(
            task_id='gcs_to_bigquery_example',
            bucket='anand-bq-test-2-text',
            source_objects=['test*'],
            destination_project_dataset_table=f"hca_test.TextTable",
            schema_fields=[],
            write_disposition='WRITE_TRUNCATE',
        )
        d1 >> load_csv
        d1 = load_csv
    current_task += 1
    if current_task >= int(Variable.get(key='start_from_task')):
        # logging.critical("start_task_t2" + Variable.get(key='start_from_task'))
        call_stored_procedure = BigQueryInsertJobOperator(
            task_id="call_stored_procedure",
            configuration={
                "query": {
                    "query": "CALL `anand-bq-test-2.hca_test.demo_proc`(); ",
                    "useLegacySql": False,
                }
            },
        )
        d1 >> call_stored_procedure
        d1 = call_stored_procedure
    current_task += 1
    
    
    

    