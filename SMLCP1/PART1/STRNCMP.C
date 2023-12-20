#include <stdio.h>
#include <string.h>

strncmp(s,t,n)
char *s, *t;
int n;
{
    while(n!=0 & *s==*t) {
        if(*s==0) return 0;
        ++s;
        ++t;
        --n;
    }
    if(n) return *s - *t;
    return 0;
}