/*
* Author: Fatima Alsalahi
* Student IDs: 400508645
* Hand in Date: 05/12/2024
*
* Description: This file contains a C program for login functionality in * a student banking app. It verifies usernames, validates credentials, 
* and handles user actions like re-entering usernames or creating 
* accounts. The program uses login.h, file_management.h, and new_account.* h for secure data handling, including password encryption, guiding 
* users through appropriate login steps.
* 
* Usage: Each function can be used individually to verify or process 
* specific login-related taskes, ensuring secure and user friendly 
* account management.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "file_management.h"
#include "new_account.h"


/* spend_money_credit
 * 
 * Parameters:
 *  - username: th username to check in the system
 *
 * Description:
 * Checks if the provided username exists in the system.
 * If the username is not found, it prompts the user to either re-enter the username or create a new account.
 * Based on user input, it returns a code indicating whether the username needs to be re-entered, a new account should be created, or an invalid choice was made..
 * 
 * Return values:
 *  - 0: Username needs to be re-entered.
 *  - 2: User wants to create a new account.
 *  - -1: Invalid choice; retry.
 *  - 1: Username exists, proceed with login
 */
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

/* login
 * 
 * Parameters:
 *  - username: the username provided by the user attempting to log in
 *  - password: the password provided by the user attempting to log in
 *
 * Description:
 * Handles the user login process by verifying the username, checking the password, and managing actions like re-entering usernames or creating new accounts.
 * First, the function checks if the username exists. If not, it asks the user to either re-enter the username or create a new account.
 * Then, it compares the provided password with the stored, encrypted password.
 * If the credentials are valid, the login is successful and the user is granted access.
 * If the credentials are invalid, an error message is displayed and the user is prompted to try again.
 * 
 * Return values:
 *  - 1: Successful login.
 *  - 0: Invalid password or failed login attempt.
 *  - 2: User needs to create a new account.
 *  - -1: Invalid action requiring retry.
 */
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

    if (strcmp(stored_password, hashed_password) == 0) {
        return 1; // successful login
    } else {
        printf("Invalid Password, Try Again.\n");
        return 0; //failed login
    }
    
}