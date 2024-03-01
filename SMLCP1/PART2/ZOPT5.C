#include <stdio.h>
#include <string.h>
#include "zopt.h"

char *l1, *l2, *l3, *l4, *l5, *l6, *l7, *l8, *l9, *l10;

pass5()
{
    int saved[2];
    int i;
    char *tail, *tail2, *temp;

    saved[0] = saved[1] = 0;

    l1 = alloc(LINELEN);
    l2 = alloc(LINELEN);
    l3 = alloc(LINELEN);
    l4 = alloc(LINELEN);
    l5 = alloc(LINELEN);
    l6 = alloc(LINELEN);
    l7 = alloc(LINELEN);
    l8 = alloc(LINELEN);
    l9 = alloc(LINELEN);
    l10 = alloc(LINELEN);

    p_read(l1);
    p_read(l2);
    p_read(l3);
    p_read(l4);
    p_read(l5);
    p_read(l6);
    p_read(l7);
    p_read(l8);
    p_read(l9);

    while(p_read(l10)) {
        
    }
}