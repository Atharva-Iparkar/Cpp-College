%macro disp 2
Mov rax,1
Mov rdi,1
Mov rsi,%1
Mov rdx,%2
syscall
%endmacro

section .bss
arr resb 100

section .data
msg1 db "Enter 5 numbers : ",10
len1 equ $ -msg1
msg2 db "Entered numbers are : ",10
len2 equ $ -msg2
count db 05

section .text
global _start:
_start:

Mov rbx,00
disp msg1,len1

up:Mov rax,0
Mov rdi,0
Mov rsi,arr
add rsi,rbx
Mov rdx,17
syscall
add rbx,17
syscall
dec byte[count]
JNZ up
   

Mov byte [count],05
Mov rbx,00
disp msg2,len2
up1:Mov rax,1
Mov rdi,1
Mov rsi,arr
add rsi,rbx
Mov rdx,17
syscall
add rbx,17
dec byte[count]
JNZ up1

Mov rax,60
Mov rdi,0
syscall

