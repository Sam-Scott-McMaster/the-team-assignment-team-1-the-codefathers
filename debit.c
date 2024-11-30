#include <stdio.h>
#include <stdlib.h>
#include "debit.h"
#include "credit.h"
#include "file_management.h"

//function to add money to debit account
void add_to_debit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    *debit_balance += amount;
    add_transaction_to_user_file(folder_name, username, "Debit", amount, debit_balance, credit_balance, date,"Money deposited to debit account.");
    printf("Transaction Date: %s\n", date);
    printf("You Added %.2f.\nYour New Debit Balance is %.2f.\n", amount, *debit_balance);
}

//function to spend money with debit account
void spend_money_debit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    if (amount <= *debit_balance) {
        *debit_balance -= amount;
        add_transaction_to_user_file(folder_name, username, "Debit", amount, debit_balance, credit_balance, date, "Money spent using debit.");
        printf("Transaction Date: %s\n", date);
        printf("You Spent %.2f.\nYour New Debit Balance is %.2f.\n", amount, *debit_balance);
    } else {
        printf("Insufficient Balance.\nYour Current Debit Balance is %.2f.\n", *debit_balance);
    }
}

//function to check balance for debit card
void check_balance_debit(double debit_balance) {
    printf("Your Current Debit Balance is %.2f.\n", debit_balance);
}
