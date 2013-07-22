;;; THIS IS A TESTING PROGRAM FOR MACROPRPOCESSOR.

;; Features tested by this example:
;;    - finding macro definitions and storing
;;      them into MDT.
;;    - no comments in expanded macro definitions
;;    - MDs can be used before they are defined
;;    - No MDs in expanded text.

;; Features that are not tested by this example:
;;    - Recursive MDs. Expansion can fall into infinite loop.
;;    - Error reporting. That sample code is correct.
;; further testing is needed in order to cover these areas.
PLUS macro &result,&arg1,&arg2
    lda &arg1   ; store first arg in A
    add &arg2   ; add the second arg
    sta &result ; save A to the result
mend

PLUS z,a,c ; PLUS macro with z,a,c as parameters
PLUS u,u,=1 ; u+=1, '=1' is a literal.

; macros can be used _BEFORE_ they are declared
TRANSFER in,word ; input from port to 'word'

TRANSFER macro &IO_oper,&data ;; TRANSFER MACRO.
    ldy &data
    &IO_oper
    sty &data
mend

TRANSFER out,area ; output to port from 'area'

ABS macro &data,&result
    lda &data
    jns *+2
    neg
    sta &result
mend

;;; LARGE EXAMPLE ;;;
    TRANSFER in,_A
    TRANSFER in,_B
    ABS _A,_absA
    ABS _B,_absB
    PLUS _absA,_absB,sum
    TRANSFER out,sum
    stop

_A  bss 1
_B  bss 1
_absA bss 1
_absB bss 1
sum bss 1
    end
;;; END OF LARGE EXAMPLE ;;;
