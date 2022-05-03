 # https://cloud.google.com/bigtable/docs/cbt-overview

gcloud components update
gcloud components install cbt

# https://cloud.google.com/bigtable/docs/create-instance-write-data-cbt-cli
echo project = anand-bq-test-2 > ~/.cbtrc
echo instance = test-1 >> ~/.cbtrc

cat ~/.cbtrc

cbt ls HCA_TEST

cbt set HCA_TEST r1 cf1:c1=test-value

cbt read HCA_TEST