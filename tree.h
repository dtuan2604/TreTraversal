#ifndef _TREE_H
#define _TREE_H
#include "node.h"

node_t *root;

node_t *buildTree(FILE *inputPtr);
void printInorder(char* fileName);
void printPreorder(char* fileName);
void printPostorder(char* fileName);



#endif
