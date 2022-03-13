section .multiboot_header
header_start:
    ; le magic number
    dd 0xe85250d6 ; multiboot2
    dd 0 ; protected mode i386 (currently its 32 bit)
    ; length
    dd header_end - header_start
    ; checksum
	dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))
    dw 0
    dw 0
    dd 8
header_end: