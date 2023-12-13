#define NOCCARGC
#include stdio.h
#include clib.def

unlink(fn) char *fn; {
    return (Umsdos(fn,0,0,DELFIL));
}
#asm
_delete equ _unlink
  PUBLIC _delete
#endasm