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