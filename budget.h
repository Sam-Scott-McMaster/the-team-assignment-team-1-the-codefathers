/* 
 * Author: Nithika Karunamoorthy
 * Student Number: 400511869 
 * Date Handed In: 05/12/2024
 * 
 * 
 * This header file contains function declarations related to budget management. 
 * It includes functions to return a user's current budget and update a user's 
 * budget. These functions are designed to work with user data stored in files.
 * 
 */

#ifndef BUDGET_H
#define BUDGET_H

void returnBudget(const char *username);
void update_budget(const char *username, float *new_budget);

#endif