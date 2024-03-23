#include <ctype.h>
#include <stdio.h>

#define NULL 0
#define ERR (-1)

extern int _Oldch;
extern _getc(), _ungetc(), utoi();

_scanf(fd, nxtarg)
int fd, *nxtarg;
{
    char *carg, *ctl, *unsigned;
    int *narg, wast, ac, width, ch, cnv, base, ovfl, sign;

    _Oldch = EOR;
    ac = 0;
    ctl = *nxtarg--;
    while(*ctl){
        if(isspace(*ctl)) {++ctl; continue;}
        if(*ctl++ != '%') continue;
        if(*ctl == '*') {narg = carg = &wast; ++ctl;};
        else             narg = carg = *nxtarg--;

    }
}