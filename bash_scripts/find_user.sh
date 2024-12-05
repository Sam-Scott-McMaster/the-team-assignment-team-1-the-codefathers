#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script checks if a user's file exists in a specified folder.
# It takes two arguments: the username and the folder path.
# The script exits with a status code of 0 if the file is found and 1 if not.

# Check if exactly two arguments are provided.
if [ $# -ne 2 ]; then
    echo "Usage: $0 <username> <folder>"  # Display usage instructions if incorrect arguments are given.
    exit 1                               # Exit with an error status.
fi

# Assign arguments to variables for clarity.
username="$1"
folder="$2"

# Construct the full path to the user's file.
file_path="$folder/${username}.txt"

# Check if the file exists.
if [ -f "$file_path" ]; then
    exit 0  # File exists, exit with success status.
else
    exit 1  # File does not exist, exit with failure status.
fi
