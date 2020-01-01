global strncmp

strncmp:
push rbp
_starting_point:
dec edx
mov al, byte [rdi]
mov cl, byte [rsi]
cmp edx, 0
je _end
test cl, cl
je _end
test al, al
je _end
cmp al, cl
inc rdi
inc rsi
jne _starting_point

_end:
movsx eax, al
movsx ecx, cl
sub eax, ecx
pop rbp
ret