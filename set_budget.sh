#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Usage: $0 <username> <budget>"
    exit 1
fi

username="$1"
budget="$2"
file_path="history_logs/${username}.txt"

echo "Budget: $budget" >> "$file_path"
