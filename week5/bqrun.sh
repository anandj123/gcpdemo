#!/bin/bash
if [ -n "$1" ]; then
  echo "Biquery query GCS directory passed : "$1
else
  echo "Biquery query GCS directory not supplied."
  exit
fi

rm -rf temp/

mkdir -p ./temp > /dev/null
pushd temp > /dev/null

for f in $(gsutil ls $1 |grep -v '/$') ;
do
  echo 'Processing file : '$f ;
  # Load file from Google cloud storage to local for preocessing
  gsutil -q cp $f . > /dev/null ;

  # split file by end query toke (;) into separate files
  # so that they can be run one after another
  #csplit -k * '/\;/' {1} > /dev/null ;

  FILES=* ;

  for g in $FILES ;
  do
    echo "-----------------------------------------------------------------------" ;
    echo "Processing $f file..." ;
    cat $g ;
    echo "-----------------------------------------------------------------------" ;
    # run query present in the file
    bq query "$(cat $g)" ;
  done
  rm * ;
done

popd
rm -rf temp/