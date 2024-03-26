#include <ctype.h>
#include <stdio.h>
#include "float.h"

#define NULL 0
#define ERR (-1)

extern int _Oldch
extern int _getc(), _ungetc(), utoi();

atof(s)
char s[];
{
    double sum,
        scale;
    char *start,
        *end,
        c;
    int minus,
        dot,
        decimal;

    if(*s == '-') {minus = 1; ++s;}
    else minus = 0;
    start = s;
    decimal = 0;
    while((dot=(*s=='.')) || isdigit(*s)) {
        if(dot) ++decimal;
        ++s;
    }
    end = s;
    sum = 0.0;
}