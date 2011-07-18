GLOBAL beep

beep:	
	push ebp
	mov ebp, esp
	sub esp, 120
	mov bx, 0x80
	in al, 0x61
	push ax
b1:	and al,11111100b
	out 0x61, al
b2:	mov cx, 0x80	; delay
b3:	loop b3
	xor al, 00000010b
	out 0x61, al
	test al, 00000010b
	jz b2
	dec bx
	jnz b1
	pop ax
	out 0x61, al
	mov cx, 0x32
b4:	loop b4
	leave
	ret
