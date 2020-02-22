/*data una matrice N*M
 inserisci i valori da tastiera
 stampa la matrice per righe
 trova il max e posizione del max
 trovare la somma della riga di indice 0 della matrice*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
const int N=3,M=3;

int main (){
  int mat[N][M],val,valx=0,valy=0;
  printf("inserisci i valori\n");
  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      scanf("%d",&mat [i][j]);
    }
  }
  printf("stampa per riga\n" );
  for (int j=0;j<M;j++){
    for (int i=0;i<M;i++){
      printf("%d\t",mat[j][i]);
    }
    printf("\n" );
  }

  val=mat[0][0];
  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      if (mat[i][j]>val){
        val=mat[i][j];
        valx=j;
        valy=i;
      }
    }
  }
  printf("\nil numero più grande è %d in posizione x=%d y=%d\n",val,valx,valy );
  val=0;
  for (int i=0;i<N;i++)
    val+=mat[0][i];
  printf("la somma è %d\n",val );
}
