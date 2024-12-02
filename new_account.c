/** 
 * Contains functions for input validation and processing related to user account
 * creation, including checking names, email, birthday, username, phone number, password strength, and
 * password encryption.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#include <math.h>
#include "new_account.h"
#include "file_management.h"

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

char *check_email() {
    const char *pattern = "^[A-Za-z0-9]+[@][a-z]+[\\.](ca|com)$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *email = malloc(50 * sizeof(char));
    puts("Please enter your email: ");

    while (scanf("%50s", email) !=1 || regexec(&regex, email, 0, NULL, 0) != 0) {
        puts("Please enter a valid email.");
        while(getchar()!='n');

    }

    return email;
	
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
    const char *pattern = "^[a-zA-Z][_0-9a-zA-z]{2,18}[a-zA-Z0-9]$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *username = malloc(20 * sizeof(char));
    puts("Enter a username that fit the following criteria: ");
    puts("    -Between 4-18 characters.");
    puts("    -Contains only alphabetical, numerical and underscore characters.");
    puts("    -Does not begin or end with an underscore character.\n");


    while(scanf("%s", username) != 1 || regexec(&regex, username, 0, NULL, 0 != 0) || find_user_file(username, "history_logs") == 0){
        if (find_user_file(username, "history_logs") == 0){
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

char *int_to_char(long num){
// Function to convert a number between 0-36 into its character representation
    char c;
    if (num < 10){ // For 0-9, convert to ASCII digits
        c = (char) num + 48;
    } else { // For 10-36, convert to ASCII letters A-Z
        c = (char) num + 55; 
    }
    char *c_str = malloc(sizeof(char)*2);
    sprintf(c_str, "%c", c);  
    return c_str;
}

char *to_hex(long num){ 
    
    char *hex_reverse = malloc(sizeof(char) * 100);
    char *hex = malloc(sizeof(char) * 100);
    long rem;

    while(num >= 16){
        rem = num%16;
        num /= 16;
        strcat(hex_reverse, int_to_char(rem));
    }
    strcat(hex_reverse, int_to_char(num));

    for (int i=strlen(hex_reverse)-1; i >= 0; i--){
        hex[strlen(hex_reverse)-1-i] = hex_reverse[i];
    }
    
    hex = realloc(hex, sizeof(char)*(strlen(hex)+1));

    return hex;
} 

int to_int(char *hex){
    int value = 0;
    int hex_digit;

    for (int i = strlen(hex)-1; i>=0; i--){

        if (hex[i] <= '9'){
            hex_digit = hex[i] - 48;
        } else {
            hex_digit = hex[i] - 55;
        }
        value += hex_digit*pow(16, strlen(hex)-1-i);
    }
    return value;
}

char *password_encryption(const char *username, const char* password) {
    int key = 0;

    for (int i=0; i<strlen(username); i++){
        key += username[i];
    }
    char *hashed_password = calloc(strlen(password) * 2 + 1, sizeof(char));  // Initialize memory


    for (int i=0; i<strlen(password); i++){
        strcat(hashed_password, to_hex(password[i] ^ key));
    }         
    return hashed_password;
}

int check_valid_password(char *password) {
    int has_lower = 0, has_upper = 0, has_digit = 0, has_special = 0;
    char *special_char = ".@#$!*?&():;";
    
    for (int i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) has_lower = 1;
        if (isupper(password[i])) has_upper = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (strchr(special_char, password[i])) has_special = 1;
    }
    
    int valid = has_lower && has_upper && has_digit && has_special;

    return valid;
}

char *password_processing(char *username) {
    char *password = malloc(32*sizeof(char));
    regex_t regex;
    char *pattern = "^[A-Za-z0-9.@#$!*?&():;]{8,32}$";

    int ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        char errbuf[100];
        regerror(ret, &regex, errbuf, sizeof(errbuf));
        fprintf(stderr, "Regex compilation failed: %s\n", errbuf);
        free(password);  // Free the allocated memory before exiting
        exit(1);  // Or handle appropriately
    }

    puts("Password format:");
    puts("- At least 1 upper case letter");
    puts("- At least 1 lower case letter");
    puts("- At least 1 numerical character");
    puts("- At least 1 special character from this selection: .@#$!*?&():;");
    puts("");
    puts("Create a password containing 8-32 letters: ");

    while(scanf("%s", password) != 1 || regexec(&regex, password, 0, NULL, 0) != 0 || check_valid_password(password) == 0) {

        puts("Password too weak. Your password must fulfill the requirements above.");
        while(getchar()!='\n');
    }

    char *hashed_password = malloc(1000);
    hashed_password =  password_encryption(username, password);

    return hashed_password;
}