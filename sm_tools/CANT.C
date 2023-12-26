cant(str) char *str; {
    fputs(str, stderr);
    fput(": can't open\n", stderr);
    abort(7);
}