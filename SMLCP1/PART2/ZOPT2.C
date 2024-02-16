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
                else if ( strcmp(Ldhl4, ln1) == 0){
                    c_write(Popde);
                    c_write(Popbc);
                }
                else if ( strcmp(Ldhl2,ln1) == 0 ) {
                    c_write(Popbc);
                }
                c_write(Pophl);
                c_write(ln5);
                if( strcmp(Ldhl6, ln1) == 0 ) {
                    c_write(Pushhl);
                    c_write(Pushbc);
                    c_write(Pushde);
                    strcpy(ln1,Pushix);
                    ++saved[3];
                }
                else if ( strcmp(Ldhl4,ln1) == 0 ) {
                    c_write(Pushhl);
                    c_write(Pushbc);
                    strcpy(ln1,Pushde);
                    ++saved[2];
                }
                else if( strcmp(Ldhl2,ln1) == 0 ) {
                    c_write(Pushhl);
                    strcpy(ln1,Pushbc);
                    ++saved[1];
                }
                else {
                    strcpy(ln1,Pushhl);
                    ++saved[0];
                }
                p_read(ln2);
                p_read(ln3);
                p_read(ln4);
                p_read(ln5);
                p_read(ln6);
            }
        }

        if(strcmp(Exdehl,ln1) == 0 &&
            (arg=match(Ldhl,ln2)) &&
            (strcmp("\tCALL cceq",ln3) == 0 || strcmp("\tCALL ccne",ln3) == 0 ))

        if(strcmp("\tLD A,H",ln4) == 0 &&
            strcmp("\tOR L",ln5) == 0 &&
            ((tail=match("\tJP NZ,", ln6)) || (tail=match("\tJP Z,",ln6)))) {
            if( (i=chk_arg(arg)) != 0){
                if(strcmp("\tCALL cceq",ln3) == 0) {
                    if(match("\tJP NZ,",ln6)){
                        strcpy(line,"\tJP Z,");
                    }
                    else {
                        strcpy(line,"\tJP NZ,");
                    }
                    strcat(line,tail);
                    strcpy(ln6,line);
                }
                temp = ln1;
                temp2 = ln2;
                temp3 = ln3;
                ln1 = ln4;
                ln2 = ln5;
                ln3 = ln6;
                ln4 = temp;
                ln5 = temp2;
                ln6 = temp3;
                p_read(ln4);
                p_read(ln5);
                p_read(ln6);
                ++saved[3+i];
            }
        }

    }
}