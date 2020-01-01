global strchr

strchr:
push rbp

_starting_point:
movsx eax, byte [rdi]
inc rdi
cmp eax, esi
je _end
test eax, eax
jne _starting_point
mov rax, 0
pop rbp
ret

_end:
dec rdi
mov rax, rdi
pop rbp
ret
