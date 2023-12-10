strchr(str, c) char *str, c; {
    while(*str) {
        if(*str == c) return (str);
        ++str;
    }
    return (0);
}