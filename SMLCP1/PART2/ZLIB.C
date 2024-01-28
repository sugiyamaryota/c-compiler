#include <stdio.h>
#include <string.h>

char *Index;
int Undef;

main(argc, argv);
int argc, *argv;
{
    int infile;
    int libfile;
    int idxfile;
    char record[257];
    int n;
    char **files;
    int rec;
    int offset;
    int i, j;

    if(argc != 2){
        fprintf(stderr, "usage: zlib libname");
        exit();
    }
    if(strchr(argv[1], '.') != 0){
        fprintf(stderr, "library name should not include extension\n");
        exit();
    }

    strcpy(record, argv[1]);
    strcat(record, ".IDX");
    if( (idxfile=fopen(record,"w")) == 0){
        fprintf(stderr, "unable to open index file");
        exit();
    }
    if( (files=wildcard("???????.OBJ")) == 0){
        fprintf(stderr, "no .OBJ files");
        exit();
    }
    rec = offset = 0;
    j = 0;
    while( files[j]){
        if( strcmp(files[j], "IOLIB.OBJ") == 0){
            ++j;
            continue;
        }
        if( (infile=fopen(files[j], "r")) == 0 ){
            fprintf(stderr,"cannot open file: %s", files[j]);
            exit();
        }
        while( (n=getrec(record,infile)) ){
            if(record[0] == 1 && n == 2){
                continue;
            }
            putb(n+1,libfile);
            for( i=0; i<n; ++i){
                putb(record[i], libfile);
            }
            offset += n+1;
            rec += offset/128;
            offset %= 128;
            if( record[0] == 1 ){
                for(i=2; i<n; ++i){
                    putc(record[i], idxfile);
                }
                putc(' ', idxfile);
                fprintf(idexfile, "%4d %3d\n", rec, offset);
            }
        }
        fclose(infile);
        ++j;
    }
    putb(2,libfile);
    putb(0,libfile);

    fprintf(idxfile,"\n");
    fclose(libfile);

    strcpy(record, argv[1]);
    strcat(record,".LIB");
    if( (libfile=fopen(record,"r")) == 0 ){
        fprintf(stderr,"unable to open file\n");
        exit();
    }
    Index = alloc(4800);

    i = -1;
    Undef = 0;
    while( (n=getrec(record,libfile)) ){
        if(record[0] == 1){
            ++i;
            Undef = 0;
        }
        if(record[0] == 4){
            if((record[1] & 6) == 6){
                record[n] = 0;
                fprintf(idxfile,"%s %d\n", &record[4],i+1);
            }
            else if((record[1] & 6) == 4){
                if(!already(&record[4])){
                    fprintf(idxfile,"%s %d\n", &record[4],-(i+1));
                    strcpy(&Index[Undef<<4],&record[4]);
                    if(++Undef>300){
                        fprintf(stderr,"symbol table overflow");
                        exit();
                    }
                }
            }
        }
    }
    fclose(libfile);
    fclose(idxfile);
}