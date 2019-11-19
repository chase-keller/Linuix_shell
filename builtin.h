//Name: Chase Keller
//Date: 11/6/19
//Purpose: prototypes for builtins.c

#ifndef BUILTINS_H
#define BUILTINS_H
#include "strvec.h"

extern const char* BUILTINS[];
void _cd(const strvec * cmd);
extern const void (*FCNS[])(const strvec * cmd);

#endif