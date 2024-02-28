;*
;* ecgc cartridge definitions
;*

if !def(ECGC_CARTRIDGE_INC)
def ECGC_CARTRIDGE_INC = 1

; MBCH Control 0
def CART_MBCH_CTRL0     equ $A100

; XRAM Control 0
def CART_XRAM_CTRL0     equ $A200
def CART_XRAM_CTRL0_CRE equ 7

; XRAM Control 1
def CART_XRAM_CTRL1     equ $A300

; DMA Registers

; DMA Base address
def CART_DMA_BASE       equ $A500

; DMA Configuration
def CART_DMA_CFG        equ (CART_DMA_BASE + $00)
def CART_DMA_CFG_STRT   equ 7   ; DMA Start
def CART_DMA_CFG_DINC   equ 5   ; DMA Destination Address Increment
def CART_DMA_CFG_SINC   equ 4   ; DMA Source Address Increment
def CART_DMA_CFG_BUSY   equ 0   ; DMA Busy Flag

def CART_DMA_CPAM       equ (CART_DMA_BASE + $01)   ; DMA Copy Amount
def CART_DMA_SAL        equ (CART_DMA_BASE + $04)   ; DMA Source Address Low
def CART_DMA_SAH        equ (CART_DMA_BASE + $05)   ; DMA Source Address High
def CART_DMA_DAL        equ (CART_DMA_BASE + $06)   ; DMA Destination Address Low
def CART_DMA_DAH        equ (CART_DMA_BASE + $07)   ; DMA Destination Address High

; Cart RAM
def CART_RAM_BASE       equ $B000
def CART_RAM_SIZE       equ $0800   ; 2kB

endc    ; ECGC_CARTRIDGE_INC