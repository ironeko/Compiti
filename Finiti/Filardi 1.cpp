/*Esercizio 1
Una matrice si dice Ordinata per Righe se gli elementi di ogni riga sono ordinati in ordine crescente da sinistra verso destra e tutti gli elementi di ogni riga, esclusa la prima, sono maggiori di ciascuno degli elementi della riga precedente.
Scrivere un programma C che permetta di
1. caricare la matrice (chiedendo le dimensioni della stessa all'utente entro certi limiti),
2. stampare la matrice (realizzare cornice)
3. chiamare una funzione ordRighe() che restituisce true se la matrice data è ordinata per righe false altrimenti*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <strings.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

const int MAX=100;
int mat[MAX][MAX],r,c;

void carica_matrice ();
void stampa_matrice ();
bool ordRighe ();

int main (){
  printf("inserisci in numero di righe:\t" );
  scanf("%d",&r);
  printf("inserisci in numero di colonne:\t" );
  scanf("%d",&c);
  carica_matrice();
  stampa_matrice();
  bool ord=ordRighe();
  if (ord==true) printf("TRUE\n" );
  else printf("FALSE\n" );
}

void carica_matrice (){
  //srand(time(NULL));
  for (int i=0;i<r;i++){
    for (int j=0;j<c;j++) {
      printf("iserisci il dato:\t");
      scanf("%d",&mat[i][j]);
      //mat[i][j] = rand()%100;
    }
  }
  system("cls");
}

void stampa_matrice (){
  for (int i=0;i<r;i++){
    for (int j=0;j<c;j++) {
      printf("%3sd ",mat[i][j]);
    }
    printf("\n");
  }
}

bool ordRighe (){
  int a=mat [0][0];
  for (int i=0;i<r;i++){
    for (int j=0;j<c;j++) {
      if (mat[i][j]<a){
        return false;
      }
      a=mat[i][j];
    }
  }
  return true;
}

























//space
