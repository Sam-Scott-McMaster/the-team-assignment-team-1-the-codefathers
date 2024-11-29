#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <username> <new_budget>"
    exit 1
fi

username="$1"
new_budget="$2"
file_path="history_logs/${username}.txt"
temp_file="history_logs/${username}_temp.txt"

# Ensure the directory exists
mkdir -p "$(dirname "$file_path")"

# Create a temporary file with updated budget
while IFS= read -r line; do
    if [[ "$line" == Budget:* ]]; then
        echo "Budget: $new_budget" >> "$temp_file"
    else
        echo "$line" >> "$temp_file"
    fi
done < "$file_path"

# Replace the original file with the updated file
mv "$temp_file" "$file_path"

echo "Budget updated successfully."
