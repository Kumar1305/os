for i in {1..3}; do
echo "Displaying processes,
attempt $i:"
ps aux
if [ $i -ne 3 ]; then
sleep 30
fi
done
echo "Process monitoring
completed."
