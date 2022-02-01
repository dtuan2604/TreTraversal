#ifndef _HELPER_H
#define _HELPER_H

#include <stdio.h>

#define BUFFER 500

int isfileEmpty(FILE * fp, char* caller); //Checking if the file is empty or not
char *stringToData(char* str); //convert the normal string to the needed string
void writeFile(FILE * fp, char* fmt, ...); //assistant function to write to a file

#endif
