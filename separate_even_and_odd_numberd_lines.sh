#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

awk 'NR % 2 == 0 { print > "evenfile" } NR % 2 == 1 { print > "oddfile" }' "$1"

echo "Even lines written to evenfile and odd lines written to oddfile."


#./separate_even_and_odd_numberd_lines.sh input1.sh
#vi evenfile
#vioutpufile
