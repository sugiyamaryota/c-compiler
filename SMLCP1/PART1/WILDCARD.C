#include <stdio.h>

#define MAXFILES 64

char _dma[128];
char **_file;

wildcard(spec)
char *spec;
{
    char fcb[36];
    char ch;
    int code;
    int i;

    i = 1;
    while(ch = *spec++){
        if(ch != '.'){
            fcb[i++] = ch;
        }
    }
    fcb[0] = 0;
    fcb[12] = 0;

    cpm(26, _dma);
    i = 0;
    if( (code=cpm(17, fcb)) == -1){
        return 0;
    }
    _file = alloc(MAXFILES*2);
    _store(code, &i);
    while( (code=cpm(18,fcb)) != -1 && i < MAXFILES-1){
        _store(code, &i);
    }
    cpm(26, 128);
    _file[i] = 0;
    return _file;
}

_store(offset, num)
int offset;
int *num;
{
    char *name;
    char *ptr;
    int i;
    name = _dma + (offset << 5) +1;
    ptr = alloc(13);
    _file[*num] = ptr;
    *num += 1;
    for( i=0; i<12; ++i){
        if(i != 8){
            if(*name != ' ')
                *ptr++ = *name++ & 0x7f;
            else
                ++name;
        }
        else
            *ptr++ = '.';
    }
    *ptr = 0;
}