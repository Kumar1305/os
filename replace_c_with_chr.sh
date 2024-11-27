#!/bin/bash
read -p "Enter the string: " s
read -p "Enter the character to be
replaced: " c
read -p "Enter the replacement
characters (chr): " chr
count=$(echo "$s" | grep -o "$c" | wc -l)
result=$(echo "$s" | sed "s/$c/$chr/g")
echo "Modified string: $result"
echo "Number of replacements: $count"
