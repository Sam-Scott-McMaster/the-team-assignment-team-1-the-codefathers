/*
 * Author: Fatima Alsalahi
 * Student IDs: 400508645
 * Hand In Date: 05/12/2024
 * 
 * Description:
 * Contains functions to display user account details in a student banking application.
 * Displays current debit and credit balances
 * Integrates with external modules such as display_details.h, and file_management.h 
 * to fetch and display relevant account information securely and accurately.
 * 
 * Main Features:
 *  - Displaying current debit and credit balances.
 * 
 * Usage:
 * Each function fetches relevant information from external modules and displays it for the user.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "display_details.h"
#include "budget.h"
#include "file_management.h"


/* display_account_balance
 * 
 * Parameters:
 *  - username: the username of the account for which balances are to be displayed
 *  - credit_balance: pointer to store the user's current credit balance
 *  - debit_balance: pointer to store the user's current debit balance
 *
 * Description:
 * Retrieves and displays the current debit and credit balances for a given user.
 * The balances are fetched from the "transaction_logs" file.
 * The credit balance is displayed as a positive value using `fabs` to ensure it is presented as an absolute value.
 * 
 * Return values:
 *  - None
 */
void display_account_balance(const char *username, double *credit_balance, double *debit_balance) {

    //retrieves the most recent balance
    get_recent_debit_balance("transaction_logs", username, debit_balance);
    get_recent_credit_balance("transaction_logs", username, credit_balance);

    // Print the balances
    printf("Your Current Debit Balance: %.2f\n", fabs(*debit_balance));
    printf("Your Current Credit Balance: %.2f\n", fabs(*credit_balance)); //use fabs to ensure the credit balance is displayed as positive
}