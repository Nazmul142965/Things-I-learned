.model small
.stack 100h
.data 

msg1 db 'Enter A lowercase Letter: $'
msg2 db 0Dh, 0Ah, 'In uppercase it is: $'

.code
main proc  
    mov ax, @data
    mov ds, ax
    
    lea dx, msg1       ;propmt
    mov ah, 09h
    int 21h  
    
    mov ah, 01h       ;input
    int 21h 
    
    sub al, 20h        ;covert
    
    mov bh, al
    
    lea dx, msg2        ;display value
    mov ah, 09h
    int 21h
    
    
    mov dl, bh
    mov ah, 02h
    int 21h
    
    
    mov ax, 4c00h
    int 21h
    
    main endp
end main
    