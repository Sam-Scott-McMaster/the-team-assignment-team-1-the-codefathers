/*
 * Author: Leyla Kutlu
 * Student IDs: 400501110
 * Hand In Date: 12/5/2024
 * 
 * Description:
 * Contains functions to handle transactions related to credit and debit balance.
 * 
 * Main Features: 
 *  - spending money with a credit card
 *  - paying off the credit balance with a debit card
 *  - checking credit card balance
 * 
 * Usage:
 * Each function can be called individually to validate or process a specific user account field, 
 * with memory management handled through dynamic allocations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "credit.h"
#include "debit.h"
#include "file_management.h"

/* spend_money_credit
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
 * Allows user to spend money using their credit account.
 * The credit limit is 1000 cad as this is a simple budgeting system which target audience is student.
 * If the user did not exceed their credit limit, the credit balance is updated accordingly.
 * A transaction record is added to the user's file.
 * If the credit limit is reached, a corresponding message is displayed.
 * 
 * Return values:
 *  - None
 */
void spend_money_credit(double *credit_balance, double *debit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    printf("Your Credit Limit is 1000.00\n");
    if (*credit_balance <= 1000.00) {
        *credit_balance += amount;
        add_transaction_to_user_file(folder_name, username, "Credit", amount, debit_balance, credit_balance, date, "Money Spent With Credit.");
        //add budget
        printf("Transaction Date: %s\n", date);
        printf("You Spent %.2f.\nYour New Credit Balance is %.2f.\n", amount, *credit_balance);
        //printf budget
    } else {
        add_transaction_to_user_file(folder_name, username, "Credit", amount, debit_balance, credit_balance, date, "Credit Limit Reached.");
        printf("Transaction Date: %s\n", date);
        printf("You Spent %.2f.\nYou Reached Your Credit Limit", amount);
    }
}

/* pay_off_credit
 * 
 * Parameters:
 *  - credit_balance: pointer to user's current credit balance
 *  - debit_balance: pointer to the user's current debit balance
 *  - amount: the amount to be pay off the credit balance using the debit account
 *  - folder_name: the folder where the user's transaction records are stored
 *  - username: the user's username for transaction record
 *  - date: the date of the transaction
 *
 * Description:
 * Allows user to pay off their credit balance.
 * If the user has sufficient funds in their debit account, the credit balance reduced.
 * A transaction record is added to the user's file.
 * If the cdebit balance is insufficient or other conditions are met, a corresponding message is displayed.
 * 
 * Return values:
 *  - None
 */
void pay_off_credit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    if (amount <= *debit_balance) {
        if (*credit_balance == 0) {
            printf("No Credit Balance To Pay\n");
            printf("Transaction Date: %s\n", date);
            printf("Credit Balance Paid Off is 0.00.\nYour New Debit Balance is %.2f.\nYour Remaining Credit Balance is %.2f.\n", *debit_balance, *credit_balance);
        } else if (*credit_balance < amount) {
            printf("Amount You Want To Pay Off is Greater Than The Credit Balance To Pay\n");
            printf("Transaction Date: %s\n", date);
            printf("Credit Balance Paid Off is 0.00.\nYour Debit Balance is %.2f.\nYour Credit Balance is %.2f.\n", *debit_balance, *credit_balance);
        } else {
            *debit_balance -= amount;
            *credit_balance -= amount;
            printf("Transaction Date: %s\n", date);
            printf("Credit Debt Paid Off is %.2f.\nYour New Debit Balance is %.2f.\nYour Credit Balance is %.2f.\n", amount, *debit_balance, *credit_balance);
        }
        add_transaction_to_user_file(folder_name, username, "Credit", amount, debit_balance, credit_balance, date, "Paid off Credit Balance.");
    } else {
        printf("Insufficient Debit Balance.\nYour Current Debit Balance is %.2f\n", *debit_balance);
    } 
}

/* check_balance_credit
 * 
 * Parameters:
 *  - credit_balance: pointer to user's current credit balance
 *
 * Description:
 * Allows user to display their credit balance.
 * If the balance is negative, the absolute is displayed
 * 
 * Return values:
 *  - None
 */
void check_balance_credit(double credit_balance) {
    printf("\nYour Current Credit Balance is %.2f.\n", fabs(credit_balance));
}
