.model small
.stack 100h
.data
msg db 'Enter A Charecter: $'
correct_msg db 0dh, 0ah,'correct$'
wrong_msg db 0dh, 0ah, 'wrong$'

.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx, msg
    mov ah, 09h
    int 21h
    
    mov ah, 01h
    int 21h
    
    cmp al, 'a'
    je print_correct
    
    lea dx, wrong_msg
    jmp print_msg
    
    print_correct:
    lea dx, correct_msg
    jmp print_msg 
    
    print_msg:
    mov ah, 09h
    int 21h
    
    mov ah, 4ch
    int 21h
    
    main endp
end main

