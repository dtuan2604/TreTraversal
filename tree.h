#ifndef _TREE_H
#define _TREE_H
#include "node.h"

node_t *buildTree(FILE *inputPtr);
void insert(node_t *rootNode, node_t *newNode);

void printInorder(char* fileName);
void printPreorder(char* fileName);
void printPostorder(char* fileName);



#endif
