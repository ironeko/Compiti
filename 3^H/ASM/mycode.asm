; multi-segment executable file template.

data segment
    ; add your data here!

    min db 0
    med db 0
    max db 0
    strInput db 10,13,"inserire un numero <10: $"
    strOut db 10,13,"i numeri ordinati sono: $"


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
    ;numeri da inserire
    lea dx,strInput
    mov ah,9
    int 21h
    mov ah,1
    int 21h
    sub al,'0'
    ;insert 1 num
    mov min,al
    mov med,al
    mov max,al
    ;insert other 2 num
    mov cx,2
Ciclo:
    lea dx,strInput
    mov ah,9
    int 21h
    mov ah,1
    int 21h
    sub al,'0'
    cmp al,max
    jbe minimo
massimo:
    mov bl,max
    mov med,bl
    mov med,bl
    jmp fineC
minimo:
    cmp al,max
    jbe medio
    mov bl,min
    mov med,bl
    mov min,bl
    jmp fineC
medio:
    mov med,al
fineC:
    loop ciclo
;stampo il risultato
    lea dx,strOut
    mov ah,9
    int 21h

    mov dl,min
    add dl,48
    mov ah,2
    int 21h

    mov dl,med
    add dl,48
    mov ah,2
    int 21h

    mov dl,max
    add dl,48
    mov ah,2
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
