#include <stdio.h>

viewport(toprow, leftcol, heght, width)
int toprow, leftcol, heght, width;
{
    putchar(27);
    putchar('X');
    putchar(32+toprow);
    putchar(32+leftcol);
    putchar(32+heght);
    putchar(32+width);
}