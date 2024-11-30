#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Usage: $0 <username> <folder>"
    exit 1
fi

username="$1"
folder="$2"
file_path="$folder/${username}.txt"

cat file_path