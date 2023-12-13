strcat(s,t) char *s, *t; {
    char *d;
    d = s;
    --s;
    while (*++s);
    while(*s++ = *t++);
    return (d);
}