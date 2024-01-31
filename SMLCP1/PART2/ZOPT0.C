#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define NULL 0
#define CTRLC 3
#define TAB 9
#define SPACE 32

#define CNIN 6

#define LINELEN 128

extern int getopt();
extern int optind;

int Ichan, Ochan;
int Total;
int Compact;

char Pophl[] = "\tPOP HL";
char Pushhl[] = "\tPUSH HL";
char Popde[] = "\tPOP DE";
char Popbc[] = "\tPOP BC";
char Pushbc[] = "\tPUSH BC";
char Ret[] = "\tRET";
char Ldde[] = "\tLD DE,";
char Ldhl[] = "\tLD HL,";
char Ldhl0[] = "\tLD HL,0";
char Ldhl2[] = "\tLD HL,2";
char Ldhl4[] = "\tLD HL,4";
char Ldhl6[] = "\tLD HL,6";
char Inchl[] = "\tINC HL";
char Dechl[] = "\tDEC HL";
char Popix[] = "\tPOP IX";
char Pushix[] = "\tPUSH IX";
char Exdehl[] = "\tEX DE,HL";
char Addhlde[] = "\tADD HL,DE";
char Addhlhl[] = "\tADD HL,HL";

usage()
{
    puts("usage: zopt [-c] file\n");
    exit();
}

main(argc, argv)
int argc;
char **argv;
{
    char file1[20], file2[20];
    int i, c;
    if(argc == 1 || argc > 3){
        usage();
    }
    Compact = FALSE;
    while( (c=getopt(argc, argv, "C")) != EOR ) {
        switch(c){
            case 'C':
                Compact = TRUE;
                break;
            default:
                usage();
        }
    }
    if( argc-optind != 1 ){
        usage();
    }
    strcpy( file1, argv[optind] );
    strcat( file1, ".asm" );
    strcpy( file2, argv[optind] );
    strcat( file2, ".$$$" );

    if( (Ichan=fopen(file1, "r")) == 0 ){
        err("cannot open input file");
        exit();
    }
    if( (Ochan=fopen(file2, "w")) == 0 ){
        err("cannot open output file");
        exit();
    }
    Total = 0;

    init();
    fclose(Ichan);
    fclose(Ochan);

    puts("Grand total bytes saved:"); putdec(Total);
    putchar('\n'); putchar('\n');

    unlink(file1);
    rename(file2, file1);
}

extern _newfcb();