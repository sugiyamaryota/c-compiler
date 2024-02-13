#include <stdio.h>
#include <string.h>
#include "zopt.h"

pass1()
{
    int i;
    int saved[5];
    char *temp;
    char *tail,*tail2;
    char *last,*this,*next;

    switch_down(1)
    saved[0] = saved[1] = saved[2] = saved[3] = saved[4] =0

    last = alloc(LINELEN);
    this = alloc(LINELEN);
    next = alloc(LINELEN);

    getline(last);
    getline(this);

    while( getline(next) ){

        if( strcmp(Pushhl, last) == 0 ){
            if( strcmp(Popde, next) == 0){
                if( match(Ldhl,this) ) {
                    strcpy(last, Exdehl);
                    getline(next);
                    ++saved[1];
                }
            }
        }

        if( strcmp(Ldhl0,last) == 0 ){
            if( strcmp("\tAdd HL,SP", this) == 0 ) {
                if( strcmp("\tCALL ccgint", next) == 0 ){
                    strcpy(last, Pophl);
                    strcpy(this, Pushhl);
                    getline(next);
                    ++saved[2];
                }
            }
        }

        if( strcmp(Ldhl2,last) == 0 ){
            if( strcmp("\tAdd HL,SP", this) == 0 ) {
                if( strcmp("\tCALL ccgint", next) == 0 ){
                    c_write(Popbc);
                    strcpy(last, Pophl);
                    strcpy(this, Pushhl);
                    strcpy(next, Pushbc);
                    ++saved[3];
                }
            }
        }

        if( (tail=match("\tPUSH", this)) ){
            if( (tail2=match("\tPOP", next)) ) {
                if( strcmp(tail, tail2) == 0 ){
                    getline(this);
                    getline(next);
                    ++saved[0];
                }
            }
        }

        if( strcmp("\tCALL dload", this) == 0 ){
            if( strcmp("\tCALL dpush", next) == 0 ) {
                strcpy(this, "\tCALL dpush")
                getline(next);
                ++saved[4];
            }
        }

        c_write(last);
        temp = last;
        last = this;
        this = next;
        next = temp;
        if (cpm(CONIN, 255) == CTRLC) exit()
    }
    c_write(last);
    c_write(this);

    puts("Remove PUSH x, POP x"); putdec(saved[0]);
    putchar('\n');
    puts("PUSH HL, POP DE round LD HL:"); putdec(saved[1]);
    putchar('\n');
    puts("Fetch top of stack:"); putdec(saved[2]);
    putchar('\n');
    puts("Fetch 2nd top of stack:"); putdec(saved[3]);
    putchar('\n');
    puts("dload; dpush -> dldpsh"); putdec(saved[4]);
    putchar('\n');
    putchar('\n');
    i = saved[0]*2 + saved[1] + saved[2]*5 + saved[3]*3 + saved[4]*3;
    pr_total(i);

    Total += i;
}