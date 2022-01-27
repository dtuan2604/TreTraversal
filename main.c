#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <string.h>


char fileName[100];
char tempFile[100];
char prog[100];

int main(int argc, char** argv)
{
	strcpy(prog,argv[0]);
	if(argc == 2)
	{
		strcpy(fileName, argv[1]);
		strcpy(tempFile, argv[1]);
		strcat(fileName, ".sp2022");
	}
	else if(argc < 2)
	{
		strcpy(fileName,"output");
		strcpy(tempFile,"output");
	
		FILE *ptr = fopen(fileName, "w");
		int input;	
	
		if(ptr == NULL){
			fprintf(stderr,"ERROR: %s: Cannot open file",prog);
			return EXIT_FAILURE;
		}
		
		while((input = getchar()) != EOF)
		{
			fprintf(ptr,"%c",input);	

		}
		printf("Finish\n");	
		fclose(ptr);	
		

	}
	else
	{
		fprintf(stderr,"ERROR: %s: Please provide one file as an argument to the program\n",prog);
		return EXIT_FAILURE;
	}

	FILE *inputPtr = fopen(fileName, "r");
	if(inputPtr == NULL)
	{
		fprintf(stderr,"%s: Cannot open file %s\n", prog,fileName);
		return EXIT_FAILURE;

	}	

	return EXIT_SUCCESS;



}
