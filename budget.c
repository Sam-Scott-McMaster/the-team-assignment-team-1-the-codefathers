#include <stdio.h> 
#include <stdlib.h>
#include "file_management.h"

void returnBudget(const char *username){ 
    get_budget_from_user_file(username); 
}

void update_budget(const char *username, float *new_budget){
    if (*new_budget > 0){ 
        update_budget_file(username, new_budget);
    } else {
        printf("Budget cannot be 0 or less.");
    }
}
