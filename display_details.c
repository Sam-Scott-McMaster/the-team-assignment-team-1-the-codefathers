#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "display_details.h"
#include "budget.h"
#include "file_management.h"

void display_account_balance(const char *username) {

    double debit_balance = 0.0, credit_balance = 0.0;

    get_recent_debit_balance("transaction_logs", username, &debit_balance);
    get_recent_credit_balance("transaction_logs", username, &credit_balance);

    // Print the balances
    printf("Your current debit balance: $%.2f\n", debit_balance);
    printf("Your current credit balance: $%.2f\n", fabs(credit_balance));
}

void display_personal_info(const char *name) {

    printf("Name: %s\n", name);
}

void display_budget(char *username) {
    
    double budget = returnBudget(username);
    printf("Budget: $%.2f\n", budget);
}