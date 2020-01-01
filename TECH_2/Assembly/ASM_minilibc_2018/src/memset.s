global memset
; void *s = rdi
; int c = e esi
; size_t n = edx

memset:
push rbp
mov rcx, 0

_while_loop:
cmp rcx, rdx
je _end
mov [rdi + rcx], rsi
inc rcx
jmp _while_loop

_end:
mov rax, rdi
pop rbp
ret