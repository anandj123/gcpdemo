#!/bin/bash
if [ $# -le 1 ]
  then
    echo "Please provide 2 parameters:"
    echo " 1. GCP project Id. E.g. project-id-1"
    echo " 2. GCS folder location. E.g. gs://bucket_name/folder_name/"
    echo " "
    echo "usage: "
    echo "   ./capture_iam_policy.sh <project_id> <gcs_location>"
    exit 0
fi
gcs_location=$2
end_char="${gcs_location: -1}"
echo $end_char
if [ $end_char != "/" ]
then
    gcs_location=$gcs_location"/"
fi
gcs_location=$gcs_location`date +"%Y-%m-%d-%T"`
echo $gcs_location

gcloud asset search-all-iam-policies --scope=projects/$1 > temp.out
gsutil cp temp.out $gcs_location
rm temp.out

