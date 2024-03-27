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
    if(decimal){
        --s;
        while(*s != '.')
            sum = (sum + float(*(s--) - '0')) /10.0;
    }
    scale = 1.0;
    while(--s >= start){
        sum += scale * float(*s-'0')
        scale *= 10.0;
    }
    c = *end++;
    if(tolower(c)=='e'){
        int neg;
        int expon;
        int k;
        neg = expon = 0;
        if(*end == '-'){
            neg = 1;
            ++end;
        }
        while(1){
            if((c=*end++) >= '0'){
                if(c <= '9'){
                    expon = expon * 10 + c - '0';
                    continue;
                }
            }
            break;
        }
        if(expon > 38){
            puts("overflow");
            expon = 0;
        }
        k = 32;
        scale = 1.0;
        while(k){
            scale *= scale;
            if(k & expon) scale *= 10.0;
            k >>= 1;
        }
        if(neg) sum /= scale;
        else sum *= scale;
    }
    if(minus) sum = -sum;
    return sum;
}