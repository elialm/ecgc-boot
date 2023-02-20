; Some usefull macros to help simplify code

if !def(MACROS_INC)
MACROS_INC = 1

; Get adress of cell on virtual screen 0 and load pointer into [bc]
;	x - x coordinate
;	y - y coordinate
LOAD_CELL_SCRN0_BC: macro
	ld bc, _SCRN0 + SCRN_VX_B * \2 + \1
endm

; Get adress of cell on virtual screen 0 and load pointer into [hl]
;	x - x coordinate
;	y - y coordinate
LOAD_CELL_SCRN0_HL: macro
	ld hl, _SCRN0 + SCRN_VX_B * \2 + \1
endm

; Get adress of cell on virtual screen 1 and load pointer into [bc]
;	x - x coordinate
;	y - y coordinate
LOAD_CELL_SCRN1_BC: macro
	ld bc, _SCRN1 + SCRN_VX_B * \2 + \1
endm

; Get adress of cell on virtual screen 1 and load pointer into [hl]
;	x - x coordinate
;	y - y coordinate
LOAD_CELL_SCRN1_HL: macro
	ld hl, _SCRN1 + SCRN_VX_B * \2 + \1
endm

; Add 16-bit register with accumulator
;	h - high register
;	l - low register
ADD_16_BIT: macro
	add a, \2	; Add lower register
	ld \2, a	; Load added number to original register
	jp nc, .done_adding		; If no carry, skip high byte
	inc \1
.done_adding
endm

; Wait for V-Blank and then disable the LCD
LCD_DISABLE: macro
	halt
    nop
    ld hl, rLCDC
    res 7, [hl]
endm

; Wait for V-Blank
LCD_AWAIT_VBLANK: macro
	halt
    nop
endm

; Enable the LCD
LCD_ENABLE: macro
	ld hl, rLCDC
    set 7, [hl]
endm

endc