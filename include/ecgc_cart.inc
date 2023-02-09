;*
;* ecgc Cartridge definitions
;*

if !def(ECGC_CARTRIDGE_INC)
ECGC_CARTRIDGE_INC = 1

; For EFB functions, refer to Using Hardend Control Functions MachXO3D Reference
; https://www.latticesemi.com/-/media/LatticeSemi/Documents/ApplicationNotes/UZ/FPGA-TN-02119-1-3-Using-Hardened-Control-Functions-MachXO3D-Reference.ashx?document_id=52704

; EFB Base address
CART_EFB_BASE       equ $A000

; EFB SPI Registers
CART_EFB_SPICR0     equ (CART_EFB_BASE + $54)   ; EFB SPI Control Register 0
CART_EFB_SPICR1     equ (CART_EFB_BASE + $55)   ; EFB SPI Control Register 1
CART_EFB_SPICR2     equ (CART_EFB_BASE + $56)   ; EFB SPI Control Register 2
CART_EFB_SPIBR      equ (CART_EFB_BASE + $57)   ; EFB SPI Clock Pre-scale
CART_EFB_SPICSR     equ (CART_EFB_BASE + $58)   ; EFB SPI Chip Select
CART_EFB_SPITXDR    equ (CART_EFB_BASE + $59)   ; EFB SPI Transmit Data
CART_EFB_SPISR      equ (CART_EFB_BASE + $5A)   ; EFB SPI Status Register
CART_EFB_SPIRXDR    equ (CART_EFB_BASE + $5B)   ; EFB SPI Revieve Data
CART_EFB_SPIIRQ     equ (CART_EFB_BASE + $5C)   ; EFB SPI Interrupt Request
CART_EFB_SPIIRQEN   equ (CART_EFB_BASE + $5D)   ; EFB SPI Interrupt Request Enable

; EFB Flash Registers

; EFB Flash Control
CART_EFB_CFGCR      equ (CART_EFB_BASE + $70)
CART_EFB_CFGCR_WBCE equ 7   ; WISHBONE Connection Enable
CART_EFB_CFGCR_RSTE equ 6   ; WISHBONE Connection Reset

CART_EFB_CFGTXDR    equ (CART_EFB_BASE + $71)   ; EFB Flash Transmit Data
CART_EFB_CFGSR      equ (CART_EFB_BASE + $72)   ; EFB Flash Status
CART_EFB_CFGRXDR    equ (CART_EFB_BASE + $73)   ; EFB Flash Recieve Data
CART_EFB_CFGIRQ     equ (CART_EFB_BASE + $74)   ; EFB Flash Interrupt Request
CART_EFB_CFGIRQEN   equ (CART_EFB_BASE + $75)   ; EFB Flash Interrupt Request Enable

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

ENDC    ; ECGC_CARTRIDGE_INC