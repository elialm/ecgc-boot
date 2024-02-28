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

; SPI Registers

; SPI Base address
def CART_SPI_BASE       equ $A600

; SPI Control
def CART_SPI_CTRL       equ (CART_SPI_BASE + $00)
def CART_SPI_CTRL_CPOL  equ 7   ; SPI Clock polarity, see SPI documentation
def CART_SPI_CTRL_CPHA  equ 6   ; SPI Clock phase, see SPI documentation
def CART_SPI_CTRL_BORD  equ 5   ; SPI Bit order, 0 = MSB first, 1 = LSB first
def CART_SPI_CTRL_CSRL  equ 4   ; SPI CS release, 0 = nothing, 1 = release CS after next byte sent
def CART_SPI_CTRL_BUSY  equ 2   ; SPI transmission busy, 1 = indicates transmission in progress
def CART_SPI_CTRL_DONE  equ 1   ; SPI transmission done, 1 = indicates valid data in DATA register
def CART_SPI_CTRL_EN    equ 0   ; SPI enable, 1 = enable core

; SPI Frequency divider
; Will divide the SPI clock with the given formula: Fclk = 100MHz / (1 + FDIV)
def CART_SPI_FDIV       equ (CART_SPI_BASE + $01)

; SPI Chip select
def CART_SPI_CS         equ (CART_SPI_BASE + $02)
def CART_SPI_CS_SD      equ 2   ; Chip select for SD card
def CART_SPI_CS_RTC     equ 1   ; Chip select for RTC
def CART_SPI_CS_FLASH   equ 0   ; Chip select for NOR flash

; SPI Data
; Write to send data over SPI, read to read received data
def CART_SPI_DATA       equ (CART_SPI_BASE + $03)

endc    ; ECGC_CARTRIDGE_INC