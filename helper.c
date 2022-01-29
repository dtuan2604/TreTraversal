#include "helper.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
