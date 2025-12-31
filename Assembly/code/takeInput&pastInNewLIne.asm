.model small
.stack 100h
.data

.code
main proc
    
    
    mov ax, @data
    mov ds, ax


    mov ah, 01h
    int 21h 
    
    mov bl, al
    
    mov ah, 02h
    mov dl, 10
    int 21h
    
    mov ah, 02h
    mov dl, 13
    int 21h
    
    mov ah, 02h
    mov dl, bl
    int 21h
    
    mov ah, 4ch
    int 21h
    
    main endp
end main
