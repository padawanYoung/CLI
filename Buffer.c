#include "Buffer.h"

char *Buffer = NULL;

bool Buffer_isEmpty()
{
    return (Buffer == NULL);
}

void Buffer_Write(char *ptr)
{
    Buffer = ptr;
}

char *Buffer_Read()
{
    return Buffer;
}

void Buffer_Clean()
{
    Counter_reset();
    free(Buffer);
    Buffer = NULL;
}