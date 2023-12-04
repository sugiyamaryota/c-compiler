strncat(s,t,n) char *s, *t; int n; {
    char *d;
    d = s;
    --s;
    while(*++s);
    while(n--) {
        if(*s++ = *t++) continue;
        return (d);
    }
    *s = 0;
    return (d);
}