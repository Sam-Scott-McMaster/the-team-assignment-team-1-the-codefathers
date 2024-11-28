#include <stdio.h> 
#include <stdlib.h>  
#include <string.h> 
#include <dirent.h> 

// Function to create user history file 
void create_user_history_file(const char *username){ 
    char command[256]; 
    snprintf(command, sizeof(command), "./create_history.sh %s", username);
    int ret = system(command); 
    printf("History & Transaction file created for user: %s\n", username);
} 

// Function to find if a user exists in a given folder
int find_user_file(const char *username, const char *folder_name) {
    char command[256];
    snprintf(command, sizeof(command), "./find_user.sh %s %s", username, folder_name);
    int ret = system(command);
    return WEXITSTATUS(ret);  // Returns 0 if found, 1 if not
}

// Function to add user information to the history log using a Bash script
void add_user_info_to_history_log(const char *folder_name, const char *username, const char *name, const char *password, const char *birthday, const char *email, const char *phone_number, double budget) {
    // Prepare the command string to pass all the arguments to the Bash script
    char command[1024];
    snprintf(command, sizeof(command), "./add_user_info.sh %s %s %s %s %s %s %.2f", 
             username, name, password, birthday, email, phone_number, budget);

    // Execute the command
    int ret = system(command);
    if (ret == 0) {
        printf("User information added successfully to the history log for user: %s\n", username);
    } else {
        printf("Error: Could not add user information to history log.\n");
    }
}

// Function to format and add a transaction entry to the user's file without category
void add_transaction_to_user_file(const char *folder_name, const char *username, const char *type, float amount, const char *date, const char *description) {
    char command[512];
    snprintf(command, sizeof(command), "./add_transaction.sh %s %s %s %.2f %s \"%s\"", folder_name, username, type, amount, date, description);
    system(command);
}

// Function to get the most recent credit balance from the user's file
void get_recent_credit_balance(const char *folder_name, const char *username, float *credit_balance) {
    char command[256];
    snprintf(command, sizeof(command), "./get_recent_credit.sh %s %s", folder_name, username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output
    if (!pipe) {
        printf("Error: Could not retrieve credit balance.\n");
        return;
    }

    fscanf(pipe, "%f", credit_balance);  // Read the balance
    pclose(pipe);
}


// Function to get the most recent debit balance from the user's file
void get_recent_debit_balance(const char *folder_name, const char *username, float *debit_balance) {
    char command[256];
    snprintf(command, sizeof(command), "./get_recent_debit.sh %s %s", folder_name, username);

    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output
    if (!pipe) {
        printf("Error: Could not retrieve debit balance.\n");
        return;
    }

    fscanf(pipe, "%f", debit_balance);  // Read the balance
    pclose(pipe);
}

// Function to retrieve the most recent budget from the user's history log
double get_budget_from_user_file(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "./get_budget.sh %s", username);

    double budget = 0.0;
    FILE *pipe = popen(command, "r");  // Open a pipe to read the script output
    if (!pipe) {
        printf("Error: Could not retrieve budget.\n");
        return budget;
    }

    fscanf(pipe, "%lf", &budget);  // Read the budget value
    pclose(pipe);

    return budget;
}

// Function to update the budget in the user's history log
void update_budget(const char *username, double new_budget) {
    char command[256];
    snprintf(command, sizeof(command), "./update_budget.sh %s %.2lf", username, new_budget);

    int ret = system(command);
    if (ret == -1) {
        printf("Error: Could not update budget.\n");
    } else {
        printf("Budget updated successfully for user: %s.\n", username);
    }
}