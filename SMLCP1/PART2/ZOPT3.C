#include <stdio.h>
#include <string.h>
#include "zopt.h"

pass3()
{
    int i, saved[9];
    char *temp, *tail;
    char *last, *this, *next;

    switch_down(1);

    saved[0] = saved[1] = saved[2] = saved[3] = saved[4] = 0;
    saved[5] = saved[6] = saved[7] = saved[8] = i = 0;

    last = alloc(LINELEN);
    this = alloc(LINELEN);
    next = alloc(LINELEN);

    p_read(last);
    p_read(this);

    while( p_read(next) ) {
        if( strcmp(Exdehl,last) == 0 ){
            if(tail=match(Ldhl,this)){
                if(strcmp("\tCALL ccasl", next) == 0){
                    if(strlen(tail) == 1 && allnum(tail)){
                        switch (*tail){
                            case '7': c_write(Addhlhl);
                                      --saved[1];
                            case '6': c_write(Addhlhl);
                                      --saved[1];
                            case '5': c_write(Addhlhl);
                                      --saved[1];
                            case '4': c_write(Addhlhl);
                                      --saved[1];
                            case '3': c_write(Addhlhl);
                                       --saved[1];
                            case '2': c_write(Addhlhl);
                                      --saved[1];
                            case '1': strcpy(last,Addhlhl);
                                      saved[1] += 6;
                                      ++i;
                                      p_read(this);
                                      p_read(next);
                                      break;
                            case '9': c_write(Addhlhl);
                                      --saved[1];
                            case '8': strcpy(last,"\tLD H,L");
                                      strcpy(this,"\tLD L,0");
                                      p_read(next);
                                      ++i;
                                      saved[1] += 4;
                                      break;
                            case '0': p_read(last);
                                      p_read(this);
                                      p_read(next);
                                      saved[1] += 7;
                                      ++i;
                                      break;
                        }
                    }
                }
                else if(strcmp("\tCALL ccasr",next) == 0 &&
                            strcmp("8",tail) == 0) {
                    strcpy(last,"\tLD A,H");
                    strcpy(this,"\tCALL ccsxt");
                    p_read(next);
                    saved[1] += 3;
                    ++i;
                }
            }
        }
    }
}