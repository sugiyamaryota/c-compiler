#include <stdio.h>
#include <math.h>
#include "float.h"

sqrt(x)
double x;
{
    double extra;
    char *px;
    char *pextra;
    int i;

    if (x == 0.0) return 0.0;
    if (x < 0.0) {
        err("ill sqrt");
        return 0.0;
    }
    px = &x;
    pextra = &extra;
    extra = 0.707;
    pextra[5] = (px[5]>>1)^64;
    i = 5;
    while(--i){
        extra += x/extra;
        --pextra[5];
    }
    return extra;
}