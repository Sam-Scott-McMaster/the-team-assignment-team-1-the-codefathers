#include <stdio.h> 
#include <stdlib.h>  
#include <string.h> 
#include <dirent.h> 

// Function to create user history file 
void create_user_history_file(const char *username){ 
    char command[256]; 
    snprintf(command, sizeof(command), "./bash_scripts/create_history.sh %s", username);
    system(command); 
} 

// Function to find if a user exists in a given folder
int find_user_file(const char *username, const char *folder_name) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/find_user.sh %s %s", username, folder_name);
    int ret = system(command);
    return WEXITSTATUS(ret);  // Returns 0 if found, 1 if not
}

// Function to get the stored password for a user
void get_user_password(const char *username, char *password_buffer, size_t buffer_size) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/get_password.sh %s", username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output
    if (!pipe) {
        printf("Error: Could not retrieve password for user: %s\n", username);
        return;
    }

    if (fgets(password_buffer, buffer_size, pipe) != NULL) {
        // Remove trailing newline character, if any
        password_buffer[strcspn(password_buffer, "\n")] = '\0';
    } else {
        printf("Error: No password retrieved for user: %s\n", username);
    }

    pclose(pipe);
}

// Function to add user information to the history log using a Bash script
void add_user_info_to_history_log(const char *folder_name, const char *username, const char *name, const char *password, const char *birthday, const char *email, const char *phone_number, double budget) {
    // Prepare the command string to pass all the arguments to the Bash script
    char command[1024];
    
    snprintf(command, sizeof(command), 
             "sh -c './bash_scripts/add_user_info.sh \"%s\" \"%s\" \"%s\" \"%s\" \"%s\" \"%s\" \"%.2f\"'", 
             username, name, password, birthday, email, phone_number, budget);

    system(command); 
}


// Function to format and add a transaction entry to the user's file without category
void add_transaction_to_user_file(const char *folder_name, const char *username, const char *type, double amount, double *debit_balance, double *credit_balance, const char *date, const char *description) {
    char command[512];
    snprintf(command, sizeof(command), "./bash_scripts/add_transaction.sh %s %s %s %.2f %.2f %.2f %s \"%s\"", folder_name, username, type, amount, *debit_balance, *credit_balance, date, description);
    system(command);
}

// Function to get the most recent credit balance from the user's file
void get_recent_credit_balance(const char *folder_name, const char *username, double *credit_balance) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/get_recent_credit.sh %s %s", folder_name, username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output
    if (!pipe) {
        printf("Error: Could not retrieve credit balance.\n");
        return;
    }

    fscanf(pipe, "%lf", credit_balance);  // Read the balance
    pclose(pipe);
}

// Function to get the most recent debit balance from the user's file
void get_recent_debit_balance(const char *folder_name, const char *username, double *debit_balance) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/get_recent_debit.sh %s %s", folder_name, username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output
    if (!pipe) {
        printf("Error: Could not retrieve debit balance.\n");
        return;
    }

    fscanf(pipe, "%lf", debit_balance);  // Read the balance
    pclose(pipe);
}

// Function to retrieve the most recent budget from the user's history log
void get_budget_from_user_file(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/get_budget.sh %s", username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output
    if (!pipe) {
        printf("Error: Could not retrieve budget.\n");
        return;
    }

    char buffer[128];
    double budget = 0.0;
    if (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        sscanf(buffer, "%lf", &budget);
        printf("Budget: %.2lf\n", budget);  // Print the budget
    } else {
        printf("Error reading budget.\n");
    }

    pclose(pipe);
    
}

// Function to update the budget in the user's history log
void update_budget_file(const char *username, float *new_budget) {
    char command[256];
    snprintf(command, sizeof(command), "./bash_scripts/update_budget.sh %s %.2lf", username, *new_budget);
    system(command); 
}

void display_transactions(const char *username){ 
    char command[256]; 
    snprintf(command, sizeof(command), "./bash_scripts/display_transactions.sh %s %s", "transaction_logs", username);
    system(command); 
}