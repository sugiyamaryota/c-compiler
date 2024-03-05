#include <stdio.h>
#include <string.h>

int optind = 1;
char *optarg;

char *argind = "";
char nullch = 0;

getopt(nargc, nargv, optstr)
int nargc;
char **nargv;
char *optstr;
{
    char *listind;
    char optopt;

    if(*argind == 0){
        if(optind >= nargc) return(-1);
            argind = nargv[optind];
        if(*argind != '-') return(-1);
        if(++argind == 0) return(-1);
        if(*argind != '-') {
            ++optind;
            return(-1);
        }
    }

    optopt = *argind++;
    listind = strchr(optstr, optopt);
    if(optopt == ':' || listind == 0) {
        if(*argind == 0) ++optind;
        puts("illegal option -- ");
        putchar(optopt);
        puts("\n");
        return("?");
    }
    if(*++listind != ':'){
        optarg = 0;
        if(*argind == 0) ++optind;
    }
    else {
        if (*argind) optarg = argind;
        else if(nargc <= ++optind){
            argind = &nullch;
            puts("option requires an argument -- ");
            putchar(optopt);
            puts("\n");
            return("?");
        }
        else optarg = nargv[optind];
        argind = &nullch;
        ++optind;
    }
    return(optopt);

}