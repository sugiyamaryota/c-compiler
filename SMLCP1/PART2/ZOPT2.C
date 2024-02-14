#include <stdio.h>
#include <string.h>
#include "zopt.h"

char *ln1, *ln2,*ln3,*ln4,*ln5,*ln6;

pass2()
{
    int saved[12];
    int i;
    char line[LINELEN];
    char *tail, *arg, *temp, *temp2, *temp3;

    switch_down(1);

    saved[0] = saved[1] = saved[2] = saved[3] = 0;
    saved[4] = saved[5] = saved[6] = saved[7] = saved[8] = 0;
    saved[9] = saved[10] = saved[11] = 0;

    ln1 = alloc(LINELEN);
    ln2 = alloc(LINELEN);
    ln3 = alloc(LINELEN);
    ln4 = alloc(LINELEN);
    ln5 = alloc(LINELEN);
    ln6 = alloc(LINELEN);

    p_read(ln1);
    p_read(ln2);
    p_read(ln3);
    p_read(ln4);
    p_read(ln5);

    while( p_read(ln6) ){
        if( strcmp(Ldhl0, ln1) == 0 ||
            strcmp(Ldhl2, ln1) == 0 ||
            strcmp(Ldhl4, ln1) == 0 ||
            strcmp(Ldhl6, ln1) == 0 ){

            if( strcmp("\tADD HL,SP", ln2) == 0 &&
                strcmp(Pushhl, ln3) == 0 &&
                strcmp("\tCALL ccgint", ln2) == 0 &&
                (strcmp(Inchl, ln5) == 0 || strcmp(Dechl, ln5) == 0) &&
                strcmp("\tCALL ccgint", ln6) == 0 &&){

                if( strcmp(Ldhl6,ln1) == 0 ){
                    c_write(Popix);
                    c_write(Popde);
                    c_write(Popbc);
                }
            }
        }
    }
}