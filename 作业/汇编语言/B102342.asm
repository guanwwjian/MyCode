;程序模板

SSEG SEGMENT PARA STACK 'stack'
	dw 100h dup(0) ;初始化堆栈大小为100
SSEG ENDS

DSEG SEGMENT
	;数据段：在此处添加程序所需的数据
	d1 db "Monday$"
	d2 db "Tuesday$"
	d3 db "Wednesday$"
	d4 db "Thirsday$"
	d5 db "Friday$"
	d6 db "Saturday$"
	d7 db "Sunday$"
	error db "error!$"
	enter db 13,10,"$"
	casetab dw error,d1,d2,d3,d4,d5,d6,d7
DSEG ENDS

ESEG SEGMENT
	;附加段：在此处添加程序所需的数据
ESEG ENDS

CSEG SEGMENT
	assume  cs:CSEG, ds:DSEG, es:ESEG, ss:SSEG


	
MAIN PROC FAR  	;主程序入口

	mov ax, dseg
	mov ds, ax
	mov ax, eseg
	mov es, ax
	mov ax, sseg
	mov ss, ax

	;此处添加主程序代码
repeat:	mov ah,1
	int 21h
	sub al,'0'
	jz exit
	mov bx, 0000h
	cmp al,1
	jb err
	cmp al,7
	ja err
	mov bl,al
err:	sal bx,1
	mov ah,9
	mov dx,offset enter
	int 21h
	mov dx, casetab [bx]
	int 21h
	mov dx,offset enter
	int 21h
	jmp repeat

exit:	mov ax, 4c00h  ;程序结束，返回到操作系统系统
	int 21h
MAIN ENDP
	
CSEG ENDS

END MAIN