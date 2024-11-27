#!/bin/bash
# Translate characters to lowercase in a text file

if [ $# -ne 2 ]; then
    echo "Usage: $0 input_file output_file"
    exit 1
fi

tr '[:upper:]' '[:lower:]' < "$1" > "$2"
echo "Translated to lowercase and saved to $2"

#./filename.sh input.txt output.txt

