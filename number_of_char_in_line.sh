#!/bin/bash
echo "Enter the text:"
while IFS= read -r line; do
chars=$(echo "$line" | wc -c)
words=$(echo "$line" | wc -w)
echo "$line has $chars
characters and $words words."
done
