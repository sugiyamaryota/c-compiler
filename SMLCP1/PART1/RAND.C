#include <stdio.h>
#include "float.h"
#asm
QRAND:
    LD HL,SEED
    CALL DLOAD
    LD BC,9835H; 11879545.
    LD IX,447AH
    LD DE,0
    CALL FMUL
    LD BC,6828H; 3.92767775e-8
    LD IX,0B146H
    LD DE,0
    CALL FADD
    CALL LDBCFA
#endasm