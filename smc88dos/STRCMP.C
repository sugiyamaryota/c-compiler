strcmp(s,t) char *s, *t; {
    while(*s == *t) {
        if(*s == 0) return (0);
        ++s; ++t;
    }
    return (*s - *t);
}