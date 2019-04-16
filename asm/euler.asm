;euler: euler.o
;	gcc euler.o
;	;ld -m elf_x86_64 -o euler euler.o
;euler.o: euler.asm
;	nasm -f elf64 -g -F stabs euler.asm -l euler.lst
;clean:
;	rm *.lst
;	rm *.o
;	rm euler
;run: euler
;	./euler




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

        mov r9, 100;4000000 ;maxFib
        mov r10, 1      ;fib1
        mov r11, 2      ;fib2
        mov r12, 0      ;nextFib
        mov r13, 2      ;sum (2 is the first even fibonacci #)

Loop:
        mov r12, r11    ;nextFib = fib2
        add r12, r10    ;               + fib1
        
        cmp r12, r9     ;if(nextfib > maxFib)
        ja _end         ;   _end

        mov r14, r12    
        and r14, 0b0000_0000_0000_0000_0000_0000_0000_0001
        cmp r14, 0
        jne Store        ;jump past Even label if odd

Even:
        add r13, r12    ; sum += nextFib

Store:
        mov r10, r11    ; fib1 = fib2
        mov r11, r12    ; fib2 = nextFib

        ;debug
        ;mov rax, r11
        ;call print      ;print(fib2)

        ;mov rax, r13
        ;call print      ;print(sum)

        ;debug off

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
        mov rax, r13
        call print      ;print(rax)

        mov rax, 1      ;Code for Exit Syscall
        mov rbx, 0      ;Return code of zero. All right, all right, alright
        int 80H         ;Make kernel call
