/* esercizio in testi Trasformaimmagine.txt*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

#define PX 3
#define WHI 2

const int r=4,c=3;

void print(int [][c][PX]);

int main (){
  srand((unsigned)time(NULL));
  /*
  printf("dimmi la grandezza dell'immagine;\nX = ");
  scanf(" %d",&c );

  printf("Y = " );
  scanf(" %d",&r );
  r=a+2;
  */


  int imm [r][c][PX],a;
  print(imm);

  for (int i=0;i<r;i++){
    printf("\nriga %d\n",++i );
    i--;
    for (int j=0;j<c;j++){
      printf("\ncolonna %d\n",++j );
      j--;
      for (int d=0;d<PX;d++){
        printf("inserisci pixell numero %d:\t",++d );
        d--;
        //scanf("%d\n",&imm [i][j][d]);
        imm [i][j][d]=rand ()%255;
        if (imm [i][j][d]<0||imm [i][j][d]>255){
          printf("imput non valido\n" );
          d--;
        }
      }
    }
  }
  print(imm);







}



void print(int imm [][c][PX]){
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  printf("\n\n-----stampo-----\n\n" );
  for (int i=0;i<r;i++){
    printf("%d)\t",++i );
    i--;
    for (int j=0;j<c;j++){
      for (int d=0;d<PX;d++){
        printf(" %d ",imm [i][j][d] );
      }
      printf(" | ");
    }
    printf("\n");
  }
}


























//i need space
