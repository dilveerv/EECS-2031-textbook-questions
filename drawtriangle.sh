#!/bin/bash
str="*"

if [ $# -eq 0 ]
then
  echo "Input a argument!"
  exit 1
else
  for (( i=1; i<=$1; i++ ))
  do
     echo "$str"
     str="$str *"
  done
fi