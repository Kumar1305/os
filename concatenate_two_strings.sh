#!/bin/bash
read -p "Enter the  first string: " str1
read -p "Enter the second string: " str2
result="$str1$str2"
echo "Concatenated string: $result"
echo "Length of the concatenated string:${#result}"
