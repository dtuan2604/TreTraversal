#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "helper.h"
#include <string.h>
#include <unistd.h>


char fileName[BUFFER];
char tempFile[BUFFER];
char prog[BUFFER];

int main(int argc, char** argv)
{
	strcpy(prog,argv[0]);
	
	//Checking arguments
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
		
		//First checking if the input is empty
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
			fprintf(ptr,"%c",input);	
		
		fclose(ptr);	
	}
	else
	{
		fprintf(stderr,"ERROR: %s: Please provide one file as an argument to the program\n",prog);
		return EXIT_FAILURE;
	}

	FILE *inputPtr = fopen(fileName, "r");
	if(isfileEmpty(inputPtr, prog) == 1)
		return EXIT_FAILURE;	

	struct node_t *root = buildTree(inputPtr); //Build the tree

	printPreorder(root, tempFile);
	printInorder(root, tempFile);
	printPostorder(root, tempFile);	
	
	fclose(inputPtr);
	destroyTree(root);	

	printf("The program run successfully! It is now terminating...\n");
	sleep(1);
	return EXIT_SUCCESS;



}
