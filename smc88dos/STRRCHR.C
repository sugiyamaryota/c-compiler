strrchr(s,c) char *s, c; {
    char *ptr;
    ptr = 0;
    while(*s) {
        if(*s==c) ptr = s;
        ++s;
    }
    return (ptr);
}