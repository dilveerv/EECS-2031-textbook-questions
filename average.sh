#!/bin/bash

#Dilveer Virdi 214332308


IFS=,

while read -r -a x; do
  
awk -F "\"*,\"*" '{if($1 == 0) {print $1 " " $4+$5+$6+$7}}' $1