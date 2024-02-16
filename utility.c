// utility.c
// This file will have the implementation of the commands.

#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

// Function to change the current working directory
void change_directory(char *path) {
    // Check if the path argument is NULL, which implies no specific directory was provided
    if (path == NULL) {
        // Create a buffer to store the current working directory path
        char cwd[1024];

        // Use getcwd to get the current working directory.
        // getcwd fills the array 'cwd' with the absolute pathname of the current working directory.
        // If the function succeeds, the cwd array contains this pathname and NULL is not returned.
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // If successful, print the current working directory to the user
            printf("%s\n", cwd);
        } else {
            // If getcwd fails, use perror to print an error message.
            // perror produces a message on standard error describing the last error encountered during a call to a system or library function.
            perror("getcwd() error");
        }
    } else {
        // If a path is provided, try changing the directory to the specified path using chdir
        // chdir changes the current working directory of the calling process to the directory specified in path.

        // If chdir returns a non-zero value, it indicates an error occurred (like if the directory does not exist).
        if (chdir(path) != 0) {
            // In case of an error, use perror to print the error message.
            perror("myshell");
        }
    }
}

void clr(){
	system("clear"); //clears the console
}

void directory(char *path){
	struct dirent *dir_ent;  // Pointer for directory entry that hold information on each directory entry
    DIR *dir_stream = opendir(path); //opens current directory, returns a pointer which represents the directory stream

    if (dir_stream == NULL) 
   	 { 
      	    printf("Could not find directory: %s... Perhaps file does not exist.\n",path);  //if the pointer is null, let user know that the directory could not be opened
            return;
    	  
   	 } 
    while ((dir_ent = readdir(dir_stream)) != NULL) //pointer for directory entry is assigned to read the next directory. AS long as it is not NULL, continue
            printf("%s\n", dir_ent->d_name); //outputs the directory
  
    closedir(dir_stream);     //closes the directory stream
}

void echo(char *msg){
    printf("%s\n",msg); // prints the comment to console
}

void environment(){
    extern char** environ; //sets environ as an external variable
    for(int i=0;environ[i]!=NULL; i++){ //iterate through array of environment variables until there's none left
        printf("%s\n",environ[i]); //prints environment to console
    }
}

void help(){
    int c; // initialized variables
    FILE *f = fopen("readme.md","r"); //opens "readme.md" file and read
    if(f==NULL){        
        printf("error");    //checks if file is NULL, prints error if it is
    }
    while((c=fgetc(f))!=EOF){ //gets next character in the file while its not at the end of file
        putchar(c);         //outputs character to console
    }
    fclose(f); //closes file
}

void pauseop(){
    printf("\npaused.. press Enter to resume"); //lets users know that the shell has been paused
    getchar(); //get character from user input
    printf("\nresuming..\n"); //lets user know the shell will continue now
}

void quit(){
    printf("Exiting myshell...\n"); //prints out to let user knows they are exiting the shell
     exit(0); //exits shell
}