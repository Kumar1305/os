#!/bin/bash

read -p "Enter the number of terms: " n
a=0
b=1
echo -n "Fibonacci series: "
for (( i=1; i<=n; i++ ))
do
    echo -n "$a "
    temp=$((a + b))
    a=$b
    b=$temp
done
echo
