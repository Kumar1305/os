#!/bin/bash
# Remove spaces from the text file and redirect output to another file

if [ $# -ne 2 ]; then
    echo "Usage: $0 input_file output_file"
    exit 1
fi

tr -d ' ' < "$1" > "$2"
echo "Spaces removed and output redirected to $2"
#create input.txt and output.txt
#./remove_blank_spaces.sh input.txt output.txt
