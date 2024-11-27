#!/bin/bash
read -p "Enter the file name: " filename
if [[ ! -f "$filename" ]]; then
echo "File does not exist!"
exit 1
fi
article_count=$(grep -o -i -w '\ba\b\|\ban\b\|\bthe\b' "$filename" | wc -l)
echo "The total number of English articles (a, an, the) in the file is: $article_count"
