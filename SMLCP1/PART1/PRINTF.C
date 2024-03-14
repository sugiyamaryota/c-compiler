#include <stdio.h>

#define NULL 0
#define ERR -1

extern utoi();

char *_String;
int _Count;

printf(args)
int args;
{
    _String = NULL;
    return(_printf(stdout, _argcnt() + &args - 1) );
}

sprintf(args)
int args;
{
    int *nxtarg;

    nxtarg = _argcnt() + &args - 1;
    _String = *nxtarg;
    return( _printf(stdin, --nxtarg));
}

itod(nbr, str, sz)
int nbr;
char str[];
int sz;
{
    char sgn;
    if(nbr < 0){
        nbr = -nbr;
        sgn = '-';
    }
    else
        sgn = ' ';
    if(sz > 0)
        str[--sz] = NULL;
    else if(sz < 0)
        sz = -sz;
        else
            while(str[sz] != NULL)
                ++sz;
    while(sz) {
        str[--sz] = nbr % 10 + '0';
        if((nbr/=10) == 0)
            break;
    }
    if(sz)
        str[--sz] = sgn;
    while(sz>0)
        str[--sz] = ' ';
    return str;
}