#!/bin/bash

for (( i=2; i<=$1; i++ ))
do
  FACT=0
  
  for (( j=2; j<=$i; j++ ))
  do
    REM=$(( $i % $j ))
    
    if [ $REM -eq 0 ]; then
      FACT=$(($FACT + 1));
    fi
  done
  
  if [ $FACT -eq 1 ];then
    echo $i
  fi
  
done