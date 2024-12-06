/* 
 * Authors: Stella Liu and Rachel Nyonje
 * Student Numbers: 400528859 and 400501476
 * Date Handed In: 05/12/2024
 * 
 * 
 * This header file contains function declarations related to user input validation and account creation processes, operations include:
 * - validating first and last names, emails, birthdays, usernames, and phone numbers according to specific patterns or rules. 
 * - ensuring password strength requirements are met and provides functionality for password encryption using a username-based 
 * 
 */ 

#ifndef NEW_ACCOUNT_H
#define NEW_ACCOUNT_H

char *scan_birthday();
char *scan_username();
char *check_first_name();
char *check_last_name();
char *check_email();
char *scan_phone();
char *password_encryption(const char *, const char*);
char *password_processing(char *);

#endif