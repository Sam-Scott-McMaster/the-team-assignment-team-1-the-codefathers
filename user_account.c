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


// Function to append a string to the user's file
void add_info_to_user_file(const char *folder_name, const char *username, const char *info) {
    char command[256];
    snprintf(command, sizeof(command), "./add_info.sh %s %s \"%s\"", folder_name, username, info);
    system(command);
}

// Function to format and add a transaction entry to the user's file without category
void add_transaction_to_user_file(const char *folder_name, const char *username, const char *type, float amount, const char *date, const char *description) {
    char command[512];
    snprintf(command, sizeof(command), "./add_transaction.sh %s %s %s %.2f %s \"%s\"", folder_name, username, type, amount, date, description);
    system(command);
}

// Function to get the most recent credit balance from the user's file
void get_recent_credit_balance(const char *folder_name, const char *username, float *credit_balance) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "%s/%s.txt", folder_name, username); // Construct the file path

    FILE *file = fopen(filepath, "r"); // Open the file in read mode

    if (!file) {
        printf("Error: Could not open file %s for reading.\n", filepath);
        return;
    }

    char line[256]; // Buffer to store each line from the file
    *credit_balance = 0.00;  // Initialize the recent credit balance

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Transaction Type: Credit") != NULL) {
            // Extract credit amount and update the recent credit balance
            if (fgets(line, sizeof(line), file)) {
                sscanf(line, "Amount: %f", credit_balance);
            }
        }
    }

    fclose(file); // Close the file
}

// Function to get the most recent debit balance from the user's file
void get_recent_debit_balance(const char *folder_name, const char *username, float *debit_balance) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "%s/%s.txt", folder_name, username); // Construct the file path

    FILE *file = fopen(filepath, "r"); // Open the file in read mode

    if (!file) {
        printf("Error: Could not open file %s for reading.\n", filepath);
        return;
    }

    char line[256]; // Buffer to store each line from the file
    *debit_balance = 0.00;  // Initialize the recent debit balance

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Transaction Type: Debit") != NULL) {
            // Extract debit amount and update the recent debit balance
            if (fgets(line, sizeof(line), file)) {
                sscanf(line, "Amount: %f", debit_balance);
            }
        }
    }

    fclose(file); // Close the file
}

// Function to set a budget in the user's history log
void set_budget_to_user_file(const char *username, double budget) {
    char command[256];
    snprintf(command, sizeof(command), "./set_budget.sh %s %.2f", username, budget);
    system(command);
}

// Function to retrieve the most recent budget from the user's history log
double get_budget_from_user_file(const char *username) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "%s/%s.txt", "history_logs", username); // Construct file path

    FILE *file = fopen(filepath, "r"); // Open file in read mode

    if (!file) {
        printf("Error: Could not open file %s for reading.\n", filepath);
        return 0.0;
    }

    char line[256];
    double budget = 0.0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Budget:") != NULL) {
            sscanf(line, "Budget: %lf", &budget); // Extract the budget value
        }
    }

    fclose(file);
    return budget;
}

// Function to update the budget in the user's history log
void update_budget(const char *username, double new_budget) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "%s/%s.txt", "history_logs", username); // Construct file path

    FILE *file = fopen(filepath, "r"); // Open file in read mode

    if (!file) {
        printf("Error: Could not open file %s for reading.\n", filepath);
        return;
    }

    char temp_filepath[256];
    snprintf(temp_filepath, sizeof(temp_filepath), "%s/temp.txt", "history_logs"); // Temporary file for modifications

    FILE *temp_file = fopen(temp_filepath, "w");
    if (!temp_file) {
        printf("Error: Could not open temporary file for writing.\n");
        fclose(file);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Budget:") != NULL) {
            fprintf(temp_file, "Budget: %.2f\n", new_budget); // Write updated budget
        } else {
            fprintf(temp_file, "%s", line); // Copy unchanged lines
        }
    }

    fclose(file);
    fclose(temp_file);

    // Replace the original file with the updated file
    remove(filepath);
    rename(temp_filepath, filepath);

    printf("Budget updated to %.2f for user: %s\n", new_budget, username);
}