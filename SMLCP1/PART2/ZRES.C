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

#define IXNAME 0
#define IXTYPE 17
#define IXREC  18

#define IXENT 600
#define IXSIZE (IXENT*IXREC)


#define NAMEMAX 16

char *Symtab;
char *Libtab;
char *Index;
int *Module;
int *Objptr;
int *Rec;
int *Off;
int Nmod;

int Ixused;
int Libused;
int Symused;

int Plotflag;
int Printflag;
int Scanflag;
int Floatflag;
int Ploadflag;
int Sloadflag;

int Libfile;
int Subfile;
int Objfile;

char Command[128];
main(argc, argv)
int argc;
char **argv;
{
    char temp[40];
    int i;

    Symtab = zalloc(SYMSIZE);
    Libtab = zalloc(LIBSIZE);
    Index = zalloc(IXSIZE);
}
