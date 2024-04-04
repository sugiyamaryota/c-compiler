#include <stdio.h>
#include <string.h>

strncat(to, from, n)
char *to, *from;
int n;
{
    char *temp;
    temp = to;
    --to;
    while(*++to);
    while(n--){
        if(*to++ = *from++) continue;
        return temp;
    }
    *to = 0;
    return temp;
}