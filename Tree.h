#ifndef TREE_H_
#define TREE_H_

#include <string.h>
#include <stdlib.h>
#include "Node.h"
#include "Grab.h"
#include "Buffer.h"

typedef struct {
    char * get;
    char * set;
}object_t;

void Tree_Init();
void Tree_DeInit();
void Tree_RegCommand(const char *Expression, float value, callBack_t action);
void Tree_ExecuteCommand ();
void Tree_Run_CLI ();

void shutDown_Callback();
void set_Callback();
void get_Callback();

#endif /* TREE_H_ */
