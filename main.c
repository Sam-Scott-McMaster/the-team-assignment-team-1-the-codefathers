#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#include "file_management.h"
#include "new_account.h"
#include "debit.h"
#include "credit.h"
#include "login.h"
#include "help.h"
#include "budget.h"

int main(int argc, char *argv[]) { 
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        help();
        return 0;
    }
    //char username[50];
    double debit_balance;
    double credit_balance;
    double credit_debt;
    double amount;
    char date[11]; 
    char username[50], password[50]; 
    float new_budget;
    float budget; 
    int login_attempts = 0;

    printf("\nWelcome To The Budgeting System\n");

    // Get username and password from user
    printf("\nEnter Your Username: ");
    scanf("%s", username);
    printf("Enter Your Password: ");
    scanf("%s", password);

    int result = login(username, password); 

    while (result == 0 && login_attempts < 2){ 
        printf("\nEnter Your Username Again: ");
        scanf("%s", username);
        printf("Enter Your Password Again: ");
        scanf("%s", password);
            
        result = login(username, password); 
        login_attempts++;
    }

    if (login_attempts == 2 && result == 0){
        puts("\nYou have reached the maximum number of login attempts. \nThank You For Using The Codefathers Budgeting System!");
        exit(1);
    }

    if (result == 2){
        printf("\nCreating New Account: \n");

        //Get first and last name 
        char *name = check_first_name();
        strcat(name, " ");
        strcat(name, check_last_name());

        char *email = check_email();
        char *user = scan_username();
        char *pass = password_processing(user);
        char *birthday = scan_birthday();
        char *phone_num = scan_phone();
        
        printf("What Is Your Monthly Spending Budget?: \n");
        scanf("%f", &budget);

        strcpy(username, user);
        create_user_history_file(user); 
        add_user_info_to_history_log("history_logs", user, name, pass, birthday, email, phone_num, budget);
    }

    if (result == 1){
        printf("Login Successful\n");
    } else if (result == -1){
        fprintf(stderr, "Error: Something Went Wrong!\n");
        exit(1); 
    }

    //Display account information
    void display_account_balance(const char *username); 

    get_recent_debit_balance("transaction_logs", username, &debit_balance);
    get_recent_credit_balance("transaction_logs", username, &credit_balance);
    printf("Your Current Debit Balance: %.2f\n", fabs(debit_balance));
    printf("Your Current Credit Balance: %.2f\n", credit_balance);

//
    printf("Please Enter The Transaction Date (DD/MM/YYYY): ");
    scanf("%10s", date);


    int choice;
    char check;

    while (1) {

        printf("\nPlease Select a Transaction Type:\n");
        printf("    1. Add Money To Debit Account\n");
        printf("    2. Spend Money From Debit Account\n");
        printf("    3. Check Debit Account Balance\n");
        printf("    4. Spend Money From Credit Account\n");
        printf("    5. Pay Off Credit Debt\n");
        printf("    6. Check Credit Account Balance\n");
        printf("    7. Display Transaction History\n");
        printf("    8. Set New Budget\n");
        printf("    9. Display Budget\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please Enter The Amount You Want To Add: ");
                scanf("%lf", &amount);
                add_to_debit(&debit_balance, &credit_balance, amount, "transaction_logs", username, date);
                break;
            case 2:
                printf("Please Enter The Amount You Want To Spend: ");
                scanf("%lf", &amount);
                spend_money_debit(&debit_balance, &credit_balance, amount, "transaction_logs", username, date);
                break;
            case 3:
                check_balance_debit(debit_balance);
                break;
            case 4:
                printf("Please Enter The Amount You Want To Spend: ");
                scanf("%lf", &amount);
                spend_money_credit(&credit_balance, &debit_balance, amount, "transaction_logs", username, date);
                break;
            case 5:
                printf("Please Enter The Amount You Want To Pay Off: ");
                scanf("%lf", &amount);
                pay_off_credit(&debit_balance, &credit_balance, amount, "transaction_logs", username, date);
                break;
            case 6:
                check_balance_credit(credit_balance);
                break;
            case 7:
                display_transactions(username);
                break;
            case 8:
                printf("Please Enter The New Budget: ");
                scanf("%f", &new_budget);
                update_budget(username, &new_budget);
                break;
            case 9:
                returnBudget(username);
                break;
            default:
                printf("Invalid Option.\n");
        }

        while(getchar() != '\n');
        
        printf("\nWould You Like To Select Another Transaction? (Y/N)\n");
        scanf("%c", &check);
        if (check != 'Y' && check != 'y') {
            break;
        }
    }

    printf("\nThank You For Using The Codefathers Budgeting System!\n");

    return 0;
}
