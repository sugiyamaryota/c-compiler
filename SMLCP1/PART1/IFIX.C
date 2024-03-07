#include <stdio.h>
#include "float.h"
#asm
;
;   convert the floating point number in FA
;   to an integer in hl (rounds toward negative numbers)
;
QIFIX:  CALL QFLOOR         ;take floor first
    LD HL,0     ; initialize the result
    LD A,(FA+5) ; get the exponent
    LD B,A      ; and save it
    OR A
    RET Z       ; z => number was zero
    LD  HL,(FA+3); get most significant bits
    LD C,H      ;save sign bit (msb)
    LD A,B      ;get exponent again
    CP 80H+16
    JP M,IFIX5  ;m => fabs(fa) < 32768
    JP NZ,OFLOW ;nz => fabs(fa) > 32768
            (overflow)