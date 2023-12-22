#include <stdio.h>
#include <string.h>

strrchr(string, c)
char *string, c;
{
    char *ptr;
    ptr = 0;
    while(*string) {
        if(*string == c) ptr = string;
        ++string;
    }
    return ptr;
}