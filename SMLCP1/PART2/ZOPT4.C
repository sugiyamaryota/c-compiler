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