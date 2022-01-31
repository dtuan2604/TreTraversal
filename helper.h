#ifndef _HELPER_H
#define _HELPER_H
#include <stdio.h>

#define BUFFER 500

char *stringToData(char* str);
void writeFile(FILE * fp, char* fmt, ...);

#endif
