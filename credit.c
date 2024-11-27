#include <stdio.h>
#include <stdlib.h>
#include "credit.h"
#include "debit.h"
#include "user_account.h"

//function to spend money with credit account
void spend_money_credit(double *credit_balance, double amount, const char *folder_name, const char *username, const char *date) {
    if (amount <= *credit_balance) {
        *credit_balance -= amount;
        *credit_debt += amount;
        //add_transaction_to_user_file(folder_name, user_name, "Credit", amount, *credit_balance, date, "Money spent with credit.");
        printf("You spent %.2f.\n Your new credit balance is %.2f.\n Your new credit debt is %.2f.\n", amount, *credit_balance, *credit_debt);
    } else {
        double exceed_credit_balance = amount - *credit_balance;
        *credit_debt += exceed_credit_balance;
        *credit_balance = 0;
        //add_transaction_to_user_file(folder_name, user_name, "Credit", amount, *credit_balance, date, "Credit balance exceeded/Credit debt increased.");
        printf("You spent %.2f.\n You exceeded your credit balance by %.2f.\n Your new credit debt is %.2f.\n", amount, exceed_credit_balance, *credit_debt);
    }
}

//function to pay off credit card debt with debit card
void pay_off_credit(double *debit_balance, double *credit_debt, double amount, const char *folder_name, const char *username, const char *date) {
    if (amount <= *debit_balance) {
        *debit_balance -= amount;
        *credit_debt -= amount;
        if (*credit_debt < 0) {
            *credit_debt = 0;
        }
        //add_transaction_to_user_file(folder_name, user_name, "Credit", amount, *credit_balance, date, "Paid off credit debt.");
        printf("Credit debt paid off is %.2f.\n Your new debit balance is %.2f.\n Your remaining credit debt is %.2f.\n", amount, *debit_balance, *credit_debt);
    } else {
        printf("Insufficient debit balance.\n Your current debit balance is %.2f.\n", *debit_balance);
    }
}

//function to check balance for credit card
void check_balance_credit(double credit_balance, double credit_debt) {
    printf("Your current credit balance is %.2f.\n", credit_balance);
    printf("Your remaining credit debt is %.2f.\n", credit_debt);
}