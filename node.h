#ifndef _NODE_H
#define _NODE_H

struct node_t
{
	char* data;
	struct node_t* left;
	struct node_t* middle;
	struct node_t* right;
};

#endif
