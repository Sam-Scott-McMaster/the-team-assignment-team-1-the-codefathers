#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "user_account.h"
#include "new_account.h"
#include "debit.h"
#include "credit.h"

int main() { 
    //char username[50];
    double debit_balance;
    double credit_balance;
    double credit_debt;
    double amount;
    char date[11]; 


    printf("Enter your username: ");
    scanf("%49s", username);

    create_user_history_file(username);
    char *name = check_first_name();
    strcat(name, " ");
    strcat(name, check_last_name());
    char *password = password_processing(name);
    char *username = scan_username();
    char *birthday = scan_birthday();
    char *phone_num = scan_phone();

    add_user_info_to_history_log("transaction_logs", username, name, password, birthday, username, phone_num, 0.0);

    printf("Welcome to the Budgeting System\n");
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
        case 5:
            printf("Please Enter The Amount You Want To Pay Off: ");
            scanf("%lf", &amount);
            pay_off_credit(&debit_balance, &credit_debt, amount, "transaction_logs", username, date);
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
