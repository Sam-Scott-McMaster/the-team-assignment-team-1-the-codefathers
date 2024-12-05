#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script creates (or overwrites) a history log file and a transactions log file for a specified user.
# It ensures that both files are created within their respective directories.

# Check if the username argument is provided.
if [ $# -ne 1 ]; then
    echo "Usage: $0 <username>"  # Inform the user of the correct usage if no argument is given.
    exit 1                      # Exit the script with an error status.
fi

# Assign the username argument to a variable for clarity.
username="$1"

# Define the path for the history log file in the history_logs directory.
folder="./history_logs"
filepath="$folder/${username}.txt"

# Create the history log file, or overwrite it if it already exists.
touch "$filepath"

# Define the path for the transactions log file in the transaction_logs directory.
folder="./transaction_logs"
filepath="$folder/${username}.txt"

# Create the transactions log file, or overwrite it if it already exists.
touch "$filepath"
