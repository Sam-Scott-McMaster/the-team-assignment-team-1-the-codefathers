/** Authors: Stella Liu and Rachel Nyonje
 * 
 * Description:
 * This program contains a set of functions designed to handle user input validation and account 
 * creation processes. It validates first and last names, emails, birthdays, usernames, and phone 
 * numbers according to specific patterns or rules. Additionally, the program ensures password 
 * strength requirements are met and provides functionality for password encryption using a username-based 
 * key.
 * 
 * Main Features:
 * - Validation of input formats using regular expressions.
 * - Enforcement of rules for username uniqueness.
 * - Password encryption through a simple XOR-based scheme and hexadecimal representation.
 * - Modular, reusable functions for better maintainability and readability.
 * 
 * Usage:
 * Each function can be called individually to validate or process a specific user account field, 
 * with memory management handled through dynamic allocations.
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
/* Name: check_first_name
 * Parameters: None
 * Description: Prompts the user to input their first name and validates it against a regex pattern 
 *              to ensure it contains only alphabetical characters. Repeats prompt until valid input is given.
 * Return Value: Pointer to a dynamically allocated string containing the validated first name.
 */
    const char *pattern = "^[A-Za-z]+$"; // Regex pattern allowing only alphabetical characters
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED); // Compile regex for validation

    char *first_name = malloc(20 * sizeof(char)); // Allocate memory for the first name
    printf("Please Enter Your First Name: ");

    // Loop until valid input is entered
    while (scanf("%20s", first_name) !=1 || regexec(&regex, first_name, 0, NULL, 0) != 0) {
        printf("Your First Name Cannot Contain Non-alphabetical Characters: ");
        while(getchar()!='\n'); // Clear input buffer
    }

    return first_name;

}

char *check_last_name() {
/* Name: check_last_name
 * Parameters: None
 * Description: Prompts the user to input their last name and validates it against a regex pattern 
 *              to ensure it contains only alphabetical characters. Repeats prompt until valid input is given.
 * Return Value: Pointer to a dynamically allocated string containing the validated last name.
 */
    const char *pattern = "^[A-Za-z]+$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *last_name = malloc(20 * sizeof(char));
    printf("Please Enter Your Last Name: ");

    while (scanf("%20s", last_name) != 1 || regexec(&regex, last_name, 0, NULL, 0) != 0) {
        printf("Your Last Name Cannot Contain Non-alphabetical Characters: ");
        while(getchar()!='\n');
    }

    return last_name;
}

char *check_email() {
/* Name: check_email
 * Parameters: None
 * Description: Prompts the user to input their email and validates it against a regex pattern 
 *              to ensure it follows a standard email format (e.g., username@domain.com or .ca).
 * Return Value: Pointer to a dynamically allocated string containing the validated email.
 */
    const char *pattern = "^[A-Za-z0-9]+[@][a-z]+[\\.](ca|com)$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *email = malloc(50 * sizeof(char));
    printf("Please Enter Your Email: ");

    while (scanf("%50s", email) !=1 || regexec(&regex, email, 0, NULL, 0) != 0) {
        printf("Please Enter a Valid Email: ");
    }

    return email;
	
} 

typedef struct {
    int day;
    int month;
    int year;
} Date;

char *scan_birthday() {
/* Name: scan_birthday
 * Parameters: None
 * Description: Prompts the user to input their birthday in the format DD/MM/YYYY and validates the input 
 *              to ensure the date is valid. Repeats prompt until valid input is given.
 * Return Value: Pointer to a dynamically allocated string containing the formatted birthday.
 */
    Date date;
    char *birthday = malloc(11*sizeof(char));

    printf("Enter Your Birthday (DD/MM/YYYY): ");

    while (scanf("%d/%d/%d", &date.day, &date.month, &date.year) != 3 || date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 1900 || date.month > 2100) {
        printf("Invalid Input. Please Enter Your Birthday In The Format DD/MM/YYYY: ");
        // Clearing input buffer
        while (getchar() != '\n');
    }

    sprintf(birthday, "%02d/%02d/%d", date.day, date.month, date.year);

    return birthday;
}

char *scan_username(){
/* Name: scan_username
 * Parameters: None
 * Description: Prompts the user to input a username and validates it against a regex pattern to ensure it:
 *              - Contains 4-18 characters.
 *              - Contains only alphanumeric and underscore characters.
 *              - Does not start or end with an underscore.
 *              Ensures the username is unique by checking against existing user files.
 * Return Value: Pointer to a dynamically allocated string containing the validated username.
 */
    const char *pattern = "^[a-zA-Z][_0-9a-zA-z]{2,18}[a-zA-Z0-9]$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *username = malloc(20 * sizeof(char));
    puts("\nEnter a Username That Fits The Following Criteria: ");
    puts("    -Between 4-18 Characters.");
    puts("    -Contains Only Alphabetical, Numerical And Underscore Characters.");
    puts("    -Does Not Begin or End With an Underscore Character.\n");


    while(scanf("%s", username) != 1 || regexec(&regex, username, 0, NULL, 0 != 0) || find_user_file(username, "history_logs") == 0){
        if (find_user_file(username, "history_logs") == 0){
            printf("This Username Already Exists. Please Choose a Unique Username: ");
        } else {
            printf("\nUsername Invalid. Kindly Enter One In The Correct Format: ");
        }
        while(getchar()!='\n');
    }

    return username;
}

char *scan_phone(){
/* Name: scan_phone
 * Parameters: None
 * Description: Prompts the user to input a 10-digit phone number and validates it against a regex pattern 
 *              to ensure it contains only numerical characters. Repeats prompt until valid input is given.
 * Return Value: Pointer to a dynamically allocated string containing the validated phone number.
 */
    char *phone_num = malloc(11*sizeof(char)); // Allocate memory for a 10-digit phone number
    regex_t regex;
    char *pattern = "[0-9]{10}"; // Regex pattern for 10 digits
    regcomp(&regex, pattern, REG_EXTENDED);

    printf("Enter Phone Number in The Format \"DDDDDDDDDD\": ");

    // Validate input until a 10-digit phone number is entered
    while(scanf("%10s", phone_num) != 1 || regexec(&regex, phone_num, 0, NULL, 0) != 0){
        printf("Invalid Phone Number. Please Enter In The Format \"DDDDDDDDDD\" Where D Is a Digit: ");
        while(getchar()!='\n'); // Clear input buffer
    }

    return phone_num; // Return the validated phone number
}

char *int_to_char(long num){
/* Name: int_to_char
 * Parameters:
 *      - num (long): A number between 0-36 to be converted to its character representation.
 * Description: Converts a number (0-36) to its character representation (0-9 as digits, 10-36 as uppercase letters).
 * Return Value: Pointer to a dynamically allocated string containing the character representation.
 */
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
/* Name: to_hex
 * Parameters:
 *      - num (long): A number to be converted to its hexadecimal representation.
 * Description: Converts a given number to its hexadecimal representation by repeatedly dividing by 16 
 *              and appending the remainder in reverse order.
 * Return Value: Pointer to a dynamically allocated string containing the hexadecimal representation.
 */   
    char *hex_reverse = malloc(sizeof(char) * 1000);
    char *hex = malloc(sizeof(char) * 1000);
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
/* Name: to_int
 * Parameters:
 *      - hex (char*): Pointer to a string containing a hexadecimal number.
 * Description: Converts a string representation of a hexadecimal number to its integer value.
 * Return Value: Integer representation of the hexadecimal input.
 */
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
/* Name: password_encryption
 * Parameters:
 *      - username (const char*): The username used as the key for encryption.
 *      - password (const char*): The plaintext password to be encrypted.
 * Description: Encrypts the password using a simple XOR operation with a key derived from the username
 *              and converts the result into a hexadecimal string.
 * Return Value: Pointer to a dynamically allocated string containing the encrypted password.
 */
    int key = 0;

    // Generate the encryption key by summing ASCII values of username characters
    for (int i=0; i<strlen(username); i++){
        key += username[i];
    }

    // Allocate memory for the encrypted password as a hexadecimal string
    char *hashed_password = calloc(strlen(password) * 2 + 1, sizeof(char));  // Initialize memory


    for (int i=0; i<strlen(password); i++){
        // Encrypt each character with XOR and convert to hexadecimal
        strcat(hashed_password, to_hex(password[i] ^ key));
    }         
    return hashed_password; // Return the encrypted password
}

int check_valid_password(char *password) {
/* Name: check_valid_password
 * Parameters:
 *      - password (char*): Pointer to the string containing the password to be validated.
 * Description: Checks if a password meets complexity requirements: at least one uppercase letter, 
 *              one lowercase letter, one digit, and one special character.
 * Return Value: Integer value (1 for valid, 0 for invalid).
 */
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
/* Name: password_processing
 * Parameters:
 *      - username (char*): The username associated with the password.
 * Description: Prompts the user to create a password that meets complexity requirements and validates it.
 *              Encrypts the password using the username as the encryption key.
 * Return Value: Pointer to a dynamically allocated string containing the encrypted password.
 */
    char *password = malloc(32*sizeof(char));
    regex_t regex;
    char *pattern = "^[A-Za-z0-9.@#$!*?&():;]{8,32}$";

    int ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        char errbuf[100];
        regerror(ret, &regex, errbuf, sizeof(errbuf));
        fprintf(stderr, "Regex Compilation Failed: %s\n", errbuf);
        free(password);  // Free the allocated memory before exiting
        exit(1);  // Or handle appropriately
    }

    puts("\nPassword Format:");
    puts("- At Least 1 Upper Case Letter");
    puts("- At Least 1 Lower Case Letter");
    puts("- At Least 1 Numerical Character");
    puts("- At Least 1 Special Character From This Selection: .@#$!*?&():;");
    puts("");
    printf("Create a password containing 8-32 letters: ");

    while(scanf("%s", password) != 1 || regexec(&regex, password, 0, NULL, 0) != 0 || check_valid_password(password) == 0) {

        printf("Password Too weak. Your Password Must Fulfill The Requirements Above: ");
        while(getchar()!='\n');
    }

    char *hashed_password = malloc(1000);
    hashed_password =  password_encryption(username, password);

    return hashed_password;
}