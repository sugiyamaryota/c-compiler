#include <stdio.h>

fgets(s,n,iop)
char *s;
int n;
FILE *iop;
{
    int c;
    char *cs;
    cs = s;
    while(--n > 0 && (c=getc(iop) != EOF)){
        if( (*cs++ = c) == '\n')
        break;
    }
    *cs = '\0';
    return ( (c == EOF && cs == s) ? 0 : s);
}