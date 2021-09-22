"""Call the stored procedure to populate orders operational layer table"""
import airflow
from airflow import DAG
from airflow.operators.bash_operator import BashOperator
from datetime import timedelta

default_args = {
    'start_date': airflow.utils.dates.days_ago(0),
    'retries': 1,
    'retry_delay': timedelta(minutes=5)
}

dag = DAG(
    'start_merge_orders_job',
    default_args=default_args,
    description='start orders merge job',
    schedule_interval=None,
    dagrun_timeout=timedelta(minutes=20))

# priority_weight has type int in Airflow DB, uses the maximum.
t1 = BashOperator(
    task_id='merge',
    bash_command="bq query --nouse_legacy_sql 'call `anand-bq-test-2.bbby_data.PopulateOrdersOperationLayer`()'",
    dag=dag,
    depends_on_past=False,
    priority_weight=2**31-1)