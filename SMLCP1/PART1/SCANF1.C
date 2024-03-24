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
        ctl += utoi(ctl, &width);
        if(!width) width = 32767;
        if(!(cnv=*ctl++)) break;
        while(isspace(ch=_getc(fd)))
            ;
        if(ch == EOF){
            if(ac) break;
            else return EOF;
        }
        _ungetc(ch);
        switch(cnv) {
            case 'c':
                *carg = _getc(fd);
                break;
            case 's':
                while(width--){
                    if((*carg=_getc(fd)) == EOF) break;
                    if(isspace(*carg)) break;
                    if(carg != &wast) ++carg;
                }
                *carg = 0;
                break;
            default:
                switch(cnv){

                }
                *narg = unsigned = 0;
                while(width-- && !isspace(ch=_getc(fd)) && ch != EOR){

                }
                *narg = sign * unsigned;
        }
        ++ac;
    }
    return ac;
}