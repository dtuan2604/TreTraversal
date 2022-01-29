#ifndef _TREE_H
#define _TREE_H
#include "node.h"

struct node_t *buildTree(FILE *inputPtr);
void insertNode(struct node_t *nodePtr, struct node_t *newNode);

void destroyTree(struct node_t *nodePtr);

void printInorder(struct node_t *nodePtr);
void printPreorder(struct node_t *nodePtr);
void printPostorder(struct node_t *nodePtr);



#endif
