#!/bin/bash

# Check if the correct number of arguments is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <username>"
    exit 1
fi

username="$1"
file_path="history_logs/${username}.txt"

# If the file doesn't exist, print an error and exit
if [ ! -f "$file_path" ]; then
    echo "Error: User file not found."
    exit 1
fi

# Extract the most recent Password entry and print the password
grep "Password:" "$file_path" | tail -1 | awk -F': ' '{print $2}'
