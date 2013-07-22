
    lda a
    add c
    sta z
    lda u
    add =1
    sta u

    ldy word
    in
    sty word

    ldy area
    out
    sty area

    ldy _A
    in
    sty _A
    ldy _B
    in
    sty _B
    lda _A
    jns *+2
    neg
    sta _absA
    lda _B
    jns *+2
    neg
    sta _absB
    lda _absA
    add _absB
    sta sum
    ldy sum
    out
    sty sum
    stop
_A  bss 1
_B  bss 1
_absA bss 1
_absB bss 1
sum   bss 1
    end
