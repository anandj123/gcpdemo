# Overview
This project is used for capturing the current IAM policies as backup for audit
and comparison purposes.

# Setup instruction
You need to copy the project into a location from where the following command 
could be run.

```
gcloud asset search-all-iam-policies --scope=projects/$1

```

You could use [Google Cloud Shell](https://cloud.google.com/shell) or any other location if you need to do this in a regular basis.

Also, you need to provide the authentication and authorization for this command
to be run (either using service account or your own user account).

```
gcloud auth application-default login
```

# Script execution
There are 2 files in the current project

## Capture IAM policies
For capturing and backing up all IAM policies for a project you need to run 
the following script 

```
capture_iam_policy.sh
```

The script requires 2 arguments

|Parameter|Description|
|---|---|
|project_id|Provide your project id e.g. project_id_1 |
|gcs_location| Provide the GCS location for backup E.g. gs://bucket_name/folder_name/ |

The usage is shown when you run without these parameters.

```
./capture_iam_policy.sh
Please provide 2 parameters:
 1. GCP project Id. E.g. project-id-1
 2. GCS folder location. E.g. gs://bucket_name/folder_name/
 
usage: 
   ./capture_iam_policy.sh <project_id> <gcs_location>
```

If these 2 parameters are passed the script will capture all IAM policies for the
mentioned project and save them to provided GCS location with the following 
naming convention

```
<gcs_location>/<project_id><current_datetime>

```
## Compare IAM policies.
To compare 2 IAM policies for differences, you could use the following script.
```
compare_iam_policies.sh
```
The script requires 2 arguments

|Parameter|Description|
|---|---|
|gcs_location_1| Provide the GCS location for backup E.g. gs://bucket_name/folder_name/file1 |
|gcs_location_2| Provide the GCS location for backup E.g. gs://bucket_name/folder_name/file2 |

The usage is shown when you run without these parameters.

```
./compare_iam_policies.sh
Please provide 2 parameters:
 1. First policy file. E.g. gs://bucket_name/folder_name/file1
 2. Second policy file. E.g. gs://bucket_name/folder_name/file2
 
usage: 
   ./capture_iam_policy.sh <gcs_location_1> <gcs_location_2>
```

If these 2 parameters are passed the script will compare the IAM policies captured
and print the output to console. The output looks like following:

```

706,717d705
< assetType: secretmanager.googleapis.com/Secret
< folders:
< - folders/1002694244729
< organization: organizations/739076213843
< policy:
<   bindings:
<   - members:
<     - user:lukemc@google.com
<     role: roles/secretmanager.secretAccessor
< project: projects/701417641712
< resource: //secretmanager.googleapis.com/projects/701417641712/secrets/secret1
< ---
1400,1401c1388,1390
<     - serviceAccount:service-701417641712@gcp-sa-workflows.iam.gserviceaccount.com
<     role: roles/workflows.serviceAgent
---
>     - serviceAccount:service-701417641873@gcp-sa-visualinspection.iam.gserviceaccount.com
>     role: roles/visualinspection.serviceAgent
>  

```

# Read the output
The above output can be interpreated as such:

```
< assetType: secretmanager.googleapis.com/Secret
< folders:
< - folders/1002694244729
< organization: organizations/739076213843
```
Entries like the above means that these policies were added to the first file (or alternatively removed from the second file).

```
>     - serviceAccount:service-701417641873@gcp-sa-visualinspection.iam.gserviceaccount.com
>     role: roles/visualinspection.serviceAgent
```

Entries like above means these policies are added to the second file (or alternatively removed from the first file).
