#!/bin/bash

# Check if a username is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <username>"
    exit 1
fi

# Display the provided username
echo "Hello, $1!!"

#chmod +x display_user.sh
#./display_user.sh John
