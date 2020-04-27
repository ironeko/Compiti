;dati n numeri con n inserito da tastiera n < 65536 contare i numeri compresi tra 1000 - 10000
 
 ; macro InsN richiede una variabile word per il passaggio dei parametri 
 ; prende un numero 0 < 65536 InsN num-> parametro 
    
InsN macro p1 
    
local cicloIn, fineIn    

    pusha ;salva i valori dei registri nello stack
    mov p1, 0 
cicloIn:  
    mov ah,1
    int 21h
    cmp al,13
    je fineIn 
    sub al,'0'
    xor bx,bx
    mov bl,al
    mov ax,p1  
    mov cx,10
    mul cx
    add ax,bx
    mov p1,ax
    jmp cicloIn  
     
fineIn:
    popa ;ripristina i valori dei registri
endm        
    
data segment
    ; add your data here!    
    num dw 0
    cont dw 0
    strIn1 db "quanti numeri vuoi inserire$"
    strIn2 db 10,13,"dammi un numero$"
    strout1 db 10,13,"numeri compresi sono:$"
    n dw 0 
    pkey db 10,13,"press any key...$"
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
    lea dx,strIn1
    mov ah, 9
    int 21h
     
    InsN num
    mov cx,num
ciclo:
    lea dx,strIn2
    mov ah, 9
    int 21h        
    InsN n 
    cmp n, 1000
    jbe fineCont 
    cmp n, 10000          
    jae fineCont
    inc cont 
fineCont:                                     
    loop ciclo
     
    ;stampa
    lea dx,strout1
    mov ah, 9
    int 21h
     
    cmp cont, 10000
    jae cifre5
    cmp cont, 1000
    jae cifre4
    cmp cont, 100
    jae cifre3
    cmp cont, 10
    jae cifre2
    jmp cifre1 
      
cifre5:    
      mov bx,10000
      mov ax, cont
      xor dx,dx
      div bx
      mov cont,dx
      mov dl, al
      add dl,'0'
      mov ah, 2
      int 21h
cifre4:
      mov bx,1000
      mov ax, cont
      xor dx,dx
      div bx
      mov cont,dx
      mov dl, al
      add dl,'0'
      mov ah, 2
      int 21h
cifre3: 
      mov bx,100
      mov ax, cont
      xor dx,dx                 ;ok
      div bx
      mov cont,dx
      mov dl, al
      add dl,'0'
      mov ah, 2
      int 21h
cifre2:
      mov bx,10 
      mov ax, cont
      xor dx,dx
      div bx
      mov cont,dx
      mov dl, al
      add dl,'0'
      mov ah, 2
      int 21h
cifre1: 
      mov ax, cont    
      mov dl, al
      add dl,'0'
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
                                                 