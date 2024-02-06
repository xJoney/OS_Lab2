#include "myshell.h"

void execute_command(char*input){
	char *token;
	char *delim="\n";
	token=strtok(input,delim);
	
	if(token~=NULL){
		if (strcmp(token,"cd")==0{
			token=strtok(NULL,delim);
			//directory path
			change_directory(token);
		}
		else{
			printf("Command not recognized.\n");
		}//end ifelse
	}//end if
}//end of exec method

int main(){
	char input[1024];
	
	while (1){
		printf("MyShell>");
		if(fgets(input,sizeof(input),stdin)==NULL){
			break;
		}
	}
	
	return 0;
}
