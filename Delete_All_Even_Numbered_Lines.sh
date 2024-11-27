#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

awk 'NR % 2 == 1' "$1" > temp && mv temp "$1"

echo "Even-numbered lines deleted from $1."

#
#
# 
