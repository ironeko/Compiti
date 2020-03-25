; multi-segment executable file template.

data segment
    ; add your data here!
    ;dato un numero minore di 15 eleverlo alla seconda

    dieci db 10
    cento db 100
    n db 0
    somma db 0
    strin db 10,13,"dammi un numero <16:$"
    strerr db 10,13, "numro maggiorre o uguale a 16:$"
    strout db 10,13, "il risultato e': $"
    pkey db 10,13,"press any key...$"  ;10,13 serve per andare a capo

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

    lea dx,strin
    mov ah,9
    int 21h
    ;prendiamo il primo numero
cicloin:
    mov ah,01
    int 21h
    cmp al,13
    je finein
    sub al,'0'
    mov bl,al
    mov al,n
    mul dieci
    add al,bl
    mov n,al
    jmp cicloin
finein:
    cmp n,15
    jbe finecontrolloin
    lea dx,strerr
    mov ah,9
    int 21h
    mov n,0
    lea dx,strin
    mov ah,9
    int 21h
    jmp cicloin

finecontrolloin:

    ;ciclo per calcolare il quadrato
    mov ch,0
    mov cl,n

calcolo:
    mov bl,n
    add somma,bl
    loop calcolo

;---------metodo prof---------------
;sommare i primi n numeri rispari
    ;mov bl,1
    ;mov ch,0
    ;mov cl,n

;calcolo:
    ;add somma,bl
    ;add bl,2
    ;loop calcolo
;---------metodo prof---------------

    ;stampo

    lea dx,strout
    mov ah,09
    int 21h

    cmp somma,100
    jae centinaia
    cmp somma,10
    jae decine
    jmp unita

centinaia:
    mov ah,0
    mov al,somma
    div cento
    mov somma,ah
    add al,48
    mov dl,al
    mov ah,2
    int 21h
decine:
    mov ah,0
    mov al,somma
    div dieci
    mov somma,ah
    add al,48
    mov dl,al
    mov ah,2
    int 21h
unita:
    mov dl,somma
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
