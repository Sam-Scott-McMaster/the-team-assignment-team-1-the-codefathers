/*Names: Nithika Karunamoorthy, Stella Liu, Rachel Nyonje, Leyla Kutlu, Fatima Alsalahi 
* Student IDs: 400511869, 400528859, 400501476, 400501110, 400508645
* Hand in date: 12/5/2024
*
* Description:
*   This file implements the main functionality for the Codefathers Budgeting System.
*   It handles user login, account creation, transaction management, and budget tracking.
*   The user can log in, create a new account, and perform various operations like adding
*   money to their debit or credit accounts, checking balances, and updating budgets.
* 
* Main Features:
* - User login and account creation.
* - Transaction management for debit and credit accounts.
* - Budget setting and tracking.
* - Transaction history display.
* - Input validation and error handling.
* - Help option via `--help`.
*
* Usage:
* - On start, users log in or create an account if they don’t have one.
* - Users can perform transactions (add/spend money, check balances) and manage their budget.
* - Help is available with the `--help` argument.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#include <time.h>
#include "file_management.h"
#include "new_account.h"
#include "debit.h"
#include "credit.h"
#include "login.h"
#include "help.h"
#include "budget.h"

/*main
*
* Parameters:
*   int argc - argument count
*   char *argv[] - argument values
* 
* Description:  
*   Main function handles user login, account creation, transaction management, and budget tracking.
*   It prompts the user to log in or create a new account, and then allows the user to interact 
*   with their account through various transaction options.
* 
* Returns: 
*   0 on success, exits with code 1 on failure.
*/
int main(int argc, char *argv[]) { 
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        help();
        return 0;
    }

    // Declare necessary variables
    //char username[50];
    double debit_balance = 0.00;
    double credit_balance = 0.00;
    double amount;
    typedef struct {
        int day;
        int month;
        int year;
    } Date;  // Date structure to hold transaction date
    Date date;
    char transactionDate[11];  // String to hold formatted transaction date (DD/MM/YYYY)
    char username[50], password[50];  // Strings to hold user login credentials
    float new_budget;         // Stores the new budget input by the user
    float budget;             // Stores the current budget
    int login_attempts = 0;   // Counter for login attempts

    // Greet the user
    printf("\n---------------------------------------\n");
    printf("\nWelcome To The Codefathers Budgeting System!\n");
    printf("\n---------------------------------------\n");

    // Get username and password from user
    printf("\nEnter Your Username: ");
    scanf("%s", username);
    printf("Enter Your Password: ");
    scanf("%s", password);

    //Attempt login
    int result = login(username, password); 

    // Allow up to 2 retries for login
    while (result == 0 && login_attempts < 2){ 
        printf("\n---------------------------------------\n");
        printf("\nEnter Your Username Again: ");
        scanf("%s", username);
        printf("Enter Your Password Again: ");
        scanf("%s", password);
            
        result = login(username, password); 
        login_attempts++;
    }

    // Exit if login fails after 3 attempts
    if (login_attempts == 2 && result == 0){
        puts("\nYou have reached the maximum number of login attempts. \nThank You For Using The Codefathers Budgeting System!");
        exit(0); 
    }

    // Handle new account creation if login returns 2
    if (result == 2){
        printf("\n---------------------------------------\n");
        printf("\nCreating New Account: \n\n");

        // Get user details for account creation 
        char *name = check_first_name();
        strcat(name, " ");
        strcat(name, check_last_name());

        char *email = check_email();
        char *user = scan_username();
        char *pass = password_processing(user);
        char *birthday = scan_birthday();
        char *phone_num = scan_phone();
        
        printf("\n---------------------------------------\n");
        printf("\nWhat Is Your Monthly Spending Budget?: ");
        scanf("%f", &budget);

        strcpy(username, user);
        create_user_history_file(user); 
        add_user_info_to_history_log("history_logs", user, name, pass, birthday, email, phone_num, budget);
    }

    if (result == 1){
        printf("\n---------------------------------------\n");
        printf("\nLogin Successful\n\n");
    } else if (result == -1){
        fprintf(stderr, "\nError: Something Went Wrong!\n\n");
        exit(1); 
    }

    //Display account balance
    void display_account_balance(const char *username); 

    // Fetch recent account balances
    get_recent_debit_balance("transaction_logs", username, &debit_balance);
    get_recent_credit_balance("transaction_logs", username, &credit_balance);
    printf("Your Current Debit Balance: %.2f\n", fabs(debit_balance));
    printf("Your Current Credit Balance: %.2f\n", fabs(credit_balance));

    // Get transaction date from user
    printf("Please Enter The Transaction Date (DD/MM/YYYY): ");
    while (scanf("%d/%d/%d", &date.day, &date.month, &date.year) != 3 || date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 1900 || date.month > 2100) {
        printf("Invalid Input. Please Enter Your Transaction Date In The Format DD/MM/YYYY: ");
        // Clearing input buffer
        while (getchar() != '\n');
    }

    // Format transaction date into string
    sprintf(transactionDate, "%02d/%02d/%d", date.day, date.month, date.year);

    // Variable to store user's choice for transaction
    int choice;
    char check;

    // Main loop to handle user transactions
    while (1) {

        // Display transaction menu
        printf("\n---------------------------------------\n");
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

        // Handle user transaction choice
        switch (choice) {
            case 1:
                printf("\n---------------------------------------\n");
                printf("\nPlease Enter The Amount You Want To Add: ");
                scanf("%lf", &amount);
                add_to_debit(&debit_balance, &credit_balance, amount, "transaction_logs", username, transactionDate);
                break;
            case 2:
                printf("\n---------------------------------------\n");
                printf("\nPlease Enter The Amount You Want To Spend: ");
                scanf("%lf", &amount);
                spend_money_debit(&debit_balance, &credit_balance, amount, "transaction_logs", username, transactionDate);
                break;
            case 3:
                printf("\n---------------------------------------\n");
                check_balance_debit(debit_balance);
                break;
            case 4:
                printf("\n---------------------------------------\n");
                printf("\nPlease Enter The Amount You Want To Spend: ");
                scanf("%lf", &amount);
                spend_money_credit(&credit_balance, &debit_balance, amount, "transaction_logs", username, transactionDate);
                break;
            case 5:
                printf("\n---------------------------------------\n");
                printf("\nPlease Enter The Amount You Want To Pay Off: ");
                scanf("%lf", &amount);
                pay_off_credit(&debit_balance, &credit_balance, amount, "transaction_logs", username, transactionDate);
                break;
            case 6:
                printf("\n---------------------------------------\n");
                check_balance_credit(credit_balance);
                break;
            case 7:
                printf("\n---------------------------------------\n\n");
                display_transactions(username);
                break;
            case 8:
                printf("\n---------------------------------------\n");
                printf("\nPlease Enter The New Budget: ");
                scanf("%f", &new_budget);
                update_budget(username, &new_budget);
                break;
            case 9:
                printf("\n---------------------------------------\n\n");
                returnBudget(username);
                break;
            default:
                printf("\n---------------------------------------\n");
                printf("\nInvalid Option.\n");
        }

        // Wait for user input to continue or exit
        while(getchar() != '\n');

        printf("\n---------------------------------------\n");        
        printf("\nEnter Y To Select Another Transaction or Press Any Other Key To Exit: ");
        scanf("%c", &check);
        if (check != 'Y' && check != 'y') {
            break;
        }
    }

    // Exit message
    printf("\n---------------------------------------\n");
    printf("\nThank You For Using The Codefathers Budgeting System!\n");
    printf("\n---------------------------------------\n");

    return 0;
}
