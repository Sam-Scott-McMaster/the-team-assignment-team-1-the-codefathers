#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "file_management.h"
#include "new_account.h"

//ask if the user already has an account
int check_username(const char *username) {
    
    if (find_user_file(username, "history_logs") != 0) {
        int choice;
        printf("\n---------------------------------------\n\n");
        printf("Username Not Found. What Would You Like To Do?\n");
        printf("1. Re-enter The Username\n");
        printf("2. Create a New Account\n");
        scanf("%d", &choice);

        if (choice == 1) {
            return 0; //indicates that username needs to be re-entered
        }
        else if (choice == 2) {
            return 2; //indicates that user wants to create a new account
        }
        else {
            printf("Invalid Choice. Please Try Again.\n");
            return -1; //invalid choice; retry
        }
    }

    return 1; //if the file exists, proceed with login

}

int check_credentials(const char *username) {
    //checks if file is in the files
    if (find_user_file(username, "history_logs") != 0) {
        printf("Error: Credentials File For User '%s' Not Found.\n", username);
        return 0; 
    }
    return 1;
}


//log in the user (takes username and password as input)
int login(char *username, const char *password) {

    char *stored_password = malloc(1000);

    int result = check_username(username);
    if (result == 0 || result == 2 || result == -1) {
        return result;
    }
    char *hashed_password = password_encryption(username, password);
    get_user_password(username, stored_password, 1000);

    if (check_credentials(username)) {
        if (strcmp(stored_password, hashed_password) == 0) {
            return 1; // successful login
        }
        else {
            printf("Invalid Password, Try Again.\n");
            return 0;
        }
    }
    else {
        printf("Account Not Found. Please Create a New Account.\n");
        return 2;
    }
}