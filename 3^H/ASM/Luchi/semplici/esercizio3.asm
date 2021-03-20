; multi-segment executable file template.

data segment
    ; add your data here! 
    ;base altezza
    b db 5
    h db 4
    b2 db 0
    h2 db 0
    ;perimetro e area
    P db 0
    A db 0
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
    ;area 
    xor ax,ax
    mov al, b
    mov bl, h
    mul bl
    mov A, ax
    
    ;base X 2
    xor ax,ax
    mov al, b
    mov bl, 2
    mul bl
    mov b2, ax 
    
    ;altezza X 2
    xor ax,ax
    mov al, h
    mov bl, 2
    mul bl
    mov h2, ax
    
    ;perimetro
    mov al, b2
    add P, al
    mov al, h2
    add P, al
    
            
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
