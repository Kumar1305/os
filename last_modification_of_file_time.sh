if [ "$#" -ne 1 ]; then
echo "Usage: $0 <filename>"
exit 1
fi
file="$1"
if [ -f "$file" ]; then
echo "Last modication time of $file:"
stat --format '%y' "$file"   #instead of --format use -f "%Sm" if error
else
echo "$file does not exist."
fi
