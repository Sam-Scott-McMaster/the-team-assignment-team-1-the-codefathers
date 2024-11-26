#ifndef DISPLAY_DETAILS_H
#define DISPLAY_DETAILS_H

//helper function to read user data from a file
int load_user_info(const char *username, char *account_type, double *balance, char *name, char *card_number);

//display account type
void display_account_type(const char *account_type);

//display account balance
void display_account_balance(double balance);

//display personal info
void display_personal_info(const char *name, const char *card_number);

#endif