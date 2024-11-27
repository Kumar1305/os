#!/bin/bash

# Check if a file name is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Check if the file exists
if [ ! -f "$1" ]; then
    echo "File not found!"
    exit 1
fi

# Check spelling using aspell
aspell check "$1"


#chmod +x spell_check.sh
#./spell_check.sh example.txt
#brew install aspell
#sudo apt-get install aspell

