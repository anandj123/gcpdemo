from datetime import datetime
from airflow import models
from google.cloud import storage
import logging
from airflow.models import Variable
from airflow.contrib.operators.bigquery_operator import BigQueryOperator

ops = []
operators = []

def fetch_sps_from_gcs():
     global ops
     global operators
     storage_client = storage.Client()
     bucket = storage_client.get_bucket('hca-data-set')
     blob = storage.Blob(Variable.get('dag_sp_gcs_file_name1'), bucket)
     data = blob.download_as_text()
     logging.info(data)
     operators = data.split(">>")
     for index,operator in enumerate(operators):
         if(',' in operator):
             operators[index] = operator.strip("[]").split(",")
     logging.info(operators)
     for operator in operators:
         if(not isinstance(operator, list)):
            task_id = "task_"+operator;
            calling_sp = "call HCA_Test_DS."+str(operator)+"();"
            op = BigQueryOperator(
                task_id=task_id,
					 sql=calling_sp,
                use_legacy_sql=False,
            )
            ops.append(op);
         else:
            p_ops = []
            for p_op in operator:
                task_id = "task_"+p_op;
                calling_sp = "call HCA_Test_DS."+str(p_op)+"();"
                op = BigQueryOperator(
						  task_id=task_id,
						  sql=calling_sp,
						  use_legacy_sql=False,
                )
                p_ops.append(op);
            ops.append(p_ops);    
     logging.info(ops)
            
with models.DAG(
    "call_bq_sps_dynamic",
    schedule_interval=None,
    start_date=datetime(2021, 1, 1),
	 ) as dag:
      
    fetch_sps_from_gcs()
   
    logging.info(operators)
    for i in range(1,len(operators)):
        ops[i-1] >> ops[i]
