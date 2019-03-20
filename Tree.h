
#ifndef TREE_H_
#define TREE_H_

#include <string.h>
#include <stdlib.h>
#include "Node.h"
#include "Grab.h"

typedef enum{
    Resume,
    Shutdown
}Tree_Flags_t;

void Tree_Init();
void Tree_DeInit();
void Tree_RegCommand(const char *Command, float value, callBack_t action);
void Tree_ExecuteCommand ();
void Tree_Run_CLI ();

void set_Callback();
void get_Callback();
void shutDown_Callback ();
#endif /* TREE_H_ */
