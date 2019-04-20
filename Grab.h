/*
 * Grab.h
 */
#ifndef GRAB_H_
#define GRAB_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Counter.h"
#define _SeparateSymbol 32  // SPASE
#define _NewLineSymbol  10 // new line



bool Grab_getIRD_Flag ();
void Grab_setIRD_Flag (bool status);
char * Grab_cmd_FILE (FILE *pointer);
char * Grab_cmd (const char * expression);
bool Grab_value(const char *expression, float * value);
#endif /* GRAB_H_ */
