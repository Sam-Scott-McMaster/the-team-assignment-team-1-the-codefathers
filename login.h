 /* 
 * This header file defines functions related to login, including operations such as:
 * - checking if the user has an account.
 * - logging the user in.
 * - checking the user's credentials.
 */

#ifndef LOGIN_H
#define LOGIN_H

//ask if the user already has an account
int check_username(const char *username);

//log in the user
int login(char *username, const char *password);

//check if the credentials are correct
// int check_credentials(const char *username, const char *password);
int check_credentials(const char *username);

#endif