#include "main.h"

int main (void){
	Tree_Init ();
	Tree_RegCommand("shutdown",0,&shutDown_Callback);

	Tree_Run_CLI();
	Tree_DeInit();
	return 0;
}
