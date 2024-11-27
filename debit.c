#include <stdio.h>
#include <stdlib.h>
#include "debit.h"
#include "credit.h"
#include "user_account.h"

//function to add money to debit account
void add_to_debit(double *debit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    *debit_balance += amount;
    //add_transaction_to_user_file(folder_name, user_name, "Debit", amount, *debit_balance, date, "Money deposited to debit account.");
    printf("You added %.2f.\n Your new debit balance is %.2f.\n", amount, debit_balance);
}

//function to spend money with debit account
void spend_money_debit(double *debit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    if (amount <= *debit_balance) {
        *debit_balance -= amount;
        //add_transaction_to_user_file(folder_name, user_name, "Debit", amount, *debit_balance, date, "Money spent using debit.");
        printf("You added %.2f.\n Your new debit balance is %.2f.\n", amount, *debit_balance);
    } else {
        printf("Insufficient balance.\n Your current debit balance is %.2f.\n", *debit_balance);
    }
}

//function to check balance for debit card
void check_balance_debit(double debit_balance) {
    printf("Your current debit balance is %.2f.\n", debit_balance);
}

//in main.c add options to spend money or add money and ask the user to input the amount of money they would like to add or spend