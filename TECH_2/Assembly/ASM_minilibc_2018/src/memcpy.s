global memcpy
; void *dest = rdi
; void *src = rsi
; size_t n = rdx

memcpy:
push rbp
mov rcx, 0

_while_loop:
cmp rcx, rdx
je _end
mov r9b, [rsi]
mov [rdi + rcx], r9b
inc rsi
inc rcx
jmp _while_loop

_end:
mov rax, rdi
pop rbp
ret