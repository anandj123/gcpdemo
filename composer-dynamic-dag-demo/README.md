# Overview
Demonstration of how to use Airflow to scan a GCS bucket for shell scripts and run them in parallel using Cloud Composer. 

This is mostly motivated by requirement for implementation of the batch ETL/ELT pipeline as shell scripts (e.g bash etc.) and schedule them dynamically by copying them into a GCS location and using a composer environment and a predefined composer DAG that can dynamically pick up these shell scripts and run them in parallel. 

# Files
[Main Composer DAG file](./gcs_loop_dag.py)

The following file is the main DAG routine that scans the directory for .sh files and run them in parallel.

# Prerequisites:

1. Need a running Cloud Composer instance to run the DAG.
2. Copy the "DAG folder" from "Environment Configuration" section of the Comoser instance detail page.
3. Create a folder under the main bucket of the dag folder. So the folder in the bucket looks like the following:

gs://us-east1-2003938zhe-bucket

| >-- dags
    >-- dag1.py
    >-- dag2.py
>-- data
    >-- run1.sh
    >-- run2.sh
>-- logs
>-- plugins


the /data folder maps to /home/airflow/gcs/data/ within the DAG environment. The loop dag code scans this directory for any files with .sh extension.

# What are the challenges with this implementation vs writing native airflow DAGs

The following challenges need to be addressed in the batch scripts.

1. Make these batch scripts idempotent (so that they can be run repeatedly without compromising the integrity of the source and target systems)

2. Maintain state internally in those scripts (e.g. which steps are run already when script is restarted, or processing is already done for today etc.)

3. Any serial dependency steps need to be maintained in those scripts (e.g. If step X fails then capturing the error code and making decision to move forward of fail, handling exceptions and performing recovery, cleanup or notification steps)

4. Retry and recover logic they have to take care within the script (e.g. exponential backoff algorithms when a step fails and want to retry N number of times etc.)

5. Any IAM permission issues outside of Composer run time they have to take care of in the batch scripts.

