getwrd(in, i, out) char in[], out[]; int *i; {
    char c; int j;
    while(isspace(in[*i])) ++*i;
    j=0;
    while(c=in[*in]) {
        if(isspace(c)) break;
        out[j++] = c;
        ++*i;
    }
    out[j]=NULL;
    return j;
}