#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "credit.h"
#include "debit.h"
#include "user_account.h"

//function to spend money with credit account
void spend_money_credit(double *credit_balance, double amount, const char *folder_name, const char *username, const char *date, double *credit_debt) {
    if (amount <= *credit_balance) {
        *credit_balance -= amount;
        *credit_debt += amount;
        add_transaction_to_user_file(folder_name, username, "Credit", amount, date, *credit_balance, "Money spent with credit.");
        printf("Transaction Date: %s\n", date);
        printf("You Spent %.2f.\nYour New Credit Balance is %.2f.\nYour New Credit Debt is %.2f.\n", amount, *credit_balance, *credit_debt);
    } else {
        double exceed_credit_balance = amount - *credit_balance;
        *credit_debt += exceed_credit_balance;
        *credit_balance = 0;
        add_transaction_to_user_file(folder_name, username, "Credit", amount, date, *credit_balance, "Credit balance exceeded/Credit debt increased.");
        printf("Transaction Date: %s\n", date);
        printf("You Spent %.2f.\nYou Exceeded Your Credit Balance by %.2f.\n Your New Credit Debt is %.2f.\n", amount, exceed_credit_balance, *credit_debt);
    }
}

/*
//function to pay off credit card debt with debit card
void pay_off_credit(double *debit_balance, double *credit_balance, double *credit_debt, double amount, const char *folder_name, const char *username, const char *date) {
    if (amount <= *debit_balance) {
        *debit_balance -= amount;
        *credit_debt -= amount;
        if (*credit_debt < 0) {
            *credit_debt = 0;
        }
        add_transaction_to_user_file(folder_name, username, "Credit", amount, date, *credit_balance, "Paid off credit debt.");
        printf("Transaction Date: %s\n", date);
        printf("Credit Debt Paid Off is %.2f.\nYour New Debit Balance is %.2f.\nYour Remaining Credit Debt is %.2f.\n", amount, *debit_balance, *credit_debt);
    } else {
        printf("Insufficient Debit Balance.\nYour Current Debit Balance is %.2f.\n", *debit_balance);
    }
}
*/

//function to check balance for credit card
void check_balance_credit(double credit_balance, double credit_debt) {
    printf("Your Current Credit Balance is %.2f.\n", fabs(credit_balance));
    printf("Your Remaining Credit Debt is %.2f.\n", credit_debt);
}