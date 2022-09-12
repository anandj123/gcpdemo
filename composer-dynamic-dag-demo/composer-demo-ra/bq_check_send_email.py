from airflow import DAG
from datetime import datetime
import os
from airflow.providers.ssh.operators.ssh import SSHOperator
from airflow.providers.google.cloud.transfers.gcs_to_bigquery import GCSToBigQueryOperator
from airflow.providers.google.cloud.operators.gcs import GCSDeleteObjectsOperator
from airflow.utils.task_group import TaskGroup
from airflow.operators.bash_operator import BashOperator
from airflow.operators.dummy_operator import DummyOperator
from airflow.operators.python_operator import PythonOperator
from airflow.providers.google.cloud.operators.bigquery import BigQueryInsertJobOperator
from airflow.providers.google.cloud.operators.bigquery import BigQueryValueCheckOperator, BigQueryCheckOperator
from airflow.operators.email import EmailOperator
from airflow.utils.email import send_email

CUR_DIR = os.path.abspath(os.path.dirname(__file__))

# job_failure_email_list = {
#     'dev': [],
#     'test': [
#         'pre_email_group@domain.com',
#     ],
#     'prod': [
#         'prod_email_group@domain.com',
#         'prod_email_group2@domain.com',
#     ],
# }

default_args = {
    'owner': 'airflow',
    'depends_on_past': False,
    'email_on_failure': True,
    'email': ['simson@google.com'],
    'email_on_retry': False,
    'retries': 0
}
# Project
# pankaj-test-353417

# DAGs bucket
# gs://us-east4-demo1-1d9ef768-bucket/dags

# Copy DAG to composer dags bucket:
# gsutil cp bq_check_send_email.py gs://us-east4-demo1-1d9ef768-bucket/dags

with DAG(
    dag_id='bq_check_send_email',
    start_date=datetime(2022, 4, 1),
    default_args=default_args,
    description='Checks BQ table for a value and sends an email',
    schedule_interval=None,
    catchup=False,
) as dag:

    check_count = BigQueryCheckOperator(
        task_id="check_count",
        sql=f"SELECT COUNT(1) > 0 FROM `pankaj-test-353417.demo.demo`",
        use_legacy_sql=False,
    )

    email = EmailOperator(
        task_id='email',
        to='simson@google.com',
        subject='success!',
        html_content="""Your DAG succeeded!""",
    )

    check_count >> email
