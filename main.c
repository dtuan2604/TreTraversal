#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "helper.h"
#include <string.h>


char fileName[100];
char tempFile[100];
char prog[100];

int isfileEmpty(FILE * fp);

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
			fprintf(stderr,"ERROR: %s: Cannot open file\n",prog);
			return EXIT_FAILURE;
		}
	
		if((input = getchar()) == EOF)
		{
			fprintf(stderr,"ERROR: %s: Input is empty\n",prog);
			return EXIT_FAILURE;
		}	
		else
		{
			fprintf(ptr,"%c", input);
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
	if(isfileEmpty(inputPtr) == 0)
		return EXIT_FAILURE;	
	
	//node_t *root = buildTree(inputPtr);
	//insert(node_t *rootNode, node_t *newNode)
	
	fclose(inputPtr);

	return EXIT_SUCCESS;



}

//Checking if the file is exist or empty
int isfileEmpty(FILE * fp)
{
	if(fp != NULL)
	{
		fseek(fp, 0, SEEK_END);
		int test = ftell(fp);

		if(test == 0)
		{
			fprintf(stderr, "ERROR: %s: Input is empty\n", prog);
			return 0;
		}
			 

	}
	else
	{
		fprintf(stderr, "ERROR: %s: Cannot open file\n", prog);
		return 0;
	}
	
	return 1;
}

