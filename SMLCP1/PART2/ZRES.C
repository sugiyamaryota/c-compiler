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
            lptr = search(cptr+NAME,STARTLIB,LIBREC,ENDLIB,LIBENT,LIBNAME);
            if(lptr == 0 || ptr[LIBNAME] == 0){
                if( strcmp(cptr+NAME, "_END") != 0){
                    printf("%s is unresolved\n", cptr+NAME);
                }
                cptr[TYPE] = DEFINED;
            }
            else {
                copy_module(lptr[MODULE]);
                mod = Module[lptr[MODULE]];
                if(strcmp(mod,"PLOT") == 0)
                    Ploadflag = TRUE;
                else if(strcmp(mod,"FLOAT") == 0)
                    Floatflag = TRUE;
                else if(strcmp(mod,"PRINTF2") == 0)
                    Ploadflag = TRUE;
                else if(strcmp(mod,"SCANF2") == 0)
                    Sloadflag = TRUE;
                module_loaded = TRUE;
            }
        }
    }
    return module_loaded;
}

loadfile(name);
char *name;
{
    char record[257];
    int infile;
    int n;

    strcpy(record, name);
    strcat(record, ".OBJ");
    if( (infile=fopen(record,"r")) == 0 ){
        fprintf(stderr,"Unable to open input file: %s\n", record);
        exit();
    }
    while( (n=getrec(record, infile)) ){
        if(record[0] == 4){
            record[n] = 0;
            if( (record[1] & 6) == 6){
                addsym(&record[4], DEFINED);
            }
            else if ( !(record[1] & 2)) {
                addsym(&record[4],UNDEFINED);
            }
        }
    }
    fclose(infile);
}

read_index(name);
char *name;
{
    int infile;
    char temp[80];
    int last;
    char *nxtptr;
    int n,i;

    if((infile=fopen(name,"r")) == 0){
        puts("cannot open index file");
        exit();
    }

    n=0;
    while(getline(infile,temp) && strlen(temp) != 0){
        ++n;
    }
    Nmod = n;
    xseek(infile,0,0);
    Module = zalloc(sizeof(int)*n);
    Objptr = zalloc(sizeof(int)*n);
    Rec = zalloc(sizeof(int)*n);
    Off = zalloc(sizeof(int)*n);

    for(i=0;i<n;++i){
        Module[i] = alloc(13);
        if(fscanf(infile,"%s %d %d",Module[i],&Rec[i],&Off[i] != 3)){
            puts("index read error");
            exit();
        }
    }
    printf("bytes free: %u\n",avail());

    getline(infile,temp);

    nxtptr = Index - IXREC;
    last = 0;
    while( fscanf(infile, "%s %d", temp, &n) == 2 ){
        if(abs(n) != last){
            last = abs(n);
            nxtptr += IXREC;
            ++Ixused;
            Objptr[last-1] = nxtptr;
        }
        strcpy(nxtptr+IXNAME, temp);
        if(n>0) {
            nxtptr[IXTYPE] = DEFINED;
            addlib(temp, (n-1));
        }
        else
            nxtptr[IXTYPE] = UNDEFINED;
        nxtptr += IXREC;
        ++Ixused;
        if(Ixused > IXENT -1){
            printf("index table full\n");
            exit();
        }
    }
    fclose(infile);
}

resolve(n);
int n;
{
    char *nxtptr;
    nxtptr = Objptr[n];
    while(nxtptr[IXNAME]){
        addsym(&nxtptr[IXNAME], nxtptr[IXTYPE]);
        nxtptr += IXREC;
    }
}

getrec(ptr,fd);
char *ptr;
int fd;
{
    int j;
    int i;
    i = getb(fd);
    if( i == 2 || i == -1){
        return 0;
    }
    j = (--i) & 0xff;
    while(i--) {
        *ptr++ = getb(fd);
    }
    return j;
}

addsym(str,type);
char *str;
int type;
{
    char *cptr;
    cptr = search(str, STARTTAB, SYMREC, ENDTAB, NUMENT, NAME);
    if(cptr == 0){
        puts("symbol table full\n");
        exit();
    }
    if(*cptr != 0){
        if(type == DEFINED){
            cptr[TYPE] = DEFINED
        }
    }
    else {
        strcpy(cptr+NAME, str);
        cptr[TYPE] = type;
        ++Symused;
    }
}

addlib(str, modx);
char *str;
int modx;
{
    char *cptr;
    cptr = search(str, STARTLIB, LIBREC, ENDLIB, LIBENT, LIBNAME);
    if(cptr == 0){
        puts("library symbol table full");
        exit();
    }
    strcpy(cptr+LIBNAME, str);
    cptr[MODULE] = modx;
    ++Libused;
}

search(sname,buf,len,end,max,off)
char *sname;
char *buf;
int len;
char *end;
int max;
int off;
{
    char *cptr,cptr2;
    cptr = cptr2 = buf + ( (hash(sname)%(max-1)) * len);
    while(*cptr != 0){
        if(strncmp(sname, cptr+off, NAMEMAX) == 0){
            return cptr;
        }
        if( (cptr+=len) >= end){
            cptr = buf;
        }
        if( cptr == cptr2){
            return 0;
        }
    }
    return cptr;
}

hash(sname)
char *sname;
{
    int i, c;
    i = 0;
    while( (c=*sname++)) i = (i<<2) +c;
    return abs(i);
}

#asm
qzalloc: pop hl; return address
    pop bc;      character count
    push bc
    push hl
    push bc;       character count as arg to alloc()
    call qalloc;   HL points to allocated memory
    pop bc;        count
    dec bc; adjust count
    push hl; save pointer to allocated memory
    ld (hl),0; start zeroing block
    ld d,h; DE points on byte after HL
    ld e,l
    inc de
    ldir; zero block
    pop hl; retrieve block pointer
    ret
#endasm

find_module(string)
char *string;
{
    int i;
    for(i=0; i<Nmod;++i){
        if(strcmp(Module[i],string) == 0){
            return i;
        }
    }
    return -1;
}