#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Usage: $0 <username> <folder>"
    exit 1
fi

username="$1"
folder="$2"
file_path="$folder/${username}.txt"

if [ -f "$file_path" ]; then
    exit 0  # File found
else
    exit 1  # File not found
fi