from airflow import DAG
from datetime import datetime
import os
from airflow.operators.dummy_operator import DummyOperator
from airflow.providers.google.cloud.operators.bigquery import BigQueryInsertJobOperator
from airflow.providers.google.cloud.operators.bigquery import BigQueryValueCheckOperator, BigQueryCheckOperator

default_args = {
    'owner': 'airflow',
    'depends_on_past': False,
    'email_on_retry': False,
    'retries': 0
}

with DAG(
    dag_id='dag1',
    start_date=datetime(2022, 4, 1),
    default_args=default_args,
    description='dummy dag 1',
    schedule_interval=None,
    catchup=False,
) as dag:

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
        sql=f"SELECT COUNT(1) > 0 FROM `pankaj-test-353417.demo.new_table`",
        use_legacy_sql=False,
    )

    bq_sql >> check_count
