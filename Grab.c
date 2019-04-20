/*
 * Grab.c
 */
#include "Grab.h"
bool isReadingDone = false; // IRD Flag

bool Grab_getIRD_Flag()
{
	return isReadingDone;
}

void Grab_setIRD_Flag(bool status)
{
	isReadingDone = status;
}

char *Grab_cmd_FILE(FILE *pointer)
{
	char *string = NULL;
	// char *temp_string;
	int i = 0;
	int j = 1;
	int temp = 0;
	string = (char *)malloc(sizeof(char));
	while (/*(temp != (int)_SeparateSymbol) && */ (temp != (int)_NewLineSymbol))
	{
		temp = getc(pointer);
		string = (char *)realloc(string, sizeof(char) * ++j);
		string[i] = (char)temp;
		i++;
	}
	string[i - 1] = '\0';
	fflush(pointer);
	return string;
}

char *Grab_cmd(const char *expression)
{
	char *cmd = NULL;
	uint8_t j = 1;
	uint32_t i = Counter_get();
	uint8_t p = 0;
	if ((*(expression + i)) && !Grab_getIRD_Flag())
	{
		cmd = (char *)malloc(sizeof(char));
		while ((*(expression + i)) && (int)*(expression + i) != _SeparateSymbol)
		{
			cmd = (char *)realloc(cmd, sizeof(char) * ++j);
			*(cmd + p) = *(expression + i);
			p++;
			Counter_increase();
			i = Counter_get();
		}
		*(cmd + p) = '\0';
		Counter_increase();
	}
	if (!*(expression + i))
	{
		Counter_reset();
		Grab_setIRD_Flag(true);
	}
	return cmd;
}

bool Grab_value(const char *expression, float *value)
{
	uint32_t i = Counter_get();
	if (*(expression + i))
	{
		int status = sscanf((expression + i), "%f", value);
		if (status == 0 )
		{
			return false;
		}
		return true;
	}
	else
	{
		Counter_reset();
		Grab_setIRD_Flag(true);
	}
	return false;
}
