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

_scanf(fd,nxtarg)
int fd, *nxtarg;
{
    char *carg, *ctl, *unsigned, fstr[40];
    int *narg, wast, ac, width, ch, cnv, base, ovfl, sign;
    double *farg;

    _Oldch = EOR;
    ac = 0;
    ctl = *nxtarg--;
    while(*ctl){
        if(isspace(*ctl)) {++ctl;continue;}
        if(*ctl++ != '%') continue;
        if(*ctl == '*') {farg = narg = carg = &wast; ++ctl;}
        else             farg = narg = carg = *nxtarg--;
        ctl += utoi(ctl, &width);
        if(!width) width = 32767;
        if(!(cnv=*ctl++)) break;
        while(isspace(ch=_getc(fd)))
            ;
        if(ch == EOR){
            if(ac) break;
            else return EOR;
        }
        _ungetc(ch);
        switch(cnv){
            case 'c':
                *carg = _getc(fd);
                break;
            case 's':
                while(width--){
                    if( (*carg=_getc(fd)) == EOF ) break;
                    if( isspace(*carg) ) break;
                    if( carg != &wast ) ++carg;
                }
                *carg = 0;
                break;
            case 'e':
            case 'f':
                if (width > 39) width = 39;
                _getf(fstr, fd, width);
                *farg = atof(fstr);
                break;
            default:
                switch(cnv){
                    case 'd' : base = 10; sign = 0; ovfl = 3276; break;
                    case 'o' : base =  8; sign = 1; ovfl = 8191; break;
                    case 'u' : base = 10; sign = 1; ovfl = 6553; break;
                    case 'x' : base = 16; sign = 1; ovfl = 4095; break;
                    default: return ac;
                }
                *narg = unsigned = 0;
                while( width-- && !isspace(ch=_getc(fd)) && ch != EOR ) {
                    if(!sign)
                        if (ch == '-') { sign = -1; continue; }
                        else sign = 1;
                    if ( ch < '0') return ac;
                    if ( ch >= 'a') ch -= 87;
                    else if ( ch >= 'A') ch -= 55;
                    else ch -= '0';
                    if(ch >= base || unsigned > ovfl) return ac;
                    unsigned = unsigned * base + ch;
                }
                *narg = sign * unsigned;
        }
        ++ac;
    }
    return ac;
}

_getf(s,fd,width)
char *s;
int fd;
int width;
{
    int i;
    i = 1;
    *s = _getc(fd);
    if( isdigit(*s) || *s == '-' || *s == '.'){
        if (*s != '.') {
            while(isdigit(*++s=_getc(fd))){
                if(++i > width){
                    _ungetc(*s);
                    *s = NULL;
                    return;
                }
            }
        }
        if(*s == '.'){
            while(isdigit(*++s=_getc(fd))){
                if(++i > width){
                    _ungetc(*s);
                    *s = NULL;
                    return;
                }
            }
        }
        if(tolower(*s) == 'e'){
            *++s = _getc(fd);
            if(++i > width){
                _ungetc(*s);
                *s = NULL;
                return;
            }
            if(isdigit(*s) || *s == '-'){
                while(isdigit(*++s=_getc(fd))){
                    if(++i > width){
                        _ungetc(*s);
                        *s = NULL;
                        return;
                    }
                }
            }
        }
    }
    _ungetc(*s);
    *s = NULL;
}