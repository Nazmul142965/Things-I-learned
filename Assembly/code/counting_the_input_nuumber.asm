.model small
.stack 100h

.data
str db "nazmul$"
msg db "Capitalized: $"


.code

main proc
    
    mov ax, @data
    mov ds, ax
    mov es, ax
    
    
    cld
    mov si, offset str
    mov di, offset str
    
    
    cap_loop:
    
    
    lodsb
    
    cmp al, '$'
    je done
    
    
    cmp al, 'a' 
    jb store_char
    cmp al, 'z'
    ja store_char
    sub al, 32
    
    
    store_char: stosb
    jmp cap_loop     
    
    done:
    stosb
    
    
    mov dx, offset msg
    mov ah, 9
    int 21h
    
    mov dx, offset str
    mov ah, 9
    int 21h
    
    
    
    mov ah, 4ch
    int 21h
    
    
    main endp
end main
   
   