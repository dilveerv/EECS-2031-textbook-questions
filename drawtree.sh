#!/bin/bash
str="*"
blank=" "
SPACE=$(($1 / 2))

if [ $# -eq 0 ]
then
  echo "Input a argument!"
  exit 1
fi

for (( j=1; j<=$SPACE; j++ ))
do
str="$blank $str"

done

trunk=$str

for (( i=1; i<=$1; i++ ))
do
  echo "$str"
  str=${str/ /}
  str="$str *"
done

echo "$trunk"
echo "$trunk"