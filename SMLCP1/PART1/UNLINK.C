#include <stdio.h>

extern _newfcb();

unlink(name)
char *name;
{
    char fcb[36];
    if(_newfcb(name, fcb) == 0)
        return -1;
    if(cpm(19,fcb) != 0)
        return -1;
    return 0;
}