#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "new_account.h"
#include "user_account.h"

char *check_first_name() {
    const char *pattern = "^[A-Za-z]+$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *first_name = malloc(20 * sizeof(char));
    puts("Please enter your first name: ");

    while (scanf("%20s", first_name) !=1 || regexec(&regex, first_name, 0, NULL, 0) != 0) {
        puts("Your first name cannot contain non-alphabetical characters");
        while(getchar()!='\n');
    }

    return first_name;

}

char *check_last_name() {
    const char *pattern = "^[A-Za-z]+$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *last_name = malloc(20 * sizeof(char));
    puts("Please enter your last name: ");

    while (scanf("%20s", last_name) != 1 || regexec(&regex, last_name, 0, NULL, 0) != 0) {
        puts("Your last name cannot contain non-alphabetical characters");
        while(getchar()!='\n');
    }

    return last_name;
}

void check_email() {
    const char *pattern = "^[A-Za-z0-9]+[@][a-z]+[\\.][ca|com]$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *email = malloc(50 * sizeof(char));
    puts("Please enter your email: ");

    while (scanf("%50s", email) !=1 || regexec(&regex, email, 0, NULL, 0) != 0) {
        puts("Please enter a valid email.");
        while(getchar()!='n');

    }
	
} 

typedef struct {
    int day;
    int month;
    int year;
} Date;

char *scan_birthday() {
    Date date;
    char *birthday = malloc(11*sizeof(char));

    printf("Enter your birthday (DD/MM/YYYY): ");

    while (scanf("%d/%d/%d", &date.day, &date.month, &date.year) != 3 || date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 1900 || date.month > 2100) {
        printf("Invalid input. Please enter your birthday in the format DD/MM/YYYY: ");
        // Clearing input buffer
        while (getchar() != '\n');
    }

    sprintf(birthday, "%02d/%02d/%d", date.day, date.month, date.year);

    return birthday;
}

char *scan_username(){
    const char *pattern = "^[a-zA-Z][_0-9a-zA-z]{2,18}[a-zA-Z]$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *username = malloc(20 * sizeof(char));
    puts("Enter a username between 6-18 characters: ");


    while(scanf("%s", username) != 1 || regexec(&regex, username, 0, NULL, 0 != 0) || find_user_file(username) == 0){
        if (find_user_file(username) == 0){
            puts("This username already exists. Please choose a unique username.");
        } else {
            puts("Username invalid. Kindly enter one in the correct format:");
        }
        while(getchar()!='\n');
    }

    return username;
}
char *scan_phone(){
    char *phone_num = malloc(11*sizeof(char));
    regex_t regex;
    char *pattern = "[0-9]{10}";
    regcomp(&regex, pattern, REG_EXTENDED);

    puts("Enter phone number in the format \"DDDDDDDDDD\": ");

    while(scanf("%10s", phone_num) != 1 || regexec(&regex, phone_num, 0, NULL, 0) != 0){
        puts("Invalid phone number. Please enter in the format \"DDDDDDDDDD\" where D is a digit: ");
        while(getchar()!='\n');
    }

    return phone_num;
}

char *password_hashing(char *name, char* password) {
    int key = 0;    

    for (int i=0; i<sizeof(name); i++){
        key += name[i];
    }
    char *hashed_password = malloc(sizeof(char) * (strlen(password) + 1));

    for (int i=0; i<strlen(password); i++){
        hashed_password[i] = password[i] ^ key;
    }         
    return hashed_password;
}

char *password_processing(char *name) {
    char *password = malloc(30*sizeof(char));
    regex_t regex;
    char *pattern = "^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[@$!%*?&]).{8,}$";

    // char *hashed_password = malloc((strlen(password)+1) * sizeof(char));
    // hashed_password =  password_hashing(char *name, password);

    return "hashed_password"; //remove quotations;
}