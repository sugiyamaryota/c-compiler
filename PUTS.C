#define NOCCARGC
#include stdio.h

puts(string) char *string; {
    fputs(string, stdout);
    fputc('\n',stdout);
}