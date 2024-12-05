#!/bin/bash
# Nithika Karunamoorthy, Student ID: 400511869, Date: 05/12/2024
#
# This script appends user information to a history log file in a predefined directory.
# It takes seven arguments: username, name, password, birthday, email, phone number, and budget.
# The script creates or updates the user's history log with the provided details.

# Assign command-line arguments to descriptive variables for clarity.
username=$1        
name=$2            
password=$3        
birthday=$4        
email=$5           
phone_number=$6    
budget=$7          

# Define the path to the history log file for the specified user.
file_path="history_logs/${username}.txt"

# Append the user's information to the history log file.
echo "Name: $name" >> "$file_path"
echo "Password: $password" >> "$file_path"
echo "Birthday: $birthday" >> "$file_path"
echo "Email: $email" >> "$file_path"
echo "Phone Number: $phone_number" >> "$file_path"
echo "Budget: $budget" >> "$file_path"
echo "------------------------" >> "$file_path"  # Add a separator for readability.
