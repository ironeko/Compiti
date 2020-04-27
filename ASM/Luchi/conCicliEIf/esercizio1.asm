; multi-segment executable file template.

data segment
    ; add your data here!  
    N db 0 
    max db 0
    min db 0
    num db 0
    input db 10, 13, "quanti numeri vuoi inserire?: $" 
    input2 db 10, 13, "inserisci un numero $"
    pkey db 10, 13, "press any key...$"
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
    ;input per ciclo
    lea dx, input
    mov ah, 9
    int 21h
    mov ah, 1
    int 21h
    sub al, '0'
    mov N, al 
    
    ;input numero
    lea dx, input2
    mov ah, 9
    int 21h  
    mov ah, 1
    int 21h
    sub al, '0'
    mov min, al
    
    sub N, 1   
    xor cx, cx
    mov cx, N
    mov max, al
ciclo:     
    ;input numero
    lea dx, input2
    mov ah, 9
    int 21h  
    mov ah, 1
    int 21h
    sub al, '0'  
        
    ;controllo
    cmp al, min
    jb newMi
    jmp f2
newMi:  
    mov min, al
f2:    
    cmp al, max
    jg newMa
    jmp f1
newMa:
    mov max, al    
f1:
    loop ciclo
    
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
