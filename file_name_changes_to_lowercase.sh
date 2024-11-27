#!/bin/bash
for file in "$@"; do
       lower_file=$(echo "$file" | tr 'A-Z' 'a-z')
        if [ "$file" != "$lower_file" ]; then
        mv "$file" "$lower_file"
        echo "Renamed $file to $lower_file"
    else
        echo "$file is already in lowercase"
    fi
done

#./rename_to_lowercase.sh FileName.txt 

