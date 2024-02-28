;*
;* ecgc cartridge bootloader definitions
;*

if !def(ECGC_BOOT_INC)
def ECGC_BOOT_INC = 1

; Charmap for chars used in boot (very minimalistic)
newcharmap boot
charmap " ", $00
charmap "0", $01
charmap "1", $02
charmap "2", $03
charmap "3", $04
charmap "4", $05
charmap "5", $06
charmap "6", $07
charmap "7", $08
charmap "8", $09
charmap "9", $0A
charmap "A", $0B
charmap "B", $0C
charmap "C", $0D
charmap "D", $0E
charmap "E", $0F
charmap "F", $10
charmap "R", $11
charmap "W", $12
charmap ":", $13

endc    ; ECGC_CARTRIDGE_INC