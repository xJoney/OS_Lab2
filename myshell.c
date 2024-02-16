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
            
            clr(); // Call the change_directory function
        } 
        else if (strcmp(token,"dir")==0){
        token = strtok(NULL, delim); //get the next part of the input (directorypath)
        if (token == NULL){
            	token = ("."); //If user did not put in a path, put the token as "." to pwd
        }
            directory(token);//call directory function 
        }
        else if (strcmp(token,"echo")==0){
            token = strtok(NULL, delim); //get the next part of the input (comment)
            echo(token); //calls echo function
        }
        else if (strcmp(token,"environ")==0){
            environment(); //calls environment function
        }
       else if (strcmp(token,"help")==0){
            help(); //calls help function
        }
       else if (strcmp(token,"pause")==0){
            pauseop(); //calls pauseop function 
        } 
       else if (strcmp(token,"quit")==0 || strcmp(token,"exit")==0){ //accepts exit or quit to run quit function
            quit();//calls quit function
        }  
        else {
            printf("Command not recognized.\n"); //if user input invalid command, let user know
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
