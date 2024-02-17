;*
;* ecgc cartridge definitions
;*

if !def(ECGC_CARTRIDGE_INC)
ECGC_CARTRIDGE_INC = 1

; MBCH Control 0
CART_MBCH_CTRL0     equ $A100

; XRAM Control 0
CART_XRAM_CTRL0     equ $A200
CART_XRAM_CTRL0_CRE equ 0

; XRAM Control 1
CART_XRAM_CTRL1      equ $A300

; DMA Base address
CART_DMA_BASE       equ $A500

; DMA Registers

; DMA Configuration
CART_DMA_CFG        equ (CART_DMA_BASE + $00)
CART_DMA_CFG_STRT   equ 7   ; DMA Start
CART_DMA_CFG_DINC   equ 5   ; DMA Destination Address Increment
CART_DMA_CFG_SINC   equ 4   ; DMA Source Address Increment
CART_DMA_CFG_BUSY   equ 0   ; DMA Busy Flag

CART_DMA_CPAM       equ (CART_DMA_BASE + $01)   ; DMA Copy Amount
CART_DMA_SAL        equ (CART_DMA_BASE + $04)   ; DMA Source Address Low
CART_DMA_SAH        equ (CART_DMA_BASE + $05)   ; DMA Source Address High
CART_DMA_DAL        equ (CART_DMA_BASE + $06)   ; DMA Destination Address Low
CART_DMA_DAH        equ (CART_DMA_BASE + $07)   ; DMA Destination Address High

; Cart RAM
CART_RAM_BASE       equ $B000
CART_RAM_SIZE       equ $0800   ; 2kB

endc    ; ECGC_CARTRIDGE_INC