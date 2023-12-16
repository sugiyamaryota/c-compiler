#include <stdio.h>

cursor(row,column);
int row, column;
{
    putchar(27);
    putchar('Y');
    putchar(32+row);
    putchar(32+column);
}