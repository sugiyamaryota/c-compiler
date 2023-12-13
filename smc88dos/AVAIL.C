#define NOCCARGC
extern char *Umemptr;

avail(abort) int abort; {
    char x;
    if(&x < Umemptr) {
        return (0);
    }
    return (&x - Umemptr);
}