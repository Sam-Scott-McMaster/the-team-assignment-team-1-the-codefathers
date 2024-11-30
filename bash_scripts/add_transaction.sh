#!/bin/bash
if [ $# -ne 8 ]; then
    echo "Usage: $0 <folder> <username> <type> <amount> <debit_balance> <credit_balance> <date> <description>"
    exit 1
fi

folder="$1"
username="$2"
type="$3"
amount="$4"
debit_balance="$5"
credit_balance="$6"
date="$7"
description="$8"
file_path="$folder/${username}.txt"
 
echo -e "Transaction Type: $type\nDebit Balance: $debit_balance\nCredit Balance: $credit_balance\nAmount: $amount\nDate: $date\nDescription: $description\n" >> "$file_path"
