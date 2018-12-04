#!/bin/bash

re='^[0-9]+$'
if ! [[ $1 =~ $re ]] ; then
   echo "The first argument is a character"
else
  echo "The first argument is a string"
fi