.model small
.stack 100h

.data 
msg1 db 'Enter A: $'
msg2 db 0dh, 0ah,'Enter B:$'
msg3 db 0dh, 0ah, 'Enter C= $' 
msg4 db 0dh, 0ah, 'A * b - c = $'
A db '?'
B db '?' 
C db '?'
result db '?'

   
.code    
main proc
    
    mov ax,@data
    mov ds, ax
    
    lea dx, msg1
    mov ah, 09h
    int 21h  
    
    mov ah, 01h
    int 21h
    sub al, 30h
    mov A, al
    
    lea dx, msg2
    mov ah, 09h
    int 21h
    
    mov ah,  01h
    int 21h
    sub al, 30h
    mov B, al  
    
    lea dx, msg3
    mov ah, 09h
    int 21h  
    
    mov ah, 01h
    int 21h
    sub al, 30h
    mov C, al
    
    
    mov al, A
    mul B
    sub al, C
    mov result, al
    
    lea dx, msg4
    mov ah, 09h
    int 21h
    
    
    add result, 30h
    mov dl, result
    mov ah, 02h
    int 21h
    
    mov ah, 4ch
    int 21h
    
    main endp
end main
      
    