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

int check_credentials(const char *username, const char *password) {

    // if (find_user_file(username, "history_logs") == 0 && ){

    // } 

    //compare with the stored credentials to make it work
    //should connect to actual stored data

    //simulates credential validation by comparing the inputs with a username and password
    return strcmp(username, "testuser") == 0 && strcmp(password, "testpass") == 0;
}

//log in the user (takes username and password as input)
int login(const char *username, const char *password) {
    //validate credentials
    if (check_credentials(username, password)) {
        printf("Login successful\n");
        return 1;
    }
    else {
        printf("Invalid username or password\n");
        return 0;

        //if username does not exist, refer back to creating an account
    }
}