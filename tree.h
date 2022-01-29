#ifndef _TREE_H
#define _TREE_H
#include "node.h"

struct node_t *buildTree(FILE *inputPtr);
void insertNode(struct node_t **nodePtr, struct node_t *newNode);

void destroyTree(struct node_t *nodePtr);

void printInorder(struct node_t *root,char* fileName);
void printPreorder(struct node_t *root, char* fileName);
void printPostorder(struct node_t *root, char* fileName);

void traverseInorder(struct node_t *nodePtr, int level, FILE *fp);
void traversePreorder(struct node_t *nodePtr, int level, FILE *fp);
void traversePostorder(struct node_t *nodePTr, int level, FILE *fp);



#endif
