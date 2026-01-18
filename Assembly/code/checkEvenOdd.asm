.model
.stack 100h

.data
msg db 'Enter the digit: $'
even_msg db 0dh , 0ah, 'EVEN$'
odd_msg db 0dh, 0ah, 'ODD$'


.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx, msg
    mov ah, 09h
    int 21h
    
    mov ah, 01h
    int 21h
    sub al, 30h
    
    and al, 1
    jz even
    
    
    lea dx, odd_msg
    jmp display
    
    
    even:
    lea dx,even_msg
    jmp display
    
    
    display:
    mov ah, 09h
    int 21h
    
    
    mov ah, 4ch
    int 21h
    
    main endp
end main