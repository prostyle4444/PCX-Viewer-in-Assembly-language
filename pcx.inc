;----------------------------------------------
; PCX.inc
; Draws An PCX image on the screen
; ----------------------------------------------


Draw_PCX:
; -----------------------------------------------------------
; FUNCTION :- DRAWS AN PCX IMAGE ON VGA SCREEN 13 
; IN:-  DI = Y * 320 + x
;       SI = IMAGE SOURCE BUFFER
; OUT = NOTHING
; NOTE :- ALL REGISTERS DESTROYED
; ------------------------------------------------------------
start:

mov ax, 0
mov bx, 0
mov cx, 0
mov dx, 0
mov ax, 0A000h
mov es, ax


main:
mov cx, 1
lodsb
cmp al, 0C0h
jb putpixel
and al, 3Fh
mov cl, al
lodsb

putpixel:
rep stosb
cmp di, 64001
jb main


mov dx, 3c8h
mov al, 0
out dx, al
inc dx
mov cx, 256

setpal:
lodsb
shr al, 2
out dx, al
lodsb
shr al, 2
out dx, al
lodsb
shr al, 2
out dx, al
loop setpal
ret
