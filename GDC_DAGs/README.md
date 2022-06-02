# Prerequisites:

1. A running Cloud Composer instance to run the DAG.
2. the DAG files are placed inside the "DAG folder" that is found in the "Environment Configuration" section of the Comoser instance detail page.
3. Create a folder under the main bucket of the dag folder. So the folder in the bucket looks like the following:

gs://<COMPOSER_BUCKET_NAME>

```

|-- dags
    |-- dag1.py
    |-- dag2.py
|-- data
    |-- bq_example.sql
    |-- task_dependency_config.txt
|-- logs
|-- plugins

```

4. The ```/data``` folder maps to ```/home/airflow/gcs/data/``` within the DAG environment.

# DAGs for each use case

## Call single Stored procedure

DAG file name : `call_single_stored_procedure.py`

**Prerequisites**: 
1. The stored procedure is already present in Bigquery. 
2. The Variable named `call_single_sp` is already present in Airflow configuration who's value contains the name of the stored procedure to call. 

**Description**: 

It reads the name of the stored procedure to call in Bigquery from the Airflow variable `call_single_sp` and calls this stored procedure. 
PS : Currently the dataset name is hardcoded but once can add variables for project_name, dataset_name in airflow. 

## Call multiple Stored procedures according to dependencies configuration

File name : `call_multiple_stored_procedure_dynamic.py`

**Prerequisites**:  
1. The stored procedures are already present in Bigquery. 
2. The Variable named `dag_sp_gcs_file_name1` is already present in Airflow configuration who's value contains the filepath URI (exlcuding the bucket name) which contains the task dependency configuration.

**Description**: 

This DAG reads the task dependency file (refer to sample file named `stored_procedure_dependency_config.txt`) from GCS, parses the file and creates individual tasks in airflow for each stored procedure call and sets the dependency among tasks according to the configuration. 

## Run a SQL query in Bigquery

File name : `run_sql_bq.py`

**Prerequisites**:  
1. The SQL file is already present in GCS. 
2. The Variable named `dag_sql_file_name1` is already present in Airflow configuration who's value contains the filepath URI (exlcuding the bucket name) which contains the SQL query to run in Bigquery.

**Description**: 

This DAG reads SQL query from the file from GCS (refer to `example_sql_bigquery.sql`), and runs this query in Bigquery. The status code and logs will be visible in the airflow task logs itself. 



