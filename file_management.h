 /* 
 * This header file defines functions related to user file management, including operations such as:
 * - Creating user history files.
 * - Retrieving and updating user information (password, budget, transactions).
 * - Managing transactions (adding and displaying).
 * - Accessing recent balance information.
 * 
 * The functions rely on Bash scripts for interacting with user files and updating or retrieving data.
 * 
 */


#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

void create_user_history_file(const char *username); 
int find_user_file(const char *username, const char *folder_name); 
void get_user_password(const char *username, char *password_buffer, size_t buffer_size);
void add_user_info_to_history_log(const char *folder_name, const char *username, const char *name, const char *password, const char *birthday, const char *email, const char *phone_number, double budget); 
void add_transaction_to_user_file(const char *folder_name, const char *username, const char *type, double amount, double *debit_balance, double *credit_balance, const char *date, const char *description); 
void get_recent_credit_balance(const char *folder_name, const char *username, double *credit_balance);
void get_recent_debit_balance(const char *folder_name, const char *username, double *debit_balance);
void get_budget_from_user_file(const char *username); 
void update_budget_file(const char *username, float *new_budget);
void display_transactions(const char *username);

#endif