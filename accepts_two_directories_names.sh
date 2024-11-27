#!/bin/bash
if [ $# -ne 2 ]; then
echo "Usage: $0 <directory1>
<directory2>"
exit 1
fi
dir1=$1
dir2=$2
if [ ! -d "$dir1" ]; then
echo "Error: $dir1 is not a directory."
exit 1
fi
if [ ! -d "$dir2" ]; then
echo "Error: $dir2 is not a directory."
exit 1
fi
for le1 in "$dir1"/*; do
lename=$(basename "$le1")
le2="$dir2/$lename"
if [ -f "$le2" ]; then
if cmp -s "$le1" "$le2"; then
echo "Deleting $le1 as it matches with $le2"
rm "$le1"
fi
fi
done
echo "Completed processing."
