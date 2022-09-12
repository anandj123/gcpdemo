from airflow import DAG
from datetime import datetime
import os
from airflow.operators.dummy_operator import DummyOperator

default_args = {
    'owner': 'airflow',
    'depends_on_past': False,
    'email_on_retry': False,
    'retries': 0
}

with DAG(
    dag_id='dag2',
    start_date=datetime(2022, 4, 1),
    default_args=default_args,
    description='Dummy dag 2',
    schedule_interval=None,
    catchup=False,
) as dag:

    dummy = DummyOperator(task_id='test')
