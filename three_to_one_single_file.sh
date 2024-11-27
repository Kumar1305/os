
#!/bin/bash
# Combine three text files and display the word count

if [ $# -ne 3 ]; then
    echo "Usage: $0 file1 file2 file3"
    exit 1
fi

cat "$1" "$2" "$3" > combined.txt
echo "Combined contents into combined.txt"
wc -w combined.txt

#./three_to_one_single_file.sh input1.txt input2.txt input3.txt

