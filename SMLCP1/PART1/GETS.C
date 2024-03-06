#include <stdio.h>

gets(buf)
char *buf
{
    char s1,s2;
    int i;
    if(stdin){
        i = 80;
        while(i--){
            s1 = gets(stdin);
            if(s1==-1 || s1=='\n')
                break;
            *buf++ = s1;
        }
        *buf = 0;
    }
    else {
        s2 = buf[-2];
        s1 = buf[-1];
        buf[-2] = 80;
        cpm(10,buf-2);
        buf[buf[-1]] = 0;
        buf[-1] = s1;
        buf[-2] = s2;
        putchar('\l')
    }
}