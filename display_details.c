#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "display_details.h"
#include "budget.h"
#include "file_management.h"

/*This file contains functions for displaying account details in a student banking application. These include showing the current debit and credit balances, personal information, and the user's budget. The program integrates with external modules such as display_details.h, budget.h, and file_management.h to fetch and display relevant information securely and accurately.*/

//Displays the user's current debit and credit balances
void display_account_balance(const char *username) {

    double debit_balance = 0.0, credit_balance = 0.0;

    //retrieves the most recent balance
    get_recent_debit_balance("transaction_logs", username, &debit_balance);
    get_recent_credit_balance("transaction_logs", username, &credit_balance);

    // Print the balances
    printf("Your current debit balance: $%.2f\n", debit_balance);
    printf("Your current credit balance: $%.2f\n", fabs(credit_balance)); //use fabs to ensure the credit balance is displayed as positive
}