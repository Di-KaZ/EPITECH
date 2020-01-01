global strcmp
; ; rdi = str1
; ; rsi = str2

strcmp:
push rbp

_starting_point:
mov al, byte [rdi]
mov cl, byte [rsi]
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