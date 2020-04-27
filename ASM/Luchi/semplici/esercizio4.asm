; multi-segment executable file template.

data segment
    ; add your data here!  
    A db 5 ;altezza
    B db 3 ;base
    C db 4 ;ipotenusa
    P db 0
    Area db 0
    due db 2
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
    ;perimetro
    mov al, A
    add P, al
    mov al, B
    add P, al
    mov al, C
    add P, al
    
    ;area
    xor ax, ax
    mov ax, A
    mov bl, B
    mul bl
       
    mov bl, due
    div bl
    mov Area, al
            
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
