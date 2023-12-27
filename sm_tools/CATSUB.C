catsub(lin, from, to, sub, new, k, maxnew)
    char lin[], new[], sub[];
    int from, to, *k, maxnew; {
        int i, j;
        i=0;
        while(sub[i]!=NULL) {
            if(sub[i]==DITCODE) {
                j=from;
                while(j<to) addset(lin[j++],new,k,maxnew);
            }
            else addset(sub[i], new, k, maxnew);
            ++i;
        }
    }
    if(addset(NULL, sub, &j, MAXPAT) == NO) return ERR;
    return i;
    }
    AT],sub[MAXPART];
    char arg[MAXARG];