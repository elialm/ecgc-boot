;*
;* crash codes definitions
;*

if !def(CRASH_INC)
def CRASH_INC = 1

; Call crash routine and stop program excecution
;   1 - error value
macro CRASH_WITH
    ld a, \1
    rst $38
endm

; Call to spi_select was made with and invalid CS value
def CRASH_SPI_INVALID_CS equ $10

endc