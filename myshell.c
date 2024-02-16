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
            pid_t pid = fork();

            if(pid>0){ //parent process
                
                int status;
                waitpid(pid,&status,0); //wait for all child processes to finish
            }
            else{ //child process
                char penv[1024];
                snprintf(penv,sizeof(penv),"Parent:%s/myshell",getenv("PWD")); //sets up parent variables
                setenv("parent",penv,1);
            }
        }
    }
}

int main(int argc,char *argv[]) {
    char input[1024]; // Buffer for user input
    // FILE *file; 

    // if(argc!=2){                                 //checks for error
    //     fprintf(stderr, "Usage: %s\n",argv[0]);
    //     return 1;
    // }
    // file = fopen(argv[1],"r"); //opens file and reads it

    // while(fgets(input,sizeof(input),file)!=NULL){ //while not null, execute command 
    //     execute_command(input);
    // }
    // fclose(file); //closes the file
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
