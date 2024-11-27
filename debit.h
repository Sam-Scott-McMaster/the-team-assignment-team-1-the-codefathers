#ifndef DEBIT_H
#define DEBIT_H

void add_to_debit(double *debit_balance, double amount, const char *folder_name, const char *username, const char *date);
void spend_money_debit(double *debit_balance, double amount, const char *folder_name, const char *username, const char *date);
void pay_off_credit(double *debit_balance, double *credit_debt, double amount, const char *folder_name, const char *username, const char *date);
void check_balance_debit(double debit_balance);

#endif