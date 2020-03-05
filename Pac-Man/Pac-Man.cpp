/*
Aggiungere:
-multithreading
-nemici
-musica
-possibilità di mangiare i nemici

W=wall
P=player
B=point
E=enemy
V=void
T=teleport

-1=enemy
0=empty
1=player
2=point
3=wall
4=teleport

Fatto:
-iniziare con una versione semplificata soltanto con un rettangolo e la possibilità di muoversi
- pezzi da mangiare
-mappa  (idea: creare un .txt in cui vene salvata la mappa con caratteri speciali es. w=muro, p=payer; creare una funzione per essa e trasportarla nell'array)
-ostacoli e bordi
-inserimento senza invio
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "vts-nf.c"

const int L=21,C=20;//21x20
int point=0;

void print (int [L][C]);
void input (int [L][C],char);
void load (int [L][C]);
int win (int [L][C]);

int main (){
  int map[L][C],v=0; // the map,possibility of win
  char a;       // the choose

  for (int i=0;i<L;i++){ // for now, set to 0
    for (int j=0;j<C;j++){
      map [i][j]=0;
    }
  }
  load (map);

  while (v!=1) {
    print (map);
    fflush(stdin);
    a=getche();
    input (map,a);
    system ("cls");
    v=win(map);
  }
  printf("you win\n" );
}

void print (int map [L][C]){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// color cange
  SetConsoleTextAttribute(hConsole, 9);// color cange
  for (int i=0;i<L;i++){
    for (int j=0;j<C;j++){
      SetConsoleTextAttribute(hConsole, 14);// color cange
      switch (map [i][j]) {
        case -1:SetConsoleTextAttribute(hConsole, 9);printf("[]" );break;//enemy for the moment
        case 0:printf("  " );break;                                      //empty
        case 1:printf(" @" );break;                                      //player
        case 2:printf(" o" );break;                                      //point
        case 3:SetConsoleTextAttribute(hConsole, 9);printf("[]" );break; //wall
        case 4:SetConsoleTextAttribute(hConsole, 0);printf("{}" );break; //teleport
      }
      SetConsoleTextAttribute(hConsole, 9);// color cange
    }
    printf("\n");
  }
  SetConsoleTextAttribute(hConsole, 7);// color cange
  printf("\tpoint = %d",point );
  printf("\n\n\t" );
}

void input (int map [L][C],char a){ //control of the input
  for (int i=0;i<L;i++){
    for (int j=0;j<C;j++){
      if (map [i][j]==1){
        switch (a){
          case 'w':
          if (map [i-1][j]==4){
            map [i][j]=0;
            map [L-1][j]=1;
          }
          else if (i-1>=0 && map [i-1][j]!=3){
              if (map [i-1][j]==2)
                point++;
              map [i][j]=0;
              map [i-1][j]=1;j+=C+1;
              i+=L+1;
            }
            break;
          case 'a':
            if (map [i][j-1]==4){
              map [i][j]=0;
              map [i][C-3]=1;
            }
            else if (j-1>=0 && map [i][j-1]!=3){
              if (map [i][j-1]==2)
                point++;
              map [i][j]=0;
              map [i][j-1]=1;j+=C+1;
              i+=L+1;
            }
            break;
          case 's':
          if (map [i+1][j]==4){
            map [i][j]=0;
            map [1][j]=1;
          }
          else if (i+1<L && map [i+1][j]!=3){
              if (map [i+1][j]==2)
                point++;
              map [i][j]=0;
              map [i+1][j]=1;j+=C+1;
              i+=L+1;
            }
            break;
          case 'd':
            if (map [i][j+1]==4){
              map [i][j]=0;
              map [i][1]=1;
            }
            else if (j+1<L && map [i][j+1]!=3){
              if (map [i][j+1]==2)
                point++;
              map [i][j]=0;
              map [i][j+1]=1;j+=C+1;
              i+=L+1;
            }
            break;
        }
      }
    }
  }
}

void load (int map[L][C]){
  int c,i=0,j=0;
  FILE *file;
  file = fopen("map.txt", "r");
  if (file) {
    while ((c = getc(file)) != EOF){
      switch (c) {
        case 'E':map[i][j]=-1;break;
        case 'V':map[i][j]=0;break;
        case 'P':map[i][j]=1;break;
        case 'B':map[i][j]=2;break;
        case 'W':map[i][j]=3;break;
        case 'T':map[i][j]=4;break;
      }
      if (j==C-1){
        j=0;
        i++;
      }
      else
        j++;
    }
    fclose(file);
  }
}

int win (int map[L][C]){
  for (int i=0;i<L;i++){
    for (int j=0;j<C;j++){
      if (map[i][j]==2){
        return 0;
      }
    }
  }
  return 1;
}










































// i need space
