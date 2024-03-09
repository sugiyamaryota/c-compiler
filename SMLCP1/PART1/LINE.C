#include <stdio.h>

line(x1, y1, x2, y2, action)
int x1, y1, x2, y2, action;
{
    int x, y, a, b, d, deltap, deltaq;
    int dx, dy;

    dx = x2 - x1;
    if (dx < 0) dx = -dx;
    dy = y2 - y1;
    if (dy < 0) dy = -dy;

    y = y1;
    x = x1;

    if(dy <= dx){
        if (x1 <= x2) a = 1;
        else a = -1;
        if (y1 <= y2) b = 1;
        else b = -1;

        deltap = dy << 1;
        d = deltap - dx;
        deltaq = d - dx;

        plot(x, y, action);
        while (x != x2) {
            x += a;
            if (d < 0) d += deltap;
            else {
                y += b;
                d += deltaq;
            }
            plot(x, y, action);
        }
    }
    else {
        if (y1 <= y2) a = 1;
        else a = -1;
        if (x1 <= x2) b = 1;
        else b = -1;

        deltap = dx << 1;
        d = deltap - dy;
        deltaq = d - dy;

        plot(x, y, action);
        while (y != y2) {
            y += a;
            if (d < 0) d += deltap;
            else {
                x += b;
                d += deltaq;
            }
            plot(x, y, action);
        }
    }
}