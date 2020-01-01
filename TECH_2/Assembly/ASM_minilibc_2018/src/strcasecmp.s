global strcasecmp
; ; rdi = str1
; ; rsi = str2

strcasecmp:
push rbp

_starting_point:
mov al, byte [rdi]
mov cl, byte [rsi]
test cl, cl
je _end
test al, al
je _end
jmp _convert_lowercase_first_al
_before_comparison:
cmp r9b, r10b
inc rdi
inc rsi
jne _starting_point

_end:
movsx eax, al
movsx ecx, cl
sub eax, ecx
pop rbp
ret

_convert_lowercase_first_al:
mov r9b, al
cmp r9b, 65
jnb _convert_lowercase_second_al
jmp _convert_lowercase_first_cl
_convert_lowercase_second_al:
cmp r9b, 90
jna _convert_al
jmp _convert_lowercase_first_cl
_convert_al:
add r9b, 32
jmp _convert_lowercase_first_cl

_convert_lowercase_first_cl:
mov r10b, cl
cmp r10b, 65
jnb _convert_lowercase_second_cl
jmp _before_comparison
_convert_lowercase_second_cl:
cmp r10b, 90
jna _convert_cl
jmp _before_comparison
_convert_cl:
add r10b, 32
jmp _before_comparison