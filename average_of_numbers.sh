#!/bin/bash
echo "Enter the number of elements:"
read n
sum=0
for ((i=1; i<=n; i++)); do
echo "Enter element $i:"
read num
sum=$((sum + num))
done
avg=$((sum / n))
echo "The average is: $avg"
