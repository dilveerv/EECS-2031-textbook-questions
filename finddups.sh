#!/bin/bash

#Dilveer Virdi 214332308

for i in "$@"
do
check=0
count="$i:"
    
  for k in "$@"
  do

    if cmp -s $i $k
    then
      count="$count $k"  
      check=$(($check + 1))
    fi

  done

if [ $check -gt 0 ]
then
  echo "$count"
fi
  
done