import datetime

import airflow
from airflow.providers.ssh.operators.ssh import SSHOperator
from airflow.providers.google.cloud.hooks.compute_ssh import ComputeEngineSSHHook

GCE_INSTANCE = 'composer-demo-instance'
GCE_ZONE = 'us-east4-c'
PROJECT_ID = 'pankaj-test-353417'

default_args = {
    'owner': 'airflow',
    'depends_on_past': False,
    'email_on_failure': False,
    'email_on_retry': False,
    'retries': 0
}

with airflow.DAG(
    dag_id='write_data_on_prem',
    start_date=datetime.datetime(2022, 1, 1),
    description='Writes data to a compute instance',
    schedule_interval=None,
    default_args=default_args,
) as dag:

    ssh_task = SSHOperator(
        task_id="write_data_on_prem",
        ssh_hook=ComputeEngineSSHHook(
            instance_name=GCE_INSTANCE,
            zone=GCE_ZONE,
            project_id=PROJECT_ID,
            use_oslogin=True,
            use_iap_tunnel=False,
            use_internal_ip=True
        ),
        command='cd /home/bajpaipankaj_google_com/demo_ssh && sudo touch demo.txt && sudo chmod 777 demo.txt && gsutil ls gs://event-arc-test/ >> demo.txt && sudo cp demo.txt /demo_ssh',
        dag=dag
    )
