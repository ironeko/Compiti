; multi-segment executable file template.

data segment
    ; add your data here!
    N db 0
    M db 0
    quoz db 0
    rest db 0
    input db 10, 13, "inserisci il primo numero$"
    input2 db 10, 13, "inserisci il secondo numero$"
    output db 10,13, "quoz: $"
    output2 db 10, 13, "resto: $"
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
    ;input N
    lea dx, input
    mov ah, 9
    int 21h
    mov ah,1
    int 21h
    sub al, '0'
    mov N, al
    ;input M
    lea dx, input2
    mov ah, 9
    int 21h
    mov ah,1
    int 21h
    sub al, '0'
    mov M, al
    
    mov al, N
    xor cx,cx
    mov cx, M
ciclo:
    cmp M ,al
    jb poss
    jmp f1
poss:
    sub al, M
    inc quoz
f1:
    loop ciclo
    mov rest, al
     
    ;output quoz
    lea dx, output
    mov ah, 9
    int 21h
    
    add quoz, '0'
    mov dl, quoz
    mov ah, 2
    int 21h
    
    ;output rest
    lea dx, output2
    mov ah, 9
    int 21h
    
    add rest, '0'
    mov dl, rest
    mov ah, 2
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
