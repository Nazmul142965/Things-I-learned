.model small
.stack 100h
.data

msg1 db  'Enter the First Value:$'
msg2 db 0Dh, 0Ah, 'Enter the Second Value:$'
msg3 db 0dh, 0ah, 'The result is:$'
num1 db '?'
num2 db '?'
result db '?'

.code 
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx, msg1
    mov ah, 09h
    int 21h
    
    mov ah, 01h  
    int 21h
    sub al, 30h
    mov num1, al
    
    
    lea dx, msg2
    mov ah, 09h
    int 21h   
    
    mov ah, 01h
    int 21h
    sub al, 30h
    mov num2, al 
    
    
    mov al, num1
    add al, num2
    mov result, al
    
    
    lea dx, msg3
    mov ah, 09h
    int 21h
     
     
    mov al, result 
    add al, 30h
    mov dl, al
    mov ah, 02h
    int 21h
    
    mov ah, 4ch
    int 21h
    
    main endp
end main