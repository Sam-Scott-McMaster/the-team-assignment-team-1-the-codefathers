#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display_details.h"
#include "budget.h"

//helper function to read user data from a file
int load_user_info(const char *username, char *account_type, double *debit_balance, double *credit_balance, double *balance, char *name) {
    char filename[100]; //char array to store the filename
    sprintf(filename, "%s.txt", username); //constructs the file name by appending ".txt" to the username and stores it in filename

    //opens file with constructed filename in read mode. Returns a pointer to the file if successful
    FILE *file = fopen(filename, "r");

    if (!file) {
        //checks if file pointer is NULL
        printf("Error: Could not find user data for %s.\n", username);
        return 0;
    }

    fscanf(file, "Account Type: %s\n", account_type); //Reads account type from the file and stores it
    fscanf(file, "Debit Balance: %lf\n", debit_balance); //Reads debit balance
    fscanf(file, "Credit Balance: %lf\n", credit_balance); //Reads credit balance

    fscanf(file, "Budget: %lf\n", returnBudget(username));

    fgets(name, 100, file); //Read name from the file using fgets, removing the newline char at the end
    name[strcspn(name, "\n")] = '\0'; //Removes the newline char if it's there

    fclose(file); //closes file
    return 1; //successful
}

void display_account_type(const char *account_type) {
    if (strcmp(account_type, "Both") == 0) { //compares account type
        printf("Account Type: Debit and Credit\n");
    } 
    else {
        printf("Account Type: %s\n", account_type); //print specific account type
    }
}

void display_account_balance(const char *account_type, double debit_balance, double credit_balance) {

    if (strcmp(account_type, "Both") == 0) {
        printf("Debit Account Balance: $%.2f\n", debit_balance);
        printf("Credit Account Balance: $%.2f\n", credit_balance);
    }
    else if (strcmp(account_type, "Debit") == 0){
        printf("Debit Account Balance: $%.2f\n", debit_balance);
    }
    else if (strcmp(account_type, "Credit") == 0); {
        printf("Credit Account Balance: $%.2f\n", credit_balance);
    }
}

void display_personal_info(const char *name) {

    //takes user details as input and prints it
    printf("Name: %s\n", name);
}

void display_budget(double budget) {
    printf("Budget: $%.2f\n", budget);
}