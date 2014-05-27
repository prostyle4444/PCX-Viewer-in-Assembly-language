use16
org 100h

mov al, 13h
int 10h
mov di, 0 
mov si, image+80h
call Draw_PCX
mov ah, 00h
int 16h
mov ax, 3
mov bx, 0
int 10h
ret

image:
file 'house.pcx' ; you can change it to whatever you want over here

include 'pcx.inc'
