#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script retrieves the most recent password entry for a specified user from their history log.
# If the user's file is not found, an error message is displayed.
# The script takes one argument: the username.

# Check if exactly one argument is provided.
if [ $# -ne 1 ]; then
    echo "Usage: $0 <username>"  # Display usage instructions if incorrect arguments are given.
    exit 1                       # Exit with an error status.
fi

# Assign the username argument to a variable.
username="$1"

# Construct the path to the user's history log file.
file_path="history_logs/${username}.txt"

# Check if the user's file exists.
if [ ! -f "$file_path" ]; then
    echo "Error: User file not found."  # Output an error if the file does not exist.
    exit 1                              # Exit with an error status.
fi

# Extract and output the most recent password entry from the file.
grep "Password:" "$file_path" | tail -1 | awk -F': ' '{print $2}'  # Fetch the last "Password:" line and print the password.
