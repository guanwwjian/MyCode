SSEG SEGMENT
	db 100 dup(?)
	tos db ?
SSEG ENDS
DSEG SEGMENT
	str db "0123456789ABCDEF"
	ans db 4 dup(?),'h',13,10,'$'
DSEG ENDS
ESEG SEGMENT

ESEG ENDS
CSEG SEGMENT
	assume ss:SSEG, ds:DSEG, es:ESEG, cs:CSEG
MAIN PROC FAR
	mov ax,SSEG
	mov ss,ax
	mov ax,DSEG
	mov ds,ax
	mov ax,ESEG
	mov es,ax
	;mov ax,10AFh
	mov bx,ax
	and bx,000Fh
	mov bl,str [bx]
	mov ans [3],bl
	mov bx,ax
	mov cl,4
	shr bx,cl
	and bx,000Fh
	mov bl,str [bx]
	mov ans [2],bl
	mov bx,ax
	mov cl,8
	shr bx,cl
	and bx,000Fh
	mov bl,str [bx]
	mov ans [1],bl
	mov bx,ax
	mov cl,12
	shr bx,cl
	and bx,000Fh
	mov bl,str [bx]
	mov ans [0],bl
	mov ah,9
	mov dx,offset ans
	int 21h
	
	mov ah,4ch
	int 21h
	
MAIN ENDP

CSEG ENDS

END MAIN