; multi-segment executable file template.

data segment
    ; add your data here! 
    N db 5
    M db 3 
    som db 0
    due db 2
    med db 0 
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
    ;divisione
    xor ax,ax
    mov al, som 
    mov ax, al
    mov bl, 2
    div bl
    ;media con il resto
    mov med, al
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
