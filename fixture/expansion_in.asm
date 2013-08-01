FOO macro &cmd,&arg
    lda &arg
    &cmd &arg
    sta &arg
mend

BAR macro &arg
    lol &arg
mend

SUM2 macro &a,&b
    lda &a
    add &b
mend

SUM3 macro &a,&b,&c
    SUM2 &a,&b
    add &c
mend

    FOO BAR,_b

    SUM3 x,y,=1
