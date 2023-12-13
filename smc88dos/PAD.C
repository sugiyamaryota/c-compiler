#define NOCCARGC

pad(dest, ch, n) char *dest, *n; int ch; {
    while(n--) *dest++ = ch;
}