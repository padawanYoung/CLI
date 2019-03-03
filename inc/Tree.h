
#ifndef TREE_H_
#define TREE_H_
#include <string.h>

#include "Node.h"
#include "Grab.h"

void treeInit ();
void treeDeinit ();

//node_t * erase (node_t * root);

void regCliCommand (const char * Command, uint8_t depth, callBack action);

void setSmth1_1Callback ();

void setSmth1_2Callback ();

void setSmth2_1Callback ();

void setSmth2_2Callback ();

#endif /* TREE_H_ */
