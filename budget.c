/* 
 * Author: Nithika Karunamoorthy
 * Student Number: 400511869 
 * Date Handed In: 05/12/2024
 * 
 * This file contains functions for retrieving and updating a user's budget.
 * The functions rely on file operations defined in the file_management module.
 */

#include <stdio.h> 
#include <stdlib.h>
#include "file_management.h"

/* 
 * returnBudget
 * 
 * Retrieves and displays the current budget for a given user by calling
 * the get_budget_from_user_file function.
 * 
 * Parameters:
 * - username: A string representing the username whose budget is to be retrieved.
 */

void returnBudget(const char *username){ 
    get_budget_from_user_file(username); 
}


/* 
 * update_budget
 * 
 * Updates the budget for a given user if the new budget is greater than zero. 
 * If the budget is invalid (0 or less), an error message is printed.
 * 
 * Parameters:
 * - username: A string representing the username whose budget is to be updated.
 * - new_budget: A pointer to a float representing the new budget amount.
 */

void update_budget(const char *username, float *new_budget){
    if (*new_budget > 0){ 
        update_budget_file(username, new_budget);
    } else {
        printf("Budget Cannot Be 0 or Less.");
    }
}
