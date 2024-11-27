#!/bin/bash

read -p "Enter a string: " str

if [ ${#str} -ge 5 ]; then
    echo "String is valid."
else
    echo "String must have at least 5 characters."
fi
