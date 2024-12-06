/*
 * Author: Leyla Kutlu
 * Student IDs: 400501110
 * Hand In Date: 05/12/2024
 * 
 * Description:
 * Contains functions to handle transactions related to credit and debit balance.
 * 
 * Main Features: 
 *  - spending money with a debit card
 *  - add money to the debit account
 *  - checking debit card balance
 * 
 * Usage:
 * Each function can be called individually to validate or process a specific user account field, 
 * with memory management handled through dynamic allocations.
 */

#include <stdio.h>
#include <stdlib.h>
#include "debit.h"
#include "credit.h"
#include "file_management.h"

/* add_to_debit
 * 
 * Parameters:
 *  - credit_balance: pointer to user's current credit balance
 *  - debit_balance: pointer to the user's current debit balance
 *  - amount: the amount to be spent using the credit account
 *  - folder_name: the folder where the user's transaction records are stored
 *  - username: the user's username for transaction record
 *  - date: the date of the transaction
 *
 * Description:
 * Allows user to add money to their debit account.
 * A transaction record is added to the user's file.
 * 
 * Return values:
 *  - None
 */
void add_to_debit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    *debit_balance += amount;
    add_transaction_to_user_file(folder_name, username, "Debit", amount, debit_balance, credit_balance, date,"Money Deposited To Debit Account.");
    printf("Transaction Date: %s\n", date);
    printf("You Added %.2f.\nYour New Debit Balance is %.2f.\n", amount, *debit_balance);
}

/* spend_money_debit
 * 
 * Parameters:
 *  - credit_balance: pointer to user's current credit balance
 *  - debit_balance: pointer to the user's current debit balance
 *  - amount: the amount to be spent using the credit account
 *  - folder_name: the folder where the user's transaction records are stored
 *  - username: the user's username for transaction record
 *  - date: the date of the transaction
 *
 * Description:
 * Allows user to spend money using their debit account.
 * If the amount is less than the debit balance, the debit balance is reduced.
 * A transaction record is added to the user's file.
 * If the amount is greater than the debit balance, a corresponding message is displayed.
 * 
 * Return values:
 *  - None
 */
void spend_money_debit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    if (amount <= *debit_balance) {
        *debit_balance -= amount;
        add_transaction_to_user_file(folder_name, username, "Debit", amount, debit_balance, credit_balance, date, "Money Spent Using Debit.");
        printf("Transaction Date: %s\n", date);
        printf("You Spent %.2f.\nYour New Debit Balance is %.2f.\n", amount, *debit_balance);
    } else {
        printf("Insufficient Balance.\nYour Current Debit Balance is %.2f.\n", *debit_balance);
    }
}

/* check_balance_credit
 * 
 * Parameters:
 *  - debit_balance: pointer to user's current debit balance
 *
 * Description:
 * Allows user to display their debit balance.
 * 
 * Return values:
 *  - None
 */
void check_balance_debit(double debit_balance) {
    printf("\nYour Current Debit Balance is %.2f.\n", debit_balance);
}
