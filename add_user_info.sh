#!/bin/bash

# Usage: ./add_user_info.sh <username> <name> <password> <birthday> <email> <phone_number> <budget>

username=$1
name=$2
password=$3
birthday=$4
email=$5
phone_number=$6
budget=$7

file_path="history_logs/${username}.txt"

# Append user information to the history log
echo "Name: $name" >> "$file_path"
echo "Password: $password" >> "$file_path"
echo "Birthday: $birthday" >> "$file_path"
echo "Email: $email" >> "$file_path"
echo "Phone Number: $phone_number" >> "$file_path"
echo "Budget: $budget" >> "$file_path"
echo "------------------------" >> "$file_path"
 