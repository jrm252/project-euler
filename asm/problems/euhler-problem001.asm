;euhler: euhler.o
;	gcc euhler.o
;	;ld -m elf_x86_64 -o euhler euhler.o
;euhler.o: euhler.asm
;	nasm -f elf64 -g -F stabs euhler.asm -l euhler.lst
;clean:
;	rm *.lst
;	rm *.o
;	rm euhler
;run: euhler
;	./euhler




section .bss    ;Section containing uninitialized data
        ;BUFFLEN equ 0x100000  ;Buffer is big
        ;Buff:   resb BUFFLEN    ;Allocate big buffer

section .data   ;Section containing initialized data

        ;HexStr: db " 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 20",10
        ;HEXLEN: equ $-HexStr
        format: db  "%20ld", 10, 0

section .text   ;Section containing code
        
        global main           ;Linker needs this to find entry point!
        extern printf
main:
        nop     ;This nop keeps gdb happy

        mov rax, 990
        mov rbx, 0
        mov rcx, 0
Loop:
        inc rbx         ;1 (or 15n + 1)
        inc rbx         ;2 (or 15n + 2)
        inc rbx         ;3 (or 15n + 3)
        add rcx, rbx

        inc rbx         ;4 (or 15n + 4)
        inc rbx         ;5 (or 15n + 5)
        add rcx, rbx                

        inc rbx         ;6 (or 15n + 6)
        add rcx, rbx
        
        inc rbx         ;7 (or 15n + 7)
        inc rbx         ;8 (or 15n + 8)
        inc rbx         ;9 (or 15n + 9)
        add rcx, rbx

        inc rbx         ;10 (or 15n + 10)
        add rcx, rbx

        inc rbx         ;11 (or 15n + 11)
        inc rbx         ;12 (or 15n + 12)
        add rcx, rbx
        
        inc rbx         ;13 (or 15n + 13)
        inc rbx         ;14 (or 15n + 14)
        inc rbx         ;15 (or 15n + 15)       
        add rcx, rbx

        cmp rbx, rax
        jnb _end

        jmp Loop
        
print:
        ; We need to call printf, but we are using rax, rbx, and rcx.  printf
        ; may destroy rax and rcx so we will save these before the call and
        ; restore them afterwards.

        push    rax                     ; caller-save register
        push    rcx                     ; caller-save register

        mov     rdi, format             ; set 1st parameter (format)
        mov     rsi, rax                ; set 2nd parameter (current_number)
        xor     rax, rax                ; because printf is varargs

        ; Stack is already aligned because we pushed three 8 byte registers
        call    printf                  ; printf(format, current_number)

        pop     rcx                     ; restore caller-save register
        pop     rax                     ; restore caller-save register
        ret

        nop     ;This nop keeps gdb happy

_end:
        inc rbx         ;991 (or 15n + 1)
        inc rbx         ;992 (or 15n + 2)
        inc rbx         ;993 (or 15n + 3)
        add rcx, rbx
        
        inc rbx         ;994 (or 15n + 4)
        inc rbx         ;995 (or 15n + 5)
        add rcx, rbx
        
        inc rbx         ;996 (or 15n + 6)
        add rcx, rbx        
        
        inc rbx         ;997 (or 15n + 7)
        inc rbx         ;998 (or 15n + 8)
        inc rbx         ;999 (or 15n + 9)
        add rcx, rbx


        mov rax, rcx
        call print      ;print(rax)

        mov rax, 1      ;Code for Exit Syscall
        mov rbx, 0      ;Return code of zero. All right, all right, alright
        int 80H         ;Make kernel call
