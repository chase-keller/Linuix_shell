//Name: Chase Keller
//Date: 11/6/19
//Purpose: To handle builtins functions

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "builtins.h"
#include "strvec.h"

//sets global arrays of builtin functions and how to call them
const char* BUILTINS[] = {"cd", NULL};
const void (*FCNS[])(const strvec * cmd) = {_cd, NULL};

//used to execute the cd builtin functions
void _cd(const strvec * cmd){

    //Checks to see if the cmd array has 3 or more arguments
    if(strvec_size(*cmd) >= 3){
        printf("too many arguments\n");
    }
    //Checks to see if the command is equal to 1
    else if(strlen(strvec_get(*cmd, 1)) == 1)
    {
        chdir("cd ~");
    }
    //Runs the command and if fails sends out an error
    else{
        if(chdir(strvec_get(*cmd, 1)) == -1){
            perror("cd");
        }
    }
    
}