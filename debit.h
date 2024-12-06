 /* 
 * Author: Leyla Kutlu
 * Student IDs: 400501110
 * Hand In Date: 05/12/2024
 * This header file defines functions related to debit account, including operations such as:
 * - spending money using debit card.
 * - adding money to debit account.
 * - checking debit card balance.
 */
#ifndef DEBIT_H
#define DEBIT_H

void add_to_debit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date);
void spend_money_debit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date);
void pay_off_credit(double *debit_balance, double *credit_balance, double amount, const char *folder_name, const char *username, const char *date);
void check_balance_debit(double debit_balance);

#endif