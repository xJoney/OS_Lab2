// myshell.h
/* This is the header file where you include standard libraries and declare functions used across your shell program. */

#ifndef MYSHELL_H  // Prevents double inclusion of this header file
#define MYSHELL_H

#include <stdio.h>   // Standard I/O functions
#include <stdlib.h>  // Standard library for functions like malloc
#include <string.h>  // String handling functions
#include <unistd.h>  // Provides access to the POSIX operating system API

// Function declaration for changing directories (cd)
void change_directory(char *path);
void clr();
void directory();
void echo();
void environ();
void help();
void pauseop();
void quit();

#endif
