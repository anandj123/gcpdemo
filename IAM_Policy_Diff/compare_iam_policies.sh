#!/bin/bash
if [ $# -le 1 ]
  then
    echo "Please provide 2 parameters:"
    echo " 1. First policy file. E.g. gs://bucket_name/folder_name/file1"
    echo " 2. Second policy file. E.g. gs://bucket_name/folder_name/file2"
    echo " "
    echo "usage: "
    echo "   ./capture_iam_policy.sh <gcs_location_1> <gcs_location_2>"
    exit 0
fi
diff <(gsutil cat $1) <(gsutil cat $2)