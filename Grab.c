/*
 * Grab.c
 */
#include "Grab.h"
bool isReadingDone = false; // IRD Flag

bool Grab_getIRD_Flag (){
	return isReadingDone;
}
void Grab_setIRD_Flag (bool status){
	isReadingDone = status;
}
char * Grab_cmd_FILE(FILE *pointer) {
	char * string;
    int i = 0;
    int j = 1;
    int temp = 0;
    string = (char *) malloc(sizeof(char));
    while ((temp != (int)_SeparateSymbol) && (temp != (int)_NewLineSymbol)) {
        temp = getc(pointer);
        string = (char *) realloc(string, sizeof(char) * ++j);
        string[i] = (char) temp;
        i++;
    }
    string[i - 1] = '\0';
	Grab_setIRD_Flag(false);
	if (temp == (int)_NewLineSymbol) {
		Grab_setIRD_Flag(true);
		fflush(pointer);
	}
    return string;
}

char * Grab_cmd (const char * expression){
	char * cmd = NULL;
	uint8_t j = 1;
	uint32_t i = Counter_get();
	uint8_t p = 0;
	cmd = (char*) malloc(sizeof(char));
	while (*(expression + i) && ((int)*(expression + i) != _SeparateSymbol)){
		cmd = (char*) realloc(cmd, sizeof(char)*++j);
		*(cmd+p) = *(expression + i);
		p++;
		Counter_increase();
		i = Counter_get();
	}
	*(cmd + p) = '\0';
	Counter_increase();
	if(!*(expression + i)){
		Grab_setIRD_Flag(true);
		Counter_reset();
	}
	return cmd;
}

float Grab_value (const char * expression){
	float value;
	uint32_t i = Counter_get();
	expression+=i;
	sscanf(expression, "%f", &value);
	Counter_reset();
	return value;
}
