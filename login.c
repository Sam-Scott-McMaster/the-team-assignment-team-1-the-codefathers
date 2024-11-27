#include <stdio.h>
#include <string.h>
#include "login.h"
#include "user_account.h"

//ask if the user already has an account
void ask_if_has_account() {
    char response;
    printf("Do you have an existing account? (y/n)");
    scanf(" %c, &response");

    if (response == 'n' || response == "N") {
        printf("Please create an account\n");

        //make sure to add in the sign-up logic (link it to the sign-up module)
    }
}

int check_credentials(const char *username, char *stored_username, char *stored_password) {

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
    // if (find_user_file(username, "history_logs") == 0 && ){

    // } 

    //compare with the stored credentials to make it work
    //should connect to actual stored data

    //simulates credential validation by comparing the inputs with a username and password
}

//log in the user (takes username and password as input)
int login(const char *username, const char *password) {

    char stored_username[50], stored_password[50];

    //validate credentials

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