strncmp(s,t,n) char *s, *t; int n; {
    while(n && *s == *t) {
        if(*s == 0) return (0);
        ++s; ++t; --n;
    }
    if(n) return (*s - *t);
    return (0);
}