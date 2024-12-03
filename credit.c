#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "credit.h"
#include "debit.h"
#include "file_management.h"

//function to spend money with credit account
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

//function to pay off credit card balance with debit card
void pay_off_credit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    if (amount <= *debit_balance) {
        if (*credit_balance == 0) {
            printf("No Credit Balance To Pay\n");
            printf("Transaction Date: %s\n", date);
            printf("Credit Balance Paid Off is 0.00.\nYour New Debit Balance is %.2f.\nYour Remaining Credit Balance is %.2f.\n", *debit_balance, *credit_balance);
        } else {
            *debit_balance -= amount;
            *credit_balance -= amount;
            printf("Transaction Date: %s\n", date);
            printf("Credit Debt Paid Off is %.2f.\nYour New Debit Balance is %.2f.\nYour Credit Balance is %.2f.\n", amount, *debit_balance, *credit_balance);
        }
        add_transaction_to_user_file(folder_name, username, "Credit", amount, debit_balance, credit_balance, date, "Paid off Credit Balance.");
    } else {
        printf("Insufficient Debit Balance.\nYour Current Debit Balance is %.2f.\n", *debit_balance);
    }
}


//function to check balance for credit card
void check_balance_credit(double credit_balance) {
    printf("\nYour Current Credit Balance is %.2f.\n", credit_balance);
}
