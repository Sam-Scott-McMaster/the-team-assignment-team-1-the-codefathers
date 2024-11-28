#include <stdio.h> 
#include <stdlib.h>
#include "user_account.h"

double returnBudget(const char *username){ 
    return get_budget_from_user_file(username); 
}

void update_budget(const char *username, double new_budget){
    if (new_budget > 0){ 
        void update_budget(username, new_budget);
    } else {
        printf("Budget cannot be 0 or less.");
    }
    
}

