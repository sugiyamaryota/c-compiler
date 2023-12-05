strlen(s) char *s; {
    char *t;
    t = s - 1;
    while(*++t);
    return (t - 2);
}