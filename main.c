//Name: Chase Keller
//Date: 11/6/19
//Purpose: This is the main file for the project to run through

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "strvec.h"
#include "builtins.h"

//Prompt prints the new user input line for the shell being built
void prompt(){
    printf("\033[1;35m $> \033[0m"); //Set the text to the color and prints $>
}

//Reads in the user input and stores it into the string vector

void read_cmd(strvec * cmd){
    //free's the string vector to make sure it is empty before filling it
    strvec_free(cmd);
    //initializing the inputLine and setting it to NULL
    char * inputLine = NULL;
    size_t size;    //length of input string 
    int nread;      
    //grabs the user input and stores it in inputLine, saves length in size
    nread = getline(&inputLine, &size, stdin);

    //Tokenizing inputLine
    char * tok;
    tok = strtok(inputLine, " \n");
    //pushes the tokens to the strvec
    while (tok){
        strvec_push(cmd, tok);
        tok = strtok(NULL, " \n");
    }    
    //releases any data stored in inputLine
    free(inputLine);
}
//This is where commands will be executed
void exec_cmd(const strvec * cmd){

    //checks for builtins before forking
    int check = 0;  //variable to store if the command is equal to a builtin
    int j = 0;      //used to loop through BUILTINS[]
    //for loop to go through the array of commands
    for(int i = 0; i < strvec_size(*cmd); i++){
        //while loop to loop through builtins that ends with NULL
        while(BUILTINS[j]){
        check = strcmp(strvec_get(*cmd, i), BUILTINS[j]);   //Checks to see if the current cmd is in BUILTINS at index j
        //if it does equal run FCNS and that index and pass it the array of cmd then return to not fork
        if (check == 0){
            FCNS[j](cmd);
            return;
            }
        j++;
        }
}
    //forking for running shell functions without ending the shell after each execution.
    int cpid = fork();
    if(cpid == 0){
        //Child
        if(execvp(strvec_get(*cmd, 0), cmd->starr) == -1){  //runs command at index zero and checks to see if it errors out
            perror(strvec_get(*cmd, 0));    //prints error
            exit(errno);
        }
        else{   //error out
            printf("ERROR, ERROR, ERROR \n");
        }
    }
    else{
        //parent
        //Literal magic and that is all that is needed to know.
        int status;
        pid_t wpid;
        
        do {
        wpid = waitpid(cpid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    //sets the the new line for the next command
    printf("\n");
}

//Where the magic happens
int main(){
    //creates a strvec call cmd
    strvec cmd;
    //initializes cmd
    strvec_init(&cmd);
        //Loop that runs the shell
    	do {
		prompt();       //asks for user input
		read_cmd(&cmd);    //reads in the input
		exec_cmd(&cmd);     //executes the command
	} while (strcmp(strvec_get(cmd, 0), "exit") != 0);
    //Frees any memory stored in cmd
    strvec_free(&cmd);
    //end
    return 0;
}