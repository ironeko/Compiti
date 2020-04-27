;-------------------------------------------------
; Prende un numero <65536 (variavile word) come parametro di ingresso, 
; e lo stampa a video (N alla fine della stampa perde il valore)
; es: stampaN N  (nel seg dati ho dichiarato N dw 54321)
;	stampa 54321 a video, N diventa 0
;-------------------------------------------------

stampaN macro p1
    local unita,decine,centinaia,migliaia,dieciMigliaia,ciclostampa   
    pusha
    cmp p1,10000
    jae dieciMigliaia
    cmp p1,1000
    jae migliaia
    cmp p1,100
    jae centinaia
    cmp p1,10
    jae decine
    jmp unita
dieciMigliaia: 
    mov bx,10000
    jmp cicloStampa
migliaia: 
    mov bx,1000
    jmp cicloStampa
centinaia:
    mov bx,100
    jmp cicloStampa 
decine:
    mov bx,10
    jmp cicloStampa
unita:
    mov bx,1 
    
cicloStampa:    
    xor dx,dx
    mov ax,p1  ;1
    div bx        ;1
    mov p1,dx  ;0
    mov dl,al     ;stampo 0
    add dl,'0'
    mov ah,2
    int 21h
    xor dx,dx
    mov ax,bx 
    mov bx,10     ;0
    div bx 
    mov bx,ax     ;0
    cmp ax,0
    jne cicloStampa  
    popa       
endm