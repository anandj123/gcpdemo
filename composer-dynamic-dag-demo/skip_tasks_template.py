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

#from airflow.utils.task_group import TaskGroup
from airflow.utils.log.logging_mixin import LoggingMixin

import os
from datetime import datetime, timedelta
args = {
    'owner': 'airflow',
    'start_date': airflow.utils.dates.days_ago(2),
    'provide_context':True    
}
with DAG(dag_id='skip_tasks_template', catchup=False,default_args=args) as dag:
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
        t1=DummyOperator(task_id='task_1',trigger_rule='none_failed')
        d1 >> t1
        d1 = t1
    current_task += 1
    if current_task >= int(Variable.get(key='start_from_task')):
        # logging.critical("start_task_t2" + Variable.get(key='start_from_task'))
        t2=DummyOperator(task_id='task_2',trigger_rule='none_failed')
        d1 >> t2
        d1 = t2
    current_task += 1
    if current_task >= int(Variable.get(key='start_from_task')):
        # logging.critical("start_task_t3" + Variable.get(key='start_from_task'))
        t3=DummyOperator(task_id='task_3',trigger_rule='none_failed')
        d1 >> t3
        d1 = t3
    current_task += 1
    if current_task >= int(Variable.get(key='start_from_task')):
        # logging.critical("start_task_t4" + Variable.get(key='start_from_task'))
        t4=DummyOperator(task_id='task_4',trigger_rule='none_failed')
        d1 >> t4
        d1 = t4
    
    

    