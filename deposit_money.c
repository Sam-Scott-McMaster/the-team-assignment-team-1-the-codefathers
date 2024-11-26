#include <stdio.h>
#include <stdlib.h>
#include "deposit_money.h"

void deposit_money() {
    int accountNumber;
    char cardType[10];
    float amount;

    printf("\nEnter account number: ");
    scanf("%d, &accountNumber");

    printf("\nEnter amount to deposit: ");
    scanf("%f, &amount");

    printf("\nEnter card type (debit/credit): ");
    scanf("%s, &cardType");

    
    for (int i = 0; i < ?; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (strcmp (cardType, "debit") == 0) {
                accounts[i].debitBalance += amount;
                printf("\nAmount deposited successfully!");
                return;
                
            } else if (strcmp (cardType, "credit") == 0) {
                accounts[i].creditBalance += amount; 
                printf("\nAmount deposited successfully!");
                return;
            } else {
                printf("\nEntered card type not found");
                return;
            }
        }
    }
    
    printf("\nAccount number not found!\n")
}