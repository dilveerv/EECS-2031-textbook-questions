#!/bin/bash

mult () {
local sum
let "sum=$1*$2"
return $sum
}
mult 4+3 5+1
echo $?