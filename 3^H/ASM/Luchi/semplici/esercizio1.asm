; multi-segment executable file template.

data segment
    ; add your data here! 
    N db 5
    M db 3
    som db 0
    sot db 0
    molt db 0
    quoz db 0
    rest db 0
    pkey db "press any key...$"
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
    ;somma 
    mov al, N
    add al, M
    mov som, al 
    
    ;sottrazione
    mov al, N
    sub al, M
    mov sot, al
    
    ;moltiplicazione
    mov al, N
    mov bl, M
    Mul bl
    mov molt, ax 
    
    ;divisione
    xor ax, ax
    mov al, N
    mov ax, al
    mov bl, M
    div bl
    mov quoz, al
    mov rest, ah
    
            
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
