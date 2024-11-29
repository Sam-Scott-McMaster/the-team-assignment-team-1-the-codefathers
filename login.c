#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "user_account.h"
#include "file_management.h"

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

}

int check_credentials(const char *username) {
    //checks if file is in the files
    if (find_user_file(username, "history_logs") != 0) {
        printf("Error: Credentials file for user '%s' not found.\n", username);
        return 0; 
    }
    return 1;

    // char filename[100];
    // sprintf(filename, "%s_credentials.txt", username); //creates a filename for the user’s credentials by appending _credentials.txt to their username

    // FILE *file = fopen(find_user_file(username, "credentials"), "r");
    // if (!file) {
    //     printf("Error: User credentials not found for %s.\n", username);
    //     return 0;
    // }

    //reads the stored username and password from the file and saves them
    // fscanf(file, "Username: %s\n", stored_username);
    // fscanf(file, "Password: %s\n", stored_password);

    // fclose(file); //closes the file
    // return 1;
}


//log in the user (takes username and password as input)
int login(char *username, const char *password) {

   
    char stored_username[50];


    int result = check_username(username);
    if (result == 0 || result == 2 || result == -1) {
        return result;
    }
    puts("we're in!");
    char *hashed_password = malloc(sizeof(char)*32);
    get_user_password(username, hashed_password, 100);
    char *stored_password = password_hashing(username, hashed_password);

    if (check_credentials(username)) {
        
        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
            return 1; // successful login
        }
        else {
            printf("Invalid username or password\n");
            return 0;
        }
    }
    else {
        printf("Account not found. Please create a new account.\n");
        return 2;
    }
}