;-------------------------------------------------
; Prende un numero da tastiera <65536
; e lo mette in N (N di tipo word)
; es: insN N  (nel seg dati ho dichiarato N dw ?)
;-------------------------------------------------

insN macro p1  
    local inserimento, fineInserimento
   
   pusha   
    mov p1,0
inserimento: 
    mov ah,1
    int 21h   
    cmp al,13
    je fineinserimento 
    sub al,'0'
    mov bl,al 
    mov ax,p1 
    mov cx,10
    mul cx
    xor bh,bh 
    add ax,bx 
    mov p1,ax
    jmp inserimento
fineInserimento:        
    popa
endm 