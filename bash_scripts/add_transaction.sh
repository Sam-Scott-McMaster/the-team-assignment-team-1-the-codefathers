#!/bin/bash
if [ $# -ne 7 ]; then
    echo "Usage: $0 <folder> <username> <type> <amount> <remaining_budget> <date> <description>"
    exit 1
fi

folder="$1"
username="$2"
type="$3"
amount="$4"
budget_remaining="$5"
date="$6"
description="$7"
file_path="$folder/${username}.txt"

echo -e "Transaction Type: $type\nAmount: $amount\nRemaining Budget: $budget_remaining\nDate: $date\nDescription: $description\n" >> "$file_path"
