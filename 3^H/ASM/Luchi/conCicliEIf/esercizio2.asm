; multi-segment executable file template.

data segment
    ; add your data here!
    conta db 0
    num db 0    
    strin db 10, 13, "quanti numeri vuoi inserire $" 
    strin2 db 10, 13, "inserisci un numero $"
    
    pkey db 10, 13, "numeri => di 5 -> $"
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax

    ; add your code here 
    
    ;input 1
    lea dx, strin
    mov ah, 9
    int 21h
    mov ah, 1
    int 21h
    sub al, '0'
    xor cx, cx 
    mov cl, al
    
ciclo:  
    ;input del numero
    lea dx, strin2
    mov ah, 9
    int 21h
    mov ah,1
    int 21h
    sub al, '0'
    ;if num inserito >= 5
    cmp al,5
    ja somma
    jmp fineS   
somma:
      inc conta
fineS:         

    loop ciclo             

    ;output string       
    lea dx, pkey
    mov ah, 9
    int 21h
    ;output number
    add conta, 48
    mov dl, conta        
    lea dx, conta
    mov ah, 9
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
