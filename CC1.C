#include <stdio.h>
#include "notice.h"
#include "cc.def"

char
#ifdef OPTIMIZE
    optimize,
#endif
    alarm,
    monitor,
    pause,
#ifdef DYNAMIC
    *stage,
    *symtab,
    *litq,
    *macn,
    *macq,
    *pline,
    *mline,
#else
    stage[STAGESIZE],
    symtab[SYMTBSZ],
    litq[LITABSZ],
    macn[MACNSIZE],
    macq[MACQSIZE],
    pline[LINESIZE],
    mline[LINESIZE],
    swq[SWTABSZ],
#endif
    *line,
    *lptr,
    *glbptr,
    *locptr,
    *stagenext,
    *stagelast,
        quote[2],
    *cptr,
    *cptr2,
    *cptr3,
        msname[NAMESIZE],
        ssname[NAMESIZE];
int
#ifdef STGOTO
    nogo,
    noloc,
#endif
    op[16]
    op2[16]
    opindex,
    opsize,
    swactive,
    swdefault,
    *swnext,
    *swend,
#ifdef DYNAMIC
    *wq,
#else
    wq[WQTABSZ],
#endif
    argcs,
    *argvs,
    *wqptr,
    litpr,
    macptr,
    pptr,
    oper,
    cch,
    nch,
    declared,
    iflevel,
    skiplevel,
    func1,
    nxtlab,
    litlab,
    beglab,
    csp,
    argstk,
    argtop,
    ncmp,
    errflag,
    eof,
    input,
    input2,
    output,
    files,
    filearg,
    glbflag,
    ctext,
    ccode,
    listfp,
    lastst,
    swused,
    *iptr;

#include "cc11.c"
#include "cc12.c"
#include "cc13.c"

#ifndef SEPARATE
#include "cc21.c"
#include "cc22.c"
#include "cc31.c"
#include "cc32.c"
#include "cc33.c"
#include "cc41.c"
#include "cc42.c"
#endif
