#include <stdio.h>
#include <string.h>

strchr( string, c)
char *string, c;
{
    while(*string) {
        if(*string == c) return string;
        ++string;
    }
    return 0;
}