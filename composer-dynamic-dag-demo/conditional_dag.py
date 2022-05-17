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

import os
from datetime import datetime, timedelta
args = {
    'owner': 'airflow',
    'start_date': airflow.utils.dates.days_ago(2),
    'provide_context':True    
}
with DAG(dag_id='conditional_dag', catchup=False,default_args=args) as dag:
    total_tasks = 3
    #print ("Current task is: " + get_current_context()['dag_run'].conf['start_from_task'])
    
    # Variable.set(key='start_from_task', 
    #             value=2)
    
    
    #d1 = DummyOperator(task_id='kick_off_conditional_dag')
    conf = " {{ dag_run.conf }} "
    logging.info("got parameter:" + str(conf))

    def get_tasks(**kwargs):
        tasks = []
        start_from_task = 1
        if kwargs['dag_run'] and kwargs['dag_run'].conf and kwargs['dag_run'].conf['start_from_task']:
            print("Remotely received value of {} for key=start_from_task.".
                format(kwargs['dag_run'].conf['start_from_task']))
            start_from_task = int(kwargs['dag_run'].conf['start_from_task'])
        else:
            print("No parameters passed, starting from begining.")
        #start_from_task = int(Variable.get(key='start_from_task'))
        for entry in range(1,total_tasks+1):
            if entry >= start_from_task:
                tasks.append("task_" + str(entry) )
        return tasks   

    # def get_tasks_start(**kwargs):
        
    #     if kwargs['dag_run'] and kwargs['dag_run'].conf and kwargs['dag_run'].conf['start_from_task']:
    #         print("Remotely received value of {} for key=start_from_task.".
    #             format(kwargs['dag_run'].conf['start_from_task']))
    #         Variable.set(key='start_from_task', 
    #             value=int(kwargs['dag_run'].conf['start_from_task']))
    #     else:
    #         print("No parameters passed, starting from begining.")
    #         Variable.set(key='start_from_task', 
    #             value=1)
           
    #fork = PythonOperator(
    #    task_id='Get_tasks_to_perform',
    #    python_callable=get_tasks_start,provide_context=True)
    
    fork1 = BranchPythonOperator(
        task_id='fork1',
        python_callable=get_tasks,provide_context=True,trigger_rule='none_failed')
    t1=DummyOperator(task_id='task_1',trigger_rule='none_failed')
    fork2 = BranchPythonOperator(
        task_id='fork2',
        python_callable=get_tasks,provide_context=True,trigger_rule='none_failed')
    t2=DummyOperator(task_id='task_2',trigger_rule='none_failed')
    fork3 = BranchPythonOperator(
        task_id='fork3',
        python_callable=get_tasks,provide_context=True,trigger_rule='none_failed')
    t3=DummyOperator(task_id='task_3',trigger_rule='none_failed')

    fork1 >> t1  >> fork2 >> t2 >> fork3 >> t3

    # current_task = 1
    # start_from_task = int(Variable.get(key='start_from_task'))

    # print("start from task: " + str(start_from_task))

    # if (current_task >= start_from_task):
    #     t1=DummyOperator(task_id='task_1')
    #     d1 >> t1
    #     d1 = t1
    #     current_task += 1

    # if (current_task >= start_from_task):
    #     t2=DummyOperator(task_id='task_2')
    #     d1 >> t2
    #     d1 = t2
    #     current_task += 1

    # if (current_task >= start_from_task):
    #     t3=DummyOperator(task_id='task_3')
    #     d1 >> t3
    #     d1 = t3
    #     current_task += 1
    
    