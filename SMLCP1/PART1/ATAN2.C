#include <stdio.h>
#include <math.h>
#include "float.h"

atan2(y,x)
double x, y;
{
    double a;
    if(fabs(x) >= fabs(y)) {
        a = atan(y/x);
        if(x < 0.0) {
            if( y >= 0.0) a += pi;
            else a -= pi;
        }
    }
    else {
        a = -atan(x/y);
        if (y < 0.0) a -=halfpi;
        else a += halfpi;
    }
    return a;
}