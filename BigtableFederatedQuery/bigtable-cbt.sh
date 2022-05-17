 # https://cloud.google.com/bigtable/docs/cbt-overview

gcloud components update
gcloud components install cbt

gcloud auth application-default login
gcloud auth login

# https://cloud.google.com/bigtable/docs/create-instance-write-data-cbt-cli
echo project = anand-bq-test-2 > ~/.cbtrc
echo instance = test-1 >> ~/.cbtrc

cat ~/.cbtrc

cbt ls HCA_TEST


cbt set HCA_TEST r1 cf1:c1=row-1-column-1
cbt set HCA_TEST r1 cf1:c2=row-1-column-2
cbt set HCA_TEST r2 cf1:c1=row-2-column-1
cbt set HCA_TEST r2 cf1:c2=row-2-column-2

cbt read HCA_TEST
