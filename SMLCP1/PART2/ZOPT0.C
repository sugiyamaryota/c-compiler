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