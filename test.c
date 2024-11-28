#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "user_account.h"
#include "new_account.h"
#include "debit.h"
#include "credit.h"

int main() { 
    char username[50];
    double debit_balance;
    double credit_balance;
    double credit_debt = 0.0;
    double amount;
    char date[11]; 


    printf("Welcome to the Budgeting System\n");

    // Get username and password from user
    printf("Enter your username: ");
    scanf("%s", username);


    printf("Welcome to the Budgeting System\n");
    //Display account information
    get_recent_debit_balance("transaction_logs", username, &debit_balance);
    get_recent_credit_balance("transaction_logs", username, &credit_balance);


    get_recent_debit_balance("transaction_logs", username, &debit_balance);
    get_recent_credit_balance("transaction_logs", username, &credit_balance);
    printf("Your Current Debit Balance: %.2f\n", debit_balance);
    printf("Your Current Credit Balance: %.2f\n", credit_balance);
    printf("Credit debt: %.2f\n", credit_debt);

    printf("Please Enter The Transaction Date (YYYY-MM-DD): ");
    scanf("%10s", date);

    int choice;

    printf("\nPlease select a transaction type:\n");
    printf("    1. Add Money To Debit Account\n");
    printf("    2. Spend Money From Debit Account\n");
    printf("    3. Check Debit Account Balance\n");
    printf("    4. Spend Money From Credit Account\n");
    printf("    5. Pay Off Credit Debt\n");
    printf("    6. Check Credit Account Balance\n");
    printf("    7. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Please Enter The Amount You Want To Add: ");
            scanf("%lf", &amount);
            add_to_debit(&debit_balance, amount, "transaction_logs", username, date);
            break;
        case 2:
            printf("Please Enter The Amount You Want To Spend: ");
            scanf("%lf", &amount);
            spend_money_debit(&debit_balance, amount, "transaction_logs", username, date);
            break;
        case 3:
            check_balance_debit(debit_balance);
            break;
        case 4:
            printf("Please Enter The Amount You Want To Spend: ");
            scanf("%lf", &amount);
            spend_money_credit(&credit_balance, amount, "transaction_logs", username, date, &credit_debt);
            break;
//        case 5:
//            printf("Please Enter The Amount You Want To Pay Off: ");
//           scanf("%lf", &amount);
//            pay_off_credit(&debit_balance, &credit_balance, &credit_debt, amount, "transaction_logs", username, date);
//            break;
        case 6:
            check_balance_credit(credit_balance, credit_debt);
            break;
        case 7:
            printf("Thank You For Using The Codefathers Budgeting System\n");
            break;
        default:
            printf("Invalid Option.\n");
    }

    return 0;
}