
#include <stdio.h>

#define NULL 0
#define ERR -1

extern char *_String;
extern int _Count;
extern utoi(), itod(), itou(), itox(), _outc();

_printf(fd, nxtarg)
int fd;
int *nxtarg;
{
    int i, prec, preclen, len;
    char c, right, str[7], pad;
    int width;
    char *sptr, *ctl, *cx;

    _Count = 0;
    ctl = *nxtarg;
}