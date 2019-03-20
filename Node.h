#ifndef NODE_H_
#define NODE_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef void (* callBack_t) (void);

typedef struct Node{
	callBack_t cb;
	char * cmd;
	float val;
	struct Node * child;
	struct Node * next;
}Node_t;

void Node_callback (callBack_t * cb);
bool  Node_hasChild (Node_t * node);
bool  Node_hasNext (Node_t * node);
Node_t * Node_getChild (Node_t * node);
Node_t * Node_getNext (Node_t * node);
void Node_addNext (Node_t* node, Node_t* nextNode);
void Node_addChild (Node_t* node, Node_t* childNode);
bool Node_isTerminal (Node_t * node);
bool Node_isTheSame (const char * cmd , const char * template);
bool Node_isFound (Node_t ** node , char const * commandName);
#endif /* NODE_H_ */
