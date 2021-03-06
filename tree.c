#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <string.h>
#include "helper.h"
#include <ctype.h>

char* treeFile = "tree.h";

struct node_t *buildTree(FILE * inputPtr)
{
	char input;
	char tempData[BUFFER] = {"\0"};
	struct node_t *temproot = NULL;

	while(input != EOF)
	{
		if(isspace(input) != 0)
		{
			if(tempData[0] != '\0')
			{
				char* modifyData = stringToData(tempData);
				int sizeData = sizeof(modifyData) + sizeof(struct node_t);
			
				struct node_t* newNode = (struct node_t*)malloc(sizeData);
				if(newNode == NULL)
			        {
                			printf("ERROR: %s: failed to allocate memory\n",treeFile);
                			return NULL;

        			}

				newNode->data = (char*)malloc(sizeof(modifyData));
				if(newNode->data == NULL)
				{
					printf("ERROR: %s: failed to allocate memory\n",treeFile);
					return NULL;
				}	
							

				strcpy(newNode->data, modifyData);
				newNode->left = NULL;
				newNode->right = NULL;
				newNode->middle = NULL;

				insertNode(&temproot, newNode);
								
	
				memset(tempData,'\0',strlen(tempData));
			}
		}	
		else
		{
			strncat(tempData, &input, 1);
		}
		
		input = fgetc(inputPtr);
	}
	
	
	return temproot;	
}

void insertNode(struct node_t **nodePtr, struct node_t *newNode)
{
	if(*nodePtr == NULL)
		*nodePtr = newNode;
	else if(newNode->data[0] < (*nodePtr)->data[0])
		insertNode(&((*nodePtr)->left), newNode);
	else if(newNode->data[0] == (*nodePtr)->data[0])
		insertNode(&((*nodePtr)->middle), newNode);
	else
		insertNode(&((*nodePtr)->right), newNode);

}

void destroyTree(struct node_t *nodePtr)
{
	if(nodePtr)
	{
		if(nodePtr->left)
			destroyTree(nodePtr->left);
		if(nodePtr->middle)
			destroyTree(nodePtr->middle);
		if(nodePtr->right)
			destroyTree(nodePtr->right);
		free(nodePtr->data);
		free(nodePtr);
		nodePtr->data = NULL;
		nodePtr = NULL;			
	}
}

void printPreorder(struct node_t *root, char* fileName)
{
	char* exten = ".preorder";
	char* outputFile = (char*)malloc(sizeof(fileName) + sizeof(exten));
	if(outputFile == NULL)
	{
		fprintf(stderr,"ERROR: %s: Cannot allocate memory\n", treeFile);
		return;
	}			
	
	strcpy(outputFile,fileName);
	strcat(outputFile,exten);

	FILE *fp = fopen(outputFile, "w");
	
	if(fp == NULL)
	{
		fprintf(stderr,"ERROR: %s: Cannot open file\n",treeFile);
                return;
	}

	traversePreorder(root, 0,fp); 

	fclose(fp);
	free(outputFile);	
}

void traversePreorder(struct node_t *nodePtr, int level, FILE * fp)
{
	if(nodePtr != NULL)
	{
		writeFile(fp,"%*s", level * 2,"");
		writeFile(fp,"%s\n", nodePtr->data);
		
		traversePreorder(nodePtr->left, level + 1, fp);
		traversePreorder(nodePtr->middle, level + 1, fp);
		traversePreorder(nodePtr->right, level + 1, fp); 		
	}		
}

void printInorder(struct node_t *root, char* fileName)
{
        char* exten = ".inorder";
        char* outputFile = (char*)malloc(sizeof(fileName) + sizeof(exten));
        if(outputFile == NULL)
        {
                fprintf(stderr,"ERROR: %s: Cannot allocate memory\n", treeFile);
                return;
        }

        strcpy(outputFile,fileName);
        strcat(outputFile,exten);

        FILE *fp = fopen(outputFile, "w");

        if(fp == NULL)
        {
                fprintf(stderr,"ERROR: %s: Cannot open file\n",treeFile);
                return;
        }

        traverseInorder(root, 0,fp);

        fclose(fp);
        free(outputFile);
}

void traverseInorder(struct node_t *nodePtr, int level, FILE * fp)
{
        if(nodePtr != NULL)
        {
                traverseInorder(nodePtr->left, level + 1, fp);
		
		writeFile(fp,"%*s", level * 2,"");
                writeFile(fp,"%s\n", nodePtr->data);

                traverseInorder(nodePtr->middle, level + 1, fp);
                traverseInorder(nodePtr->right, level + 1, fp);
        }
}

void printPostorder(struct node_t *root, char* fileName)
{
        char* exten = ".postorder";
        char* outputFile = (char*)malloc(sizeof(fileName) + sizeof(exten));
        if(outputFile == NULL)
        {
                fprintf(stderr,"ERROR: %s: Cannot allocate memory\n", treeFile);
                return;
        }

        strcpy(outputFile,fileName);
        strcat(outputFile,exten);

        FILE *fp = fopen(outputFile, "w");

        if(fp == NULL)
        {
                fprintf(stderr,"ERROR: %s: Cannot open file\n",treeFile);
                return;
        }

        traversePostorder(root, 0,fp);

        fclose(fp);
        free(outputFile);
}

void traversePostorder(struct node_t *nodePtr, int level, FILE * fp)
{
        if(nodePtr != NULL)
        {
                traversePostorder(nodePtr->left, level + 1, fp);
		traversePostorder(nodePtr->middle, level + 1, fp);
                traversePostorder(nodePtr->right, level + 1, fp);

                writeFile(fp,"%*s", level * 2,"");
                writeFile(fp,"%s\n", nodePtr->data);
        }
}


