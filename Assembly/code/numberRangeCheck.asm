.model small
.stack 100h
.data
msg db 'Enter A Charecter: $'
small_msg db 0dh, 0ah, 'Small$'
large_msg db 0dh, 0ah, 'Large$'
invalid_msg db 0dh, 0ah, 'Invalid$' 

.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx, msg
    mov ah, 09h
    int 21h
    
    mov ah, 01h
    int 21h
    
    cmp al, '0'
    jl invalid
    cmp al, '9'
    jg invalid
    cmp al, '5'
    jl small
    
    lea dx, large_msg
    jmp display
    
    small:
    lea dx, small_msg
    jmp display
    
    invalid:
    lea dx, invalid_msg
    jmp display 
    
    display:
    mov ah, 09h
    int 21h
    
   
    mov ah, 4ch
    int 21h
    
    main endp
end main

