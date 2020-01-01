;rdi = s
;rsi = c
global rindex

rindex:
push rbp
mov rax, 0
_go_to_end_ptr:
movsx edx, byte [rdi]
cmp edx, 0
je _end
cmp edx, esi
je _change_last
_changed:
inc rdi
jmp _go_to_end_ptr

_end:
pop rbp
ret

_change_last:
mov rax, rdi
jmp _changed