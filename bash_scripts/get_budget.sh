#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script retrieves the most recent budget entry for a specified user from their history log.
# If the user's file does not exist, it outputs a default budget of 0.00.
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
    echo "0.00"  # Output a default budget if the file does not exist.
    exit 0       # Exit with a success status.
fi

# Extract and output the most recent budget entry from the file.
grep "Budget:" "$file_path" | tail -1 | awk '{print $2}'  # Fetch the last "Budget:" line and print the second field (budget amount).
