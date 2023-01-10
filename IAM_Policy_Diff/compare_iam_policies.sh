#!/bin/bash
if [ $# -le 1 ]
  then
    echo "Please provide 2 parameters:"
    echo " 1. First policy file. E.g. project-id-1"
    echo " 2. GCS folder location. E.g. gs://bucket_name/folder_name/"
    echo " "
    echo "usage: "
    echo "   ./capture_iam_policy.sh <project_id> <gcs_location>"
    exit 0
fi
diff <(gsutil cat $1) <(gsutil cat $2)