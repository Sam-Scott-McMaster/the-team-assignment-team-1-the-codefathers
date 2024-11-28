#include <stdio.h> 
#include <stdlib.h> 
#include "user_account.h"
#include "new_account.h"
#include "debit.h"
#include "credit.h"

int main() { 
    //char username[50]; 
    //double debit_balance
    //double credit_balance
    //double credit_debt
    //double amount

    //printf("Enter your username: ");
    //scanf("%49s", username);

    //create_user_history_file(username);
    char *username = scan_username();
    char *phone_num = scan_phone();
    char *birthday = scan_birthday();

    //add options for transaction
    //int choice;

    return 0;
}
