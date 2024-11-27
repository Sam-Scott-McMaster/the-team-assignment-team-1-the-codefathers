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
int find_user_file(const char *username, const char *folder_name){
    DIR *dir = opendir(folder_name); // Open the directory
    if (!dir) {
        printf("Error: Could not open directory %s\n", folder_name);
        return -1; // Indicate error
    }

    char target_filename[256];
    snprintf(target_filename, sizeof(target_filename), "%s.txt", username); // Append .txt to username

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) { // Read each entry
        if (strcmp(entry->d_name, target_filename) == 0) { // Compare with constructed target filename
            closedir(dir); // Close the directory
            return 0;      // File found
        }
    }

    closedir(dir);
    return 1; // File not found
}

// Function to append a string to the user's file
void add_info_to_user_file(const char *folder_name, const char *username, const char *info) {
    char filepath[256]; // Buffer to store the full file path
    snprintf(filepath, sizeof(filepath), "%s/%s.txt", folder_name, username); // Construct the file path

    FILE *file = fopen(filepath, "a"); 

    if (!file) { 
        printf("Error: Could not open file %s for writing.\n", filepath); 
        return; 
    }

    fprintf(file, "%s\n", info); 
    fclose(file); 
    printf("Information added to file: %s\n", filepath); 
}

// Function to format and add a transaction entry to the user's file without category
void add_transaction_to_user_file(const char *folder_name, const char *username, const char *type, float amount, const char *date, float balance, const char *description) {
    char filepath[256]; 
    snprintf(filepath, sizeof(filepath), "%s/%s.txt", folder_name, username); // Construct the file path

    FILE *file = fopen(filepath, "a"); // Open file in append mode

    if (!file) { 
        printf("Error: Could not open file %s for writing.\n", filepath); 
        return; 
    }

    // Format the transaction entry and append it to the file without the category field
    fprintf(file, "Transaction Type: %s\nAmount: %.2f\nDate: %s\nBalance: %.2f\nDescription: %s\n\n",
            type, amount, date, balance, description);
    fclose(file); 
    printf("Transaction added to file: %s\n", filepath); 
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
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "%s/%s.txt", "history_logs", username); // Construct file path

    FILE *file = fopen(filepath, "a"); // Open file in append mode

    if (!file) {
        printf("Error: Could not open file %s for writing.\n", filepath);
        return;
    }

    fprintf(file, "Budget: %.2f\n", budget); // Add budget entry
    fclose(file);
    printf("Budget of %.2f set for user: %s\n", budget, username);
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