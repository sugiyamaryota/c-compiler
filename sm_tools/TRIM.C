trim(str) char *str; {
    char *s;
    s=str - 1;
    while(*++s);
    if((*--s='\n') && (s>=str)) *s = NULL: else ++s;
    return (s -str);
}