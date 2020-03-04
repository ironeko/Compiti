/*
vorrei iniziare con una versione semplificata soltanto con un rettangolo e la possibilità di muoversi,
in seguito voglio aggiungere:
X pezzi da mangiare
-ostacoli
-nemici
-mappa
-multithreading
-inserimento senza invio
-musica
-possibilità di mangiare i nemici
*/


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>

const int L=9,C=9;
int point=0;

void print (int [L][C]);
void input (int [L][C],char);

int main (){
  int map[L][C]; // the map
  char a;       // the choose

  for (int i=0;i<L;i++){ // for now, set to -1
    for (int j=0;j<C;j++){
      map [i][j]=-1;
    }
  }

  map [L/2] [C/2]=1; //Creat the player

  //-1=point
  //0=empty
  //1=player
  //2=enemy

  while (L!=0) {
    print (map);
    fflush(stdin);
    scanf("%c",&a);
    input (map,a);
    system ("cls");
  }
}

void print (int map [L][C]){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 9);
  printf("\n\t-------------------------------------\n" );
  for (int i=0;i<L;i++){
    printf("\t" );
    for (int j=0;j<C;j++){
      printf("|");
      SetConsoleTextAttribute(hConsole, 14);
      if (map [i][j]==0){
        printf("   " );
      }
      else if (map [i][j]==1){
        printf(" @ " );
      }
      else if (map [i][j]==-1){
        printf(" o " );
      }
      SetConsoleTextAttribute(hConsole, 9);
    }
    printf("|");
    printf("\n\t-------------------------------------\n" );
  }
  SetConsoleTextAttribute(hConsole, 7);
  printf("\tpoint = %d",point );
  printf("\n\n\t" );
}

void input (int map [L][C],char a){
  switch (a) {
    case 'w':
      for (int i=0;i<L;i++){
        for (int j=0;j<C;j++){
          if (map [i][j]==1){
            if (map [i-1][j]==-1)
              point++;
            map [i][j]=0;
            map [i-1][j]=1;
            j+=C+1;
            i+=L+1;
          }
        }
      };break;
    case 'a':for (int i=0;i<L;i++){
      for (int j=0;j<C;j++){
        if (map [i][j]==1){
          if (map [i][j-1]==-1)
            point++;
          map [i][j]=0;
          map [i][j-1]=1;
          j+=C+1;
          i+=L+1;
        }
      }
    };break;
    case 's':for (int i=0;i<L;i++){
      for (int j=0;j<C;j++){
        if (map [i][j]==1){
          if (map [i+1][j]==-1)
            point++;
          map [i][j]=0;
          map [i+1][j]=1;
          j+=C+1;
          i+=L+1;
        }
      }
    };break;
    case 'd':for (int i=0;i<L;i++){
      for (int j=0;j<C;j++){
        if (map [i][j]==1){
          if (map [i][j+1]==-1)
            point++;
          map [i][j]=0;
          map [i][j+1]=1;
          j+=C+1;
          i+=L+1;
        }
      }
    };break;
    default: printf("Error\n" );system("pause");
  }
}















































// i need space
