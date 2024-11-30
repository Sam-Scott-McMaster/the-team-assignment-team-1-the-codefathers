#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Usage: $0 <folder> <username>"
    exit 1
fi

folder="$1"
username="$2"
file_path="$folder/${username}.txt"

if [ ! -f "$file_path" ]; then
    echo "0.00"  # Default value if file doesn't exist
    exit 0
fi

# Extract the most recent debit balance
grep "Debit Balance:" "$file_path" | awk '{print $3}'