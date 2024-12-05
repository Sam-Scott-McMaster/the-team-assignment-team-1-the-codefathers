/* 
* 
* This file contains functions for managing user data, transaction history, and budget updates. 
* It interacts with various Bash scripts for reading and writing data related to users' budget and transactions.
* 
*/


#include <stdio.h> 
#include <stdlib.h>  
#include <string.h> 
#include <dirent.h> 

/* 
* Function: create_user_history_file
* 
* Parameters:
*   const char *username - The username for which the history file is to be created.
*
* This function creates a user history file by calling the appropriate Bash script.
*/

void create_user_history_file(const char *username){ 
    char command[256]; 
    snprintf(command, sizeof(command), "./bash_scripts/create_history.sh %s", username);
    system(command); 
} 

/* 
* Function: find_user_file
* 
* Parameters:
*   const char *username - The username to search for.
*   const char *folder_name - The folder where the user files are stored.
* 
* Returns:
*   int - 0 if the user file is found, 1 if not.
*
* This function checks if a user exists in a given folder by calling a Bash script.
*/
int find_user_file(const char *username, const char *folder_name) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/find_user.sh %s %s", username, folder_name);
    int ret = system(command);
    return WEXITSTATUS(ret);  // Returns 0 if found, 1 if not
}

/* 
* Function: get_user_password
* 
* Parameters:
*   const char *username - The username for which to retrieve the password.
*   char *password_buffer - A buffer to store the retrieved password.
*   size_t buffer_size - The size of the buffer.
* 
* This function retrieves the stored password for the given username by calling a Bash script.
*/
void get_user_password(const char *username, char *password_buffer, size_t buffer_size) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/get_password.sh %s", username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output

    if (fgets(password_buffer, buffer_size, pipe) != NULL) {
        // Remove trailing newline character, if any
        password_buffer[strcspn(password_buffer, "\n")] = '\0';
    }

    pclose(pipe);
}

/* 
* Function: add_user_info_to_history_log
* 
* Parameters:
*   const char *folder_name - The folder name where the user data will be stored.
*   const char *username - The username for which the information is to be added.
*   const char *name - The full name of the user.
*   const char *password - The user's password.
*   const char *birthday - The user's birthday.
*   const char *email - The user's email address.
*   const char *phone_number - The user's phone number.
*   double budget - The user's budget.
* 
* This function adds user information to the history log using a Bash script.
*/
void add_user_info_to_history_log(const char *folder_name, const char *username, const char *name, const char *password, const char *birthday, const char *email, const char *phone_number, double budget) {
    // Prepare the command string to pass all the arguments to the Bash script
    char command[1024];
    snprintf(command, sizeof(command), "sh -c './bash_scripts/add_user_info.sh \"%s\" \"%s\" \"%s\" \"%s\" \"%s\" \"%s\" \"%.2f\"'", username, name, password, birthday, email, phone_number, budget);
    system(command); 
}


/* 
* Function: add_transaction_to_user_file
* 
* Parameters:
*   const char *folder_name - The folder where the user file is stored.
*   const char *username - The username associated with the transaction.
*   const char *type - The type of transaction (e.g., deposit, withdrawal).
*   double amount - The amount involved in the transaction.
*   double *debit_balance - Pointer to the user's debit balance (updated after transaction).
*   double *credit_balance - Pointer to the user's credit balance (updated after transaction).
*   const char *date - The transaction date.
*   const char *description - A description of the transaction.
* 
* This function formats and adds a transaction entry to the user's file using a Bash script.
*/
void add_transaction_to_user_file(const char *folder_name, const char *username, const char *type, double amount, double *debit_balance, double *credit_balance, const char *date, const char *description) {
    char command[512];
    snprintf(command, sizeof(command), "./bash_scripts/add_transaction.sh %s %s %s %.2f %.2f %.2f %s \"%s\"", folder_name, username, type, amount, *debit_balance, *credit_balance, date, description);
    system(command);
}

/* 
* Function: get_recent_credit_balance
* 
* Parameters:
*   const char *folder_name - The folder where the user's file is stored.
*   const char *username - The username for which to retrieve the credit balance.
*   double *credit_balance - Pointer to store the retrieved credit balance.
* 
* This function retrieves the most recent credit balance for a user from their file.
*/
void get_recent_credit_balance(const char *folder_name, const char *username, double *credit_balance) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/get_recent_credit.sh %s %s", folder_name, username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output
    fscanf(pipe, "%lf", credit_balance);  // Read the balance
    pclose(pipe);
}

/* 
* Function: get_recent_debit_balance
* 
* Parameters:
*   const char *folder_name - The folder where the user's file is stored.
*   const char *username - The username for which to retrieve the debit balance.
*   double *debit_balance - Pointer to store the retrieved debit balance.
* 
* This function retrieves the most recent debit balance for a user from their file.
*/
void get_recent_debit_balance(const char *folder_name, const char *username, double *debit_balance) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/get_recent_debit.sh %s %s", folder_name, username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output

    fscanf(pipe, "%lf", debit_balance);  // Read the balance
    pclose(pipe);
}

/* 
* Function: get_budget_from_user_file
* 
* Parameters:
*   const char *username - The username for which to retrieve the budget.
*
* This function retrieves the most recent budget for a user from their history log.
*/
void get_budget_from_user_file(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/get_budget.sh %s", username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output

    char buffer[128];
    double budget = 0.0;
    if (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        sscanf(buffer, "%lf", &budget);
        printf("Budget: %.2lf\n", budget);  // Print the budget
    }

    pclose(pipe);
    
}

/* 
* Function: update_budget_file
* 
* Parameters:
*   const char *username - The username whose budget needs to be updated.
*   float *new_budget - The new budget value to set for the user.
* 
* This function updates the user's budget in their history log using a Bash script.
*/
void update_budget_file(const char *username, float *new_budget) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/update_budget.sh %s %.2lf", username, *new_budget);
    system(command); 
}

/* 
* Function: display_transactions
* 
* Parameters:
*   const char *username - The username whose transactions are to be displayed.
*
* This function displays all transactions for the specified user by calling a Bash script.
*/
void display_transactions(const char *username){ 
    char command[256]; 
    snprintf(command, sizeof(command), "./bash_scripts/display_transactions.sh %s %s", "transaction_logs", username);
    system(command); 
}