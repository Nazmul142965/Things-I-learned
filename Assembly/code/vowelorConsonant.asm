.model
.stack 100h

.data
msg db 'Enter the Charecter: $'
vowel_msg db 0dh , 0ah, 'Vowel$'
consonant_msg db 0dh, 0ah, 'Consonant$'


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
    je vowel
    cmp al, 'e'
    je vowel
    cmp al, 'i'
    je vowel
    cmp al, 'o'
    je vowel
    cmp al, 'u'
    je vowel
    
    lea dx, consonant_msg
    jmp display
    
    
    vowel:
    lea dx, vowel_msg
    jmp display
    
    
    display:
    mov ah, 09h
    int 21h
    
    
    mov ah, 4ch
    int 21h
    
    main endp
end main