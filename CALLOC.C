#define NOCCARGC
#include stdio.h

calloc(n, size) char *n, *size; {
    return (Ualloc(n*size, YES));
}