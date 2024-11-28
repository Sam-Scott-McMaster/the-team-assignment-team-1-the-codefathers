#!/bin/bash
if [ $# -ne 3 ]; then
    echo "Usage: $0 <folder> <username> <info>"
    exit 1
fi

folder="$1"
username="$2"
info="$3"
file_path="$folder/${username}.txt"

echo "$info" >> "$file_path"
