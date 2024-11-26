#ifndef LOGIN_H
#define LOGIN_H

//ask if the user already has an account
void ask_if_has_account();

//log in the user
int login(const char *username, const char *password);

//check if the credentials are correct
int check_credentials(const char *username, const char *password);

#endif