atoib(s,b) char *s; int b; {
    int n, digit;
    n = 0;
    while((isspace(*s))) ++s;
    while((digit = (127 & *s++)) >= '0') {
        if(digit >= 'a') digit -= 87;
        else if(digit >= 'A') digit -= 55;
        else digit -= '0';
        if(digit >= b) break;
        n = b * n + digit;
    }
    return (n);
}