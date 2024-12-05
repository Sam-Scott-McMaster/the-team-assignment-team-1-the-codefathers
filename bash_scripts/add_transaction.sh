#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script appends a transaction record to a user's file in a specified folder.
# It takes eight arguments: folder path, username, transaction type, amount, debit balance,
# credit balance, date, and description.
# The script checks for correct usage and appends the formatted transaction details to the file.

# Check if exactly eight arguments are provided.
# If not, display usage instructions and exit with an error code.

if [ $# -ne 8 ]; then
    echo "Usage: $0 <folder> <username> <type> <amount> <debit_balance> <credit_balance> <date> <description>"
    exit 1  # Exit with status 1 to indicate an error.
fi

# Assign command-line arguments to descriptive variables for readability.
folder="$1"           
username="$2"         
type="$3"             
amount="$4"           
debit_balance="$5"    
credit_balance="$6"   
date="$7"             
description="$8"      
file_path="$folder/${username}.txt"  # Construct the full path to the user's file.

# Append the transaction details to the user's file, formatted with line breaks.
echo -e "Transaction Type: $type\nDebit Balance: $debit_balance\nCredit Balance: $credit_balance\nAmount: $amount\nDate: $date\nDescription: $description\n" >> "$file_path"
