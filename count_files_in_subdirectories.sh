#!/bin/bash

for dir in */; do
    if [ -d "$dir" ]; then
        count=$(find "$dir" -type f | wc -l)
        echo "$dir: $count files"
    fi
done
