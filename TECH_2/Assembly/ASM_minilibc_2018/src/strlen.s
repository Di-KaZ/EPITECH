global strlen
; int strlen(char *rdi)
strlen:
push rbp
mov eax, -1 ; ca va etre notre size && valeur de retour

_while_loop: 
inc eax ; on incremente de 1 la size trouver 
cmp byte [rdi], 0 ; on compare le caratchere de rdi dereferencé avec 0 ('\0')
lea rdi, [rdi + 1] ; on deplace le pointeur de la string de 1
jne _while_loop ; c'est la qu'on utilise le compare et on jump a l'etiquette while_loop si le compare est pas vrai
pop rbp
ret ; si on arrive la on est au bout de la string et on revoit eax