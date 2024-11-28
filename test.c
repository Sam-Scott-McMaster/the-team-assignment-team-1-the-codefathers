#include <stdio.h>
#include <stdlib.h>
#include "debit.h"
#include "credit.h"

int main() {
    double debit_balance = 1000.00;
    double credit_balance = 200.00;
    double credit_debt = 0.00;
    double amount;
    char date[11]; 

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
            add_to_debit(&debit_balance, amount, "folder", "username", date);
            break;
        case 2:
            printf("Please Enter The Amount You Want To Spend: ");
            scanf("%lf", &amount);
            spend_money_debit(&debit_balance, amount, "folder", "username", date);
            break;
        case 3:
            check_balance_debit(debit_balance);
            break;
        case 4:
            printf("Please Enter The Amount You Want To Spend: ");
            scanf("%lf", &amount);
            spend_money_credit(&credit_balance, amount, "folder", "username", date, &credit_debt);
            break;
        case 5:
            printf("Please Enter The Amount You Want To Pay Off: ");
            scanf("%lf", &amount);
            pay_off_credit(&debit_balance, &credit_debt, amount, "folder", "username", date);
            break;
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