#!/bin/bash
find ${PWD} -empty -type d -delete

## count empty dirs only ##
## find /path/ -empty -type d | wc -l ## 
 
## count empty files only ##
## find /path/ -empty -type f | wc -l ## 