#ifndef NEW_ACCOUNT_H
#define NEW_ACCOUNT_H

char *scan_birthday();
char *scan_username();
char *check_first_name();
char *check_last_name();
char *check_email();
char *scan_phone();
char *password_encryption(const char *, const char*);
char *password_processing(char *);

#endif