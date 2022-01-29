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
				int sizeData = strlen(modifyData) + sizeof(struct node_t);
			
				struct node_t* newNode = (struct node_t*)malloc(sizeData);
				
				newNode->data = (char*)malloc(strlen(modifyData));
				if(newNode->data == NULL)
				{
					printf("ERROR: %s: failed to allocate memory\n",treeFile);
					return NULL;
				}	
							

				strcat(newNode->data, modifyData);
				printf("%s\n",newNode->data);
				newNode->left = NULL;
				newNode->right = NULL;
				newNode->middle = NULL;

				insertNode(temproot, newNode);
								
	
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

void insertNode(struct node_t *nodePtr, struct node_t *newNode)
{
	if(nodePtr == NULL)
		nodePtr = newNode;
	else if(newNode->data[0] < nodePtr->data[0])
		insertNode(nodePtr->left, newNode);
	else if(newNode->data[0] == nodePtr->data[0])
		insertNode(nodePtr->middle, newNode);
	else
		insertNode(nodePtr->right, newNode);

}

void destroyTree(struct node_t *nodePtr)
{
	if(nodePtr)
	{
		if(nodePtr->left)
			destroyTree(nodePtr->left);
		if(nodePtr->right)
			destroyTree(nodePtr->right);
		free(nodePtr->data);
		free(nodePtr);			
	}
}

