#include <stdio.h>
#include <string.h>

#define DEFINED 0
#define UNDEFINED 1

#define CR 13
#define NULL 0

#define NAME 0
#define TYPE 17
#define SYMREC 18

#define NUMENT 700
#define STARTTAB Symtab
#define ENDTAB (STARTTAB + ((NUMENT - 1)*SYMREC))
#define SYMSIZE (NUMENT * SYMREC)

#define LIBNAME 0
#define MODULE 17
#define LIBREC 18

#define LIBENT 500
#define STARTLIB Libtab
#define ENDLIB (STARTLIB + ((LIBENT-1)*LIBREC))
#define LIBSIZE (LIBENT*LIBREC)