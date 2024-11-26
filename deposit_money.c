#include <stdio.h>
#include <stdlib.h>
#include "deposit_money.h"

void deposit_money() {
    char response;
    int accountNumber;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d, &accountNumber");

    printf("\nEnter amount to deposit: ");
    scanf("%f, &amount");

    printf("\nEnter the account type that you would like to deposit money (Debit/Credit): ");
    scanf("%c, &response");

    //open user account and see if it is null
    //if null return error

    for (int i = 0; i < account_num; i++) {
        if (accounts[i].accountNumber == accountNumber)
        if (response == "Debit" || response == "D") {
            //consider the distinction between debit and credit
            account.balance += amount;
            printf("\nAmount deposited successfully!")
            
        } else if (response == "Credit" || response == "C") {
            //consider the distinction between debit and credit
            account.balance += amount; 
            printf("\nAmount deposited successfully!");

        }
    }
        printf("\nAccount not found!\n")
}