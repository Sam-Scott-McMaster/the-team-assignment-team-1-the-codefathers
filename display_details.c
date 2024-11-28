#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display_details.h"
#include "budget.h"

void display_account_type(const char *account_type) {

    if (strcmp(account_type, "Both") == 0) { //compares account type
        printf("Account Type: Debit and Credit\n");
    } 
}

void display_account_balance(const char *account_type, double debit_balance, double credit_balance) {

    double debit_balance = 0.0, credit_balance = 0.0;

    get_recent_debit_balance("transaction_logs", username, &debit_balance);
    get_recent_credit_balance("transaction_logs", username, &credit_balance);

    // Print the balances
    printf("Your current debit balance: $%.2f\n", debit_balance);
    printf("Your current credit balance: $%.2f\n", credit_balance);
}

void display_personal_info(const char *name) {

    //takes user details as input and prints it
    printf("Name: %s\n", name);
}

void display_budget(double budget) {
    
    double budget = returnBudget(username);
    printf("Budget: $%.2f\n", budget);
}