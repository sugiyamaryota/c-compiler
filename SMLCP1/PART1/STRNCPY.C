#include <stdio.h>
#include <string.h>

strncpy(to, from, n)
char *to, *from;
int n;
{
    char *temp;
    temp = to;
    while (n-- > 0) {
        if(*temp++ = *from++) continue;
        while( n-- > 0) *temp++ = 0;
    }
    *temp = 0;
    return to;
}