#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script retrieves the most recent credit balance for a specified user from their transaction log.
# The script takes two arguments: the folder containing the user's transaction logs and the username.

# Check if exactly two arguments are provided.
if [ $# -ne 2 ]; then
    echo "Usage: $0 <folder> <username>"  # Display usage instructions if incorrect arguments are given.
    exit 1                               # Exit with an error status.
fi

# Assign the folder and username arguments to variables.
folder="$1"
username="$2"

# Construct the path to the user's transaction log file.
file_path="$folder/${username}.txt"

# Extract and print the most recent credit balance from the transaction log file.
grep "Credit Balance: " "$file_path" | tail -n 1 | awk '{print $NF}'  # Get the last "Credit Balance" line and print the balance value.