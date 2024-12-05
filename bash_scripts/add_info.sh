#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script appends user information to a specified file within a given folder.
# It takes three arguments: the folder path, username, and the information to append.
# The script checks for correct usage and ensures that the information is added to the appropriate file.

# Check if exactly three arguments are provided.
# If not, display usage instructions and exit with an error code.
if [ $# -ne 3 ]; then
    echo "Usage: $0 <folder> <username> <info>"  # Inform the user about correct script usage.
    exit 1  # Exit with status 1 to indicate an error.
fi

# Assign command-line arguments to descriptive variables for readability.
folder="$1"           # The folder where the user file is located.
username="$2"         # The username used to determine the file name.
info="$3"             # The information to append to the user's file.
file_path="$folder/${username}.txt"  # Construct the full path to the user's file.

# Append the provided information to the user's file.
echo "$info" >> "$file_path"  # Use echo to write the information to the file.
