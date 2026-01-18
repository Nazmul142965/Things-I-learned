.model small
.stack 100h

.data 
msg1 db 'Enter A: $'
msg2 db 0dh, 0ah,'Enter B: $'
msg3 db 0dh,0ah, '2A + B^2 = $'
A db '?'
B db '?'
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
    
    mov ah, 01h
    int 21h
    sub al, 30h
    mov B, al
    
    mov al, A
    add al, A
    mov bl, B
    mul bl
    add al, bl
    mov  result, al
    
    
    lea dx, msg3
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
      
    