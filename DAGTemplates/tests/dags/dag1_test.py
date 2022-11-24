from airflow import DAG
from airflow.models import DagBag

def test_no_import_errors():
    dag_bag = DagBag(include_examples=False)
    dag_bag.process_file('dag1.py')
    assert len(dag_bag.import_errors) == 0, "No Import Failures"
    assert len(dag_bag.dagbag_stats) == 1
    print (dag_bag.get_dag("airflow_tutorial_v01")) 
# command I used
# airflow info
# python3 -m site
# pip3 list
# python3 -m pip install -r requirements.txt       
# pytest tests/dags/dag1_test.py -s           (to see the stdout print messages)


