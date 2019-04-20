#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdbool.h>
#include <stdlib.h>
#include "Counter.h"

bool Buffer_isEmpty();
void Buffer_Write(char *ptr);
char *Buffer_Read();
void Buffer_Clean();

#endif /* BUFFER_H_ */