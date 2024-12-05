#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script reads and displays the contents of a user's file from a specified folder.
# It expects two arguments: the folder path and the username.

# Check if exactly two arguments are provided.
if [ $# -ne 2 ]; then
    echo "Usage: $0 <folder> <username>"  # Display usage instructions if the argument count is incorrect.
    exit 1                               # Exit with an error status.
fi

# Assign arguments to variables for better readability.
folder="$1"
username="$2"

# Construct the full path to the user's file within the specified folder.
file_path="$folder/${username}.txt"

# Display the contents of the user's file.
cat "$file_path"
