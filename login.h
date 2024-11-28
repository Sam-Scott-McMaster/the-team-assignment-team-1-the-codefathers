#ifndef LOGIN_H
#define LOGIN_H

//ask if the user already has an account
int check_username(const char *username);

//log in the user
int login(const char *username, const char *password);

//check if the credentials are correct
// int check_credentials(const char *username, const char *password);
int check_credentials(const char *username, const char *stored_username, const char *stored_password);

#endif