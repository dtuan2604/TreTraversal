#ifndef _NODE_H
#define _NODE_H

typedef struct Node
{
	char* data;
	struct node_t* left;
	struct node_t* right;
	struct node_t* middle;
} node_t;

#endif
