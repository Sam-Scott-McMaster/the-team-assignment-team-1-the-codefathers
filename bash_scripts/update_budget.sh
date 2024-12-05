#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script updates the budget of a specified user in their history log.
# It takes two arguments: the username and the new budget value. It updates
# the budget in the user's history log file and saves the changes.

# Check if exactly two arguments are provided: username and new_budget.
if [ $# -ne 2 ]; then
    echo "Usage: $0 <username> <new_budget>"  # Display usage instructions if incorrect arguments are given.
    exit 1                               # Exit with an error status.
fi

# Assign the username and new_budget arguments to variables.
username="$1"
new_budget="$2"

# Define the path to the user's history log file and a temporary file for the update.
file_path="history_logs/${username}.txt"
temp_file="history_logs/${username}_temp.txt"

# Ensure that the directory for the file exists.
mkdir -p "$(dirname "$file_path")"  # Create the directory if it doesn't exist.

# Create a temporary file with the updated budget value.
while IFS= read -r line; do
    if [[ "$line" == Budget:* ]]; then
        # If the line contains "Budget:", replace it with the new budget value.
        echo "Budget: $new_budget" >> "$temp_file"
    else
        # Otherwise, retain the original line.
        echo "$line" >> "$temp_file"
    fi
done < "$file_path"

# Replace the original file with the updated temporary file.
mv "$temp_file" "$file_path"  # Rename the temp file to overwrite the original file.

# Print a success message.
echo "Budget updated successfully."
