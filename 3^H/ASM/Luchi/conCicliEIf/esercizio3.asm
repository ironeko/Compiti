; multi-segment executable file template.

data segment
    ; add your data here! 
    N db 0
    M db 0
    num db 0 
    input db 10, 13, "inserisci il primo numero $"
    input2 db 10, 13, "inserisci il secondo numero $"
    acapo db 10, 13, "$"
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
    ;input N
    lea dx, input
    mov ah, 9
    int 21h
    mov ah, 1
    int 21h
    sub al, '0'
    mov N, al 
    
    xor ah, ah
    ;input M
    lea dx, input2
    mov ah, 9
    int 21h
    mov ah, 1
    int 21h 
    sub al, '0'
    mov M, al
    
    mov al, num
    
    xor cx,cx
    mov cx, M 
ciclo:
    add al, N
    loop ciclo
    mov num, al 
    ;a capo
    lea dx, acapo
    mov ah, 9
    int 21h
    
    ;output
    add num, '0'   
    mov dx, num
    mov ah, 2
    int 21h
    
    ;a capo
    lea dx, acapo
    mov ah, 9
    int 21h
         
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
