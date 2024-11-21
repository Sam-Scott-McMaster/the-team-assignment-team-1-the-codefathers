#include <stdio.h> 
#include <stdlib.h> 

void create_user_history_file(const char *username){ 
    char command[256]; 

    snprintf(command, sizeof(command), "./create_history.sh %s", username);

    int ret = system(command); 
    
    printf("History file created for user: %s\n", username);
} 