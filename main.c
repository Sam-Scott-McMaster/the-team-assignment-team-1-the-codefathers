#include <stdio.h> 
#include <stdlib.h> 
#include "user_account.h"
#include "new_account.h"
int main() { 
    //char username[50]; 

    //printf("Enter your username: ");
    //scanf("%49s", username);

    //create_user_history_file(username);
    char *username = scan_username();
    char *phone_num = scan_phone();
    char *birthday = scan_birthday();
    return 0;
}
