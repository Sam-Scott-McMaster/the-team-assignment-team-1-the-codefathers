#include <stdio.h> 
#include <stdlib.h>  
#include <string.h> 
#include <dirent.h> 

void create_user_history_file(const char *username){ 
    char command[256]; 

    snprintf(command, sizeof(command), "./create_history.sh %s", username);

    int ret = system(command); 
    
    printf("History & Transaction file created for user: %s\n", username);
} 

int find_user_file(const char *username, const char *folder_name){
    // const char *folder_name = "history_logs"; // Name of the folder 

    DIR *dir = opendir(folder_name); // Open the directory 
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) { // Read each entry
        // Check if the entry name matches the target file name
        if (strcmp(entry->d_name, username) == 0) {
            closedir(dir); // Close the directory
            return 0;
        }
    }

    closedir(dir); 
    return 1;
}