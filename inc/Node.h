/*
 * Node.h
 *
 *  Created on: 15 ����. 2019 �.
 *      Author: Serhii
 */

#ifndef NODE_H_
#define NODE_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {Next,Child,Current}typeOfNode;
typedef unsigned int HashType;
typedef void (* callBack) (void);

typedef struct node{
	callBack cb;
	char * cmd;
	float val;
	bool isTerminalNode;
	struct node * childNode;
	struct node * parentNode;
	struct node * nextNode;
	struct node * prevNode;
}node_t;

bool hasParentNode(node_t * node);
bool  hasChildNode (node_t * node);
bool hasPrevNode(node_t * node);
bool  hasNextNode (node_t * node);
node_t * getParentNode (node_t * node);
node_t * getChildNode (node_t * node);
node_t * getPrevNode (node_t * node);
node_t * getNextNode (node_t * node);
void addNextNode (node_t* node, node_t* nextNode);
void addChildNode (node_t* node, node_t* child);
bool isTheSameNode (node_t * node, node_t * template);
bool isNodeFound (node_t ** node, node_t * template);
#endif /* NODE_H_ */
