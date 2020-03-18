/*Dato un vettore chiamato cognomi (con N elementi) contenente i cognomi degli studenti di una
classe e una matrice voti(NxC)che riporta i voti degli studenti in C materie, caricare casualmente la
matrice voti con valori interi compresi fra 1 e 10 e quindi visualizzare per ogni studente, il voto più
alto, quello più basso, e la media dei voti conseguiti. Inoltre contare per ogni studente il numero dei
voti negativi e il numero dei voi positivi. Infine visualizzare il numero di studenti promossi senza
alcun debito, quelli promossi con 1,2,3 debiti, e quelli respinti.
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

int const MAT=3,VOTI=3;
struct classe{
  int voti[MAT][VOTI];
  int media[MAT];
  int max[],min;
}


int caricamentoCognomi();
void inserimentoVoti(int n);

int main {

}

int caricamentoCognomi(){
  FILE *fp;
  int conta=0;
  fp=fopen("cognomi.txt","r");

  if(fp==NULL){
    printf("Errore file\n" );
    return -1;
  }

  while (!feof(fp)){
    fscanf(fp,"%s",&slasse[conta],cognome);
    conta++;
  }
  fclose(fp);
  return conta;
}

void inserimentoVoti(int n){
  srand ((unsigned)time(NULL));
  for (int i=0;i<n;i++){
    for (int j=0;j<=MAT;j++){
      classe[i].voti[j]=(rand()%8)+3;//voti da 3 a 10
    }
  }
}

void statistiche (int n){
  for (int i=0;i<n;i++){
    classe[i].media=0;
    for (int j=0;j<=MAT;j++){
      classe[i].media+=classe[i].voti[j];

    }
  }
}


































//space
