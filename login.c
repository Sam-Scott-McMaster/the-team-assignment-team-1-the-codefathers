#include <stdio.h>
#include <string.h>
#include "login.h"
#include "user_account.h"

//ask if the user already has an account
int check_username(const char *username) {
    
    if (find_user_file(username, "history_logs") != 0) {
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

    int result = check_username(username);
    if (result == 0); {
        return 0;
    }
    else if (result == 2) {
        return 2;
    }
    else if (result == -1) {
        return -1;
    }

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