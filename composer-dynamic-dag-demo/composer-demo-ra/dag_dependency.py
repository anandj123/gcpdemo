from airflow import DAG
from datetime import datetime
import os
import logging
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
from airflow.operators.trigger_dagrun import TriggerDagRunOperator
from airflow.operators.sql import BranchSQLOperator
from airflow.providers.google.cloud.hooks.bigquery import BigQueryHook
from airflow.operators.python_operator import PythonOperator

default_args = {
    'owner': 'airflow',
    'depends_on_past': False,
    'email_on_retry': False,
    'retries': 0
}
# Project
# pankaj-test-353417

# DAGs bucket
# gs://us-east4-demo1-1d9ef768-bucket/dags

# Copy DAG to composer dags bucket:
# gsutil cp dag_dependency.py gs://us-east4-demo1-1d9ef768-bucket/dags

GCP_CONN_ID = 'bigquery_default'

with DAG(
    dag_id='dag_dependency',
    start_date=datetime(2022, 4, 1),
    default_args=default_args,
    description='Triggers multiple dags in dependencies',
    schedule_interval=None,
    catchup=False,
) as dag:

    # Example 1 - Chain DAGs
    dag1 = TriggerDagRunOperator(
        task_id="dag1",
        trigger_dag_id="dag1",
    )

    dag2 = TriggerDagRunOperator(
        task_id="dag2",
        trigger_dag_id="dag2",
    )

    dag1 >> dag2

    # Example 2 - Chain Tasks

    bq_sql = BigQueryInsertJobOperator(
        task_id='create_table',
        configuration={
            'query': {
                'query': """
                CREATE OR REPLACE TABLE `pankaj-test-353417`.demo.new_table AS
                    SELECT 1 AS col1, 'A' AS col2 UNION ALL
                    SELECT 2, 'B' UNION ALL
                    SELECT 3, 'C' UNION ALL
                    SELECT 4, 'D'
                """,
                'useLegacySql': False,
            },
        },
    )

    check_count = BigQueryCheckOperator(
        task_id="check_count",
        sql=f"SELECT COUNT(1) > 0 FROM `pankaj-test-353417`.demo.new_table",
        use_legacy_sql=False,
    )

    bq_sql2 = BigQueryInsertJobOperator(
        task_id='create_table_copy',
        configuration={
            'query': {
                'query': """
                CREATE OR REPLACE TABLE `pankaj-test-353417`.demo.new_table2 AS
                    SELECT * FROM `pankaj-test-353417`.demo.new_table
                """,
                'useLegacySql': False,
            },
        },
    )

    bq_sql >> check_count >> bq_sql2

    # Example 3 - Chain Tasks with failure

    bq_sql_fail = BigQueryInsertJobOperator(
        task_id='create_table2',
        configuration={
            'query': {
                'query': """
                CREATE OR REPLACE TABLE `pankaj-test-353417`.demo.table_fail AS
                    SELECT 1 AS col1, 'A' AS col2 UNION ALL
                    SELECT 2, 'B' UNION ALL
                    SELECT 3, 'C' UNION ALL
                    SELECT 4, 'D'
                """,
                'useLegacySql': False,
            },
        },
    )

    check_count_fail = BigQueryCheckOperator(
        task_id="check_count_fail",
        sql=f"SELECT COUNT(1) > 5 FROM `pankaj-test-353417`.demo.table_fail",
        use_legacy_sql=False,
    )

    bq_sql2_fail = BigQueryInsertJobOperator(
        task_id='create_table_copy_fail',
        configuration={
            'query': {
                'query': """
                CREATE OR REPLACE TABLE `pankaj-test-353417`.demo.table_fail2 AS
                    SELECT * FROM `pankaj-test-353417`.demo.table_fail
                """,
                'useLegacySql': False,
            },
        },
    )

    bq_sql_fail >> check_count_fail >> bq_sql2_fail
