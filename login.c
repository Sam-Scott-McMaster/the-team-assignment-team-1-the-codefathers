#include <stdio.h>
#include <string.h>
#include "login.h"
#include "user_account.h"

//ask if the user already has an account
int check_username(const char *username) {
    
    if (find_user_file(username, "credentials") != 0) {
        int choice;
        printf("Username not found. What would you like to do?\n");
        printf("1. Re-enter the username\n");
        printf("2. Create a new account\n");
        scanf("%d", &choice);

        if (choice == 1) {
            return 0; //indicates that username needs to be re-entered
        }
        else if (choice == 2) {
            return 2; //indicates that user wants to create a new account
        }
        else {
            printf("Invalid choice. Please try again.\n");
            return -1; //invalid choice; retry
        }
    }

    return 1; //if the file exists, proceed with login

int check_credentials(const char *username, char *stored_username, char *stored_password) {

    if (find_user_file(username, "credentials") != 0) {
        printf("Error: Credentials file for user '%s' not found.\n", username);
        return 0;
    }

    char filename[100];
    sprintf(filename, "%s_credentials.txt", username);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: User credentials not found for %s.\n", username);
        return 0;
    }

    fscanf(file, "Username: %s\n", stored_username);
    fscanf(file, "Password: %s\n", stored_password);

    fclose(file);
    return 1;
}
}

//log in the user (takes username and password as input)
int login(const char *username, const char *password) {

    char stored_username[50], stored_password[50];

    /*while (1) {
        int username_check = check_username(username);

        if (username_check == 0) {
            printf("Please re-enter your username: "):
            scanf("%s", (char *)username);
        }
        else if (username_check == 2) {
            printf("Redirecting to account creation..");
            //call function to create account (new_account(username);)
            break;
        }
        else if (username_check == 1) {
            if (checl_credentials(username, stored_username, stored_password)) {
                if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
                    printf("Login successful\n");
                    return 1;
                }
                else {
                    printf("Invalid username or password\n");
                    return 0;
                }
            }
        }
        else {
            //retry if an invalid choice was made
            continue;
        }
    } */

    //if above is implemented, remove what's below

    if (check_credentials(username, stored_username, stored_password)) {

        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
            printf("Login successful\n");
            return 1;
        }
        else {
            printf("Invalid username or password\n");
            return 0;

            //if username does not exist, refer back to creating an account
        }
    }
    else {
        printf("Please create an account or ensure your credentials are correct.\n");
        return 0;
    }
}