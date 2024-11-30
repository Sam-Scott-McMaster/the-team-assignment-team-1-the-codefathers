#ifndef CREDIT_H
#define CREDIT_H

void spend_money_credit(double *credit_balance, double *debit_balance, double amount, const char *folder_name, const char *username, const char *date);
void pay_off_credit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date);
void check_balance_credit(double credit_balance);

#endif