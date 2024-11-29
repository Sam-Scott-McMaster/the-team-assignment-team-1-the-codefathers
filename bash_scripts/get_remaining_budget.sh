#!/bin/bash
if [ $# -ne 1 ]; then
    echo "Usage: $0 <username>"
    exit 1
fi

username="$1"
file_path="transaction_logs/${username}.txt"

if [ ! -f "$file_path" ]; then
    echo "0.00"  # Default budget if file doesn't exist
    exit 0
fi

# Extract the most recent budget entry
grep "Remaining Budget:" "$file_path" | tail -1 | awk '{print $2}'
