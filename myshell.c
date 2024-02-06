// myshell.c
// This file contains the main logic of your shell program.

#include "myshell.h"

// Function to execute the entered command
void execute_command(char *input) {
    char *token;
    char *delim = " \n";
    token = strtok(input, delim); // Tokenize the input

    // If the first token is a recognizable command
    if (token != NULL) {
        if (strcmp(token, "cd") == 0) {
            token = strtok(NULL, delim); // Get the next part of the input (directory path)
            change_directory(token); // Call the change_directory function
        } 
        else if (strcmp(token, "clr") == 0) {
            token = strtok(NULL, delim); // Get the next part of the input (directory path)
            clr(); // Call the change_directory function
        } 
        else if (strcmp(token,"dir")==0){
            token = strtok(NULL, delim);
            directory();
        }
        else if (strcmp(token,"echo")==0){
            token = strtok(NULL, delim);
            echo();
        }
        else if (strcmp(token,"environ")==0){
            token = strtok(NULL, delim);
            environ();
        }
       else if (strcmp(token,"help")==0){
            token = strtok(NULL, delim);
            help();
        }
       else if (strcmp(token,"pause")==0){
            token = strtok(NULL, delim);
            pauseop();
        }
       else if (strcmp(token,"quit")==0){
            token = strtok(NULL, delim);
            quit();
        }  
        else {
            printf("Command not recognized.\n");
        }
    }
}

int main() {
    char input[1024]; // Buffer for user input

    // Main command loop
    while (1) {
        printf("MyShell> "); // Prompt for input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on EOF
        }
        execute_command(input); // Process the input
    }

    return 0;
}
