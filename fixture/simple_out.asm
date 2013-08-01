* PLUS z,a,c
    lda a
    add c
    sta z
* PLUS u,u,=1
    lda u
    add =1
    sta u
* TRANSFER in,word
    ldy word
    in
    sty word
* TRANSFER out,area
    ldy area
    out
    sty area
*     TRANSFER in,_A
    ldy _A
    in
    sty _A
*     TRANSFER in,_B
    ldy _B
    in
    sty _B
*     ABS _A,_absA
    lda _A
    jns *+2
    neg
    sta _absA
*     ABS _B,_absB
    lda _B
    jns *+2
    neg
    sta _absB
*     PLUS sum,_absA,_absB
    lda _absA
    add _absB
    sta sum
*     TRANSFER out,sum
    ldy sum
    out
    sty sum
    stop
_A  bss 1
_B  bss 1
_absA bss 1
_absB bss 1
sum bss 1
    end
