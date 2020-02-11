//creare struct con data nome e cognome
//menù per ordinare la lista per tuttecose

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include "library1.c"
#define MAX 1

struct studente{
  char nome[40];
  char cognome[40];
  char data[10];
};

studente h[28];

void inserimento();
void stampa();

int main (){
  int a,c=1;
  do{
    system ("cls");
    printf("1)inserisci\n2)stampa in ordine di inserimento\n");
    scanf("%d",&a);
    switch (a) {
      case 1: inserimento();break;
      case 2: stampa();break;
      default: printf("errore\n");
    }
    system ("pause");
  }while (c!=0);
}

void inserimento(){
  for (int i=0;i<MAX;i++){
    printf("\ndimmi il nome dell %d^() studente:\t",++i);
    i--;
    scanf(" %s",&h[i].nome );
    printf("\ndimmi il cognome dell %d^() studente:\t",++i);
    i--;
    scanf(" %s",&h[i].cognome );
    printf("\ndimmi la data di nascita dell %d^() studente\n(gg-mm-aaaa):\t",++i);
    i--;
    scanf(" %s",&h[i].data );
  }
}

void stampa(){
  for (int i=0;i<MAX;i++){
    printf("studente %d\nnome:\t\t\t%s\ncognome:\t\t%s\ndata di nascita:\t%s\n",++i,h[i].nome,h[i].cognome,h[i].data );
    i--;
  }
}
