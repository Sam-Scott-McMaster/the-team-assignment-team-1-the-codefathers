#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "file_management.h"
#include "new_account.h"

/*This file contains a C program for login functionality in a student banking app. It verifies usernames, validates credentials, and handles user actions like re-entering usernames or creating accounts. The program uses login.h, file_management.h, and new_account.h for secure data handling, including password encryption, guiding users through appropriate login steps.*/

//Checks if the provided username exists in the system
int check_username(const char *username) {
    
    //Checks if the user file exists in "history_logs"
    if (find_user_file(username, "history_logs") != 0) {
        int choice;
        printf("\n---------------------------------------\n\n");
        printf("Username Not Found. What Would You Like To Do?\n");
        printf("1. Re-enter The Username\n");
        printf("2. Create a New Account\n");
        scanf("%d", &choice);

        //Handle user choices based on input
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

//Verifies that the crdentials file for the given username exists
int check_credentials(const char *username) {
    //checks if file is in the files
    if (find_user_file(username, "history_logs") != 0) {
        printf("Error: Credentials File For User '%s' Not Found.\n", username);
        return 0; 
    }
    return 1; //file not found
}


//Handles the user login process by checking the username, verifying the password and managing cases like incorrect credentials or missing accounts
int login(char *username, const char *password) {

    char *stored_password = malloc(1000); //Allocating memory for storing the password

    //check if the username exists and handles user actions
    int result = check_username(username);
    if (result == 0 || result == 2 || result == -1) {
        return result;
    }

    //Encrypted the provided password for comparison
    char *hashed_password = password_encryption(username, password);

    //Retrieved the stored password from the system
    get_user_password(username, stored_password, 1000);

    //Verify the credentials if the file exists
    if (check_credentials(username)) {
        if (strcmp(stored_password, hashed_password) == 0) {
            return 1; // successful login
        }
        else {
            printf("Invalid Password, Try Again.\n");
            return 0; //failed login
        }
    }
    else {
        printf("Account Not Found. Please Create a New Account.\n");
        return 2; //create new account
    }
}