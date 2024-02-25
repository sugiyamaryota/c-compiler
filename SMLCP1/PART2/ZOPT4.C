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