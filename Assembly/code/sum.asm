.model small
.stack 100h
.data
.code

main proc
    
   mov ax, @data
   mov ds, ax
   
   mov ax, 6h
   mov bx, 4h
   
    
    
    add ax, bx
    
    main endp
end main
    
    
