section .data
message: db "hello, World", 10

section .text
global _start
_start:
    mov rax, 1          ; syscall number. 1 is write
    mov rdi, 1          ; 1st argument.   dest file descriptor number. 1 is stdout
    mov rsi, message    ; 2nd argument.   input data start address
    mov rdx, 13         ; 3rd argument.   input data length
    syscall

    mov rax, 60         ;  syscall number. 60 is exit
    xor rdi, rdi        ; 1st argument register
    syscall