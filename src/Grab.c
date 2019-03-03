/*
 * Grab.c
 *
 *  Created on: 15 февр. 2019 г.
 *      Author: Serhii
 */
#include "Grab.h"

char * getString (const char * expression){
	char * cmd;
	int SeparateSymbol = 32; // space
	uint8_t j = 1;
	uint32_t i = getCounter0();
	uint8_t p = 0;
	cmd = (char*) malloc(sizeof(char));
	while (*(expression + i) && ((int)*(expression + i) != SeparateSymbol)){
		cmd = (char*) realloc(cmd, sizeof(char)*j++);
		*(cmd+p) = *(expression + i);
		p++;
		increaseCounter0();
		i = getCounter0();
	}
	*(cmd + p) = '\0';
	increaseCounter0();
	if(!*(expression + i)){
		resetCounter0();
	}
	return cmd;
}

float getValue (const char * expression){
	float value;
	uint32_t i = getCounter0();
	expression+=i;
	sscanf(expression, "%f", &value);
	resetCounter0();
	return value;
}
