FOO macro &cmd,&arg
    lda &arg
    &cmd &arg
    sta &arg
mend

BAR macro &arg
    lol &arg
mend

FOO BAR,_b
