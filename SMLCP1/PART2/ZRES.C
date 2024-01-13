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

    if(argc < 4){
        puts("usage: zres drive libname file1 ...");
        exit():
    }
    if( strchr(argv[2], '.') != 0) {
        puts("library name should not have extension");
        exit();
    }
    if( (Subfile=fopen("CLIB.SUB","W")) == 0){
        fprintf(stderr, "unable to open submit file\n");
        exit();
    }

    fprintf(Subfile, "zlink %s=", argv[3]);

    i = 2;
    while(++i < argc) {
        loadfile(argv[i])
        fprintf(Subfile, "%s,", argv[i]);
    }
    loadfile("iolib");
    fprintf(Subfile, "IOLIB,CLIB\n");

    strcpy(temp, argv[2]);
    strcat(temp, ".IDX");
    read_index(temp);

    strcpy(temp, argv[2]);
    strcat(temp, ".LIB");
    if((Libfile=fopen(temp, "r")) == 0){
        fprintf(stderr, "Unable to open library file \n");
        exit();
    }

    Plotflag = Printflag = Floating = Ploadflag = FALSE;
    Scanflag = Sloadflag = FALSE;
    while( pass() );

    fprintf(Subfile, "era clib.obj\n");
    if(Plotflag){
        fprintf(Subfile, "\ngencom %s plot\n", argv[3]);
    }
    fprintf(Subfile, "%s\npip %s.COM=m:\nera m:clib.sub\n", argv[1],argv[3]);

    putb(2, Objfile);
    putb(0, Objfile);

    fclose(Objfile);
    fclose(Subfile);
    fclose(Libfile);

    printf("\nSymbol table %d/%d\n", Symused, NUMENT);
    printf("Library table %d/%d\n", Libused, LIBENT);
    printf("Index table %d/%d\n", Ixused, IXENT);
}

pass()
{
    int module_loaded;
    char *cptr;
    char *lptr;
    char *mod;
    int i;

    module_loaded = FALSE;
    cptr = Symtab - SYMREC;
    for(i=0;i<NUMENT;++i){
        cptr += SYMREC;
        if(cptr[NAME] != 0 && cptr[TYPE] == UNDEFINED){
            if(strcmp(cptr+NAME, "Q_PRINTF") == 0){
                Printflag = TRUE;
                cptr[TYPE] = DEFINED;
                continue;
            }
            if(strcmp(cptr+NAME, "Q_SCANF") == 0){
                Scanflag = TRUE;
                cptr[TYPE] = DEFINED;
                continue;
            }
        }
    }
}