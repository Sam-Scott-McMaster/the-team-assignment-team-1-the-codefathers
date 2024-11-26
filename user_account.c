#include <stdio.h> 
#include <stdlib.h>  
#include <string.h> 
#include <dirent.h> 

// Function to create user history file 
void create_user_history_file(const char *username){ 
    char command[256]; 

    snprintf(command, sizeof(command), "./create_history.sh %s", username);

    int ret = system(command); 
    
    printf("History & Transaction file created for user: %s\n", username);
} 

// Function to find if a user exists in a given folder
int find_user_file(const char *username, const char *folder_name){
    DIR *dir = opendir(folder_name); // Open the directory
    if (!dir) {
        printf("Error: Could not open directory %s\n", folder_name);
        return -1; // Indicate error
    }

    char target_filename[256];
    snprintf(target_filename, sizeof(target_filename), "%s.txt", username); // Append .txt to username

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) { // Read each entry
        if (strcmp(entry->d_name, target_filename) == 0) { // Compare with constructed target filename
            closedir(dir); // Close the directory
            return 0;      // File found
        }
    }

    closedir(dir);
    return 1; // File not found
}

// Function to append a string to the user's file
void add_info_to_user_file(const char *folder_name, const char *username, const char *info) {
    char filepath[256]; // Buffer to store the full file path
    snprintf(filepath, sizeof(filepath), "%s/%s.txt", folder_name, username); // Construct the file path

    FILE *file = fopen(filepath, "a"); 

    if (!file) { 
        printf("Error: Could not open file %s for writing.\n", filepath); 
        return; 
    }

    fprintf(file, "%s\n", info); 
    fclose(file); 
    printf("Information added to file: %s\n", filepath); 
}


