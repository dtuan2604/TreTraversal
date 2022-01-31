#include "helper.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

char* helpFile = "helper.h";

char* stringToData(char* str)
{
	int size = strlen(str) + 2;
	char* buffer = (char*)malloc(size);
	if(buffer == NULL)
	{
		fprintf(stderr,"ERROR: %s: failed to allocate log", helpFile);
		return NULL;		
	}
	char colon = ':';
	
	memset(buffer, '\0', size);
	strncat(buffer, &str[size-3],1);
	strncat(buffer, &colon, 1);
	strcat(buffer, str);

	return buffer;
}

void writeFile(FILE * fp, char* fmt, ...)
{
	char buf[BUFFER];
	va_list args;

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);


	if(fp != NULL)
	{
		fprintf(fp, buf);
		fflush(fp);
	}	


} 
