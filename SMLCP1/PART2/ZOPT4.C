#include <stdio.h>
#include <string.h>
#include "zopt.h"

uncomma(string, token1, token2)
char *string, *token1, *token2;
{
    int i;
    while( *string != ',')
        *token1++ = *string++;
    *token1 = 0;
    ++string;
    i = 0;
    while( (*string != NULL) & (i < 19) ) {
        *token2++ = *string++;
        ++i;
    }
    *token2 = 0;
}

jumps(s1, s2, s3, save, last, this, next)
char *s1;
char *s2;
char *s3;
int *save;
char **last;
char **this;
char **next;
{
    char line[LINELEN], *temp, *tail;

    if( tail=match(s1,*last) ){
        if(tail=match(tail,*next)){
            if(*tail == ':'){
                if(tail=match(s2, *this)){
                    if(islower(*tail)){
                        strcpy(line,s3)
                        strcat(line,tail)
                        strcpy(*last,line)
                        temp = *this;
                        *this = *next;
                        *next = temp;
                        p_read(*next);
                        ++(*save);
                    }
                }
            }
        }
    }
}

pass4()
{
    int i, saved[7];
    char source1[20], source2[20], dest1[20], dest2[20];
    char line[LINELEN];
    char *tail, *tail2, *temp;
    char *last, *this, *next;

    switch_down(1);
    saved[0] = saved[1] = saved[2] = saved[3] = saved[4] = 0;
    saved[5] = saved[6] = 0;

    last = alloc(LINELEN);
    this = alloc(LINELEN);
    next = alloc(LINELEN);

    p_read(last);
    p_read(this);

    
}