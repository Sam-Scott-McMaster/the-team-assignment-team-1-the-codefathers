#ifndef CREDIT_H
#define CREDIT_H

void spend_money_credit(double *credit_balance, double amount, const char *folder_name, const char *username, const char *, double *credit_debt);
//void pay_off_credit(double *debit_balance, double *credit_debt, double amount, const char *folder_name, const char *username, const char *date);
void check_balance_credit(double credit_balance, double credit_debt);

#endif