#!/bin/bash

if [[ -d $1 ]]; then
    echo "$1 is a directory"
elif [[ -f $1 ]]; then
    mkdir -p ~/Bin/
    mv ${PWD}/$1/ ~/Bin/
else
    echo "$1 is not valid"
    exit 1
fi