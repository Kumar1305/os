#!/bin/bash
read -p "Enter your name: " username
read -p "Hello $username, please enter the file name: " filename
lines_per_page=15
total_lines=$(wc -l < "$filename")
current_line=1
while [[ $current_line -le $total_lines ]]; do
    head -n $((current_line + lines_per_page - 1)) "$filename" | tail -n $lines_per_page
    current_line=$((current_line + lines_per_page))
    if [[ $current_line -le $total_lines ]]; then
        read -n 1 -p "Press Enter or any key to see the next $lines_per_page lines..."
        echo ""
    fi
done

