#!/bin/bash
echo "Enter an input:"
read input
if [[ $input =~ ^[0-9]+$ ]]; then
echo "$input is a number."
else
echo "$input is a string."
fi
