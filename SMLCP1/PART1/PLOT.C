#asm
;
;   PLOT ROUTINES FOR SMALL C
;
;   This package includes the following routines:
;
;   plot(x, y, action)          plot at x,y
;   cursor(row, column)         position cursor
;   viewport(toprow, leftcol, height, width)  set viewport
;   line(x1, y1, x2, y2, action) draw line(x1, y1) -> (x2, y2)
;   box(x1, y1, x2, y2, action)       (x2, y2) is bottom right
;
;
;
    global qplot
qplot: LD HL,7; put SP+7 in HL

;
;
#endasm