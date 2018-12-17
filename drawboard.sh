#!/bin/bash

#Dilveer Virdi 214332308

TOTAL=0

for i in "$@"
do
    if [[ $i == " " ]]
    then
      TOTAL=$((TOTAL + 1))
    elif [[ $i == "X" ]]
    then
      TOTAL=$((TOTAL + 1))
    elif [[ $i == "O" ]]
    then
      TOTAL=$((TOTAL + 1))
    else
      echo "invaild character"
      exit
    fi
done

if [ $TOTAL -eq 9 ]
then
  echo "$1|$2|$3"
  echo "-+-+-"
  echo "$4|$5|$6"
  echo "-+-+-"
  echo "$7|$8|$9"
else
  echo "Number of arguments not vaild"
fi