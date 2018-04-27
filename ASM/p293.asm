assume cs: code

code segment
start:
	mov al, 100
	call showbyte

	mov ax, 4c00h
	int 21h

showbyte:
	jmp short show
	table db '0123456789ABCDEF'

show:
	push bx
	push es

	mov ah, al
	mov cl, 4
	shr ah, cl
	and al, 00001111b

	mov bl, ah
	mov bh, 0
	mov ah, table[bx]

	mov bx, 0b800h
	mov es,bx
	mov es:[160*12+40*2], ah

	mov bl, al
	mov bh, 0
	mov al, table[bx]

	mov es:[160*12+40*2+2], al

	pop es
	pop bx
	ret

code ends
end start