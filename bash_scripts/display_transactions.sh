#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Usage: $0 <folder> <username>"
    exit 1
fi

folder="$1"
username="$2"
file_path="$folder/${username}.txt"
 
cat "$file_path"