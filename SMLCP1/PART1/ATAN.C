#include <stdio.h>
#include <math.h>
#include "float.h"

#asm
;
;  transcendental floating point routines
;
QATAN: CALL SGN
    CALL  M,ODD  ;negate argument & answer
    LD A,(FA+5)
    CP 81H
    JR C,ATAN5   ;c => argument less than 1
    LD BC,8100H  ;1.0
    LD IX,0
    LD D,C
    LD E,C
    CALL FDIV
    LD HL,HLSUB
    PUSH HL; will subtract answer from pi/2
ATAN5: LD HL,ATNCOEF
    CALL EVENPOL
    LD HL,QHALFPI  ;may use for subtraction
    RET
;
ATNCOEF: DB 13

#endasm
