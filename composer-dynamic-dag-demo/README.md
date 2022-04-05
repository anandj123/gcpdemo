# Overview
Demonstration of how to use Airflow to scan a GCS bucket for shell scripts and run them in parallel using Cloud Composer.

# Files
[Main Composer DAG file](./gcs_loop_dag.py)

The following file is the main DAG routine that scans the directory for .sh files and run them in parallel.

# Prerequisites:

1. Need a running Cloud Composer instance to run the DAG.
2. Copy the "DAG folder" from "Environment Configuration" section of the Comoser instance detail page.
3. Create a folder under the main bucket of the dag folder. So the folder in the bucket looks like the following:

gs://us-east1-2003938zhe-bucket
|-- dags
    |-- dag1.py
    |-- dag2.py
|-- data
    |-- run1.sh
    |-- run2.sh
|-- logs
|-- plugins

the /data folder maps to /home/airflow/gcs/data/ within the DAG environment. The loop dag code scans this directory for any files with .sh extension.

