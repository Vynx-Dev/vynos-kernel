global start
section .text
bits 32 ; this specifies the code is for 32 bit
start:
    mov dword [0xb8000], 0x2f4b2f4f ; DWORD printing ok
    hlt ; halt