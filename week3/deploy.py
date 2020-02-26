import os

with open('create_table.sql', 'r') as f:
    sql = f.read()
    os.system("bq query --nouse_legacy_sql '" + sql + "'")
