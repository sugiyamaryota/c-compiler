#include <stdio.h>
#include <stype.h>

#define NULL 0
#define ERR (-1)

char *_String1;
int _Oldch;

scanf(args)
int args;
{
    _String1 = NULL;
    return(_scanf(stdin, _argcnt() + &args - 1));
}

fscanf(args)
int args;
{
    int *nxtarg;
    _String1 = NULL;
    nxtarg = _argcnt() + &args;
    return(_scanf(*(--nxtarg), --nxtarg));
}

sscanf(args)
int args;
{
    int *nxtarg;
    nxtarg = _argcnt() + &args - 1;
    _String1 = *nxtarg;
    return(_scanf(stdout, --nxtarg));
}