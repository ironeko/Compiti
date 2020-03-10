/*le mie prove cl multithreading
Aggiungere:
-multithreading
-nemici
-musica
-possibilità di mangiare i nemici
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
const int L=21,C=20;
int map[L][C];
int point=0;

void load (){
  int c,i=0,j=0;
  FILE *file;
  file = fopen("map.txt", "r");
  if (file) {
    while ((c = getc(file)) != EOF){
      switch (c) {
        case 'E':map[i][j]=-5;break;
        case '1':map[i][j]=-1;break;
        case '2':map[i][j]=-2;break;
        case '3':map[i][j]=-3;break;
        case '4':map[i][j]=-4;break;
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
void print (){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// color cange
  SetConsoleTextAttribute(hConsole, 9);// color cange
  for (int i=0;i<L;i++){
    for (int j=0;j<C;j++){
      SetConsoleTextAttribute(hConsole, 14);// color cange
      switch (map [i][j]) {
        case -5:SetConsoleTextAttribute(hConsole, 0);printf("[]" );break;//enemy hose
        case -4:SetConsoleTextAttribute(hConsole, 10);printf(" &" );break;
        case -3:SetConsoleTextAttribute(hConsole, 13);printf(" &" );break;
        case -2:SetConsoleTextAttribute(hConsole, 5);printf(" &" );break;
        case -1:SetConsoleTextAttribute(hConsole, 12);printf(" &" );break;
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

void enemy (){
  int i=0,j=0,b[4],l[4][2];

  for (int p=0;p<4;p++){
    b [p]=2;
  }

  srand(time(NULL));
  for (int t=0;t<=6;t++){
    switch (t) {
      case 1:
        for (i=0;i<L;i++){
          for (j=0;j<C;j++){
            if (map [i][j]==-1){
              i+=L;
              j+=C;
            }
          }
        }
        i-=L+1;
        j-=C+1;

        if (point<10){// search angol
          if (map [i][j+1]!=3 && map [i][j+1]>=0 && l[0][1]!=j+1){
            if (map [i][j+1]==4){
              map [i][j]=b[0];
              b[0]=map [i][1];
              map [i][1]=-1;
            }
            else{
              map[i][j]=b[0];
              b[0]=map[i][j+1];
              map[i][j+1]=-1;
            }
          }

          else if (map [i-1][j]!=3 && map [i-1][j]>=0 && l[0][0]!=i-1){
            if (map [i-1][j]==4){
              map [i][j]=b[0];
              b[0]=map [L-1][j];
              map [L-1][j]=-1;
            }
            else{
              map[i][j]=b[0];
              b[0]=map[i-1][j];
              map[i-1][j]=-1;
            }
          }

          else if (map [i+1][j]!=3 && map [i+1][j]>=0 && l[0][0]!=i+1){
            if (map [i+1][j]==4){
              map [i][j]=b[0];
              b[0]=map [1][j];
              map [1][j]=-1;
            }
            else{
              map[i][j]=b[0];
              b[0]=map[i+1][j];
              map[i+1][j]=-1;
            }
          }

          else if(map [i][j-1]!=3 && map [i][j-1]>=0 && l[0][1]!=j-1){
            if (map [i][j-1]==4){
              map [i][j]=b[0];
              b[0]=map [i][C-3];
              map [i][C-3]=-1;
            }
            else{
              map[i][j]=b[0];
              b[0]=map[i][j-1];
              map[i][j-1]=-1;
            }
          }
          l[0][0]=i;
          l[0][1]=j;
        }
        else{// to the player

        };break;

      case 2:
      case 3:
      case 4:
        int a;
        for (i=0;i<L;i++){
          for (j=0;j<C;j++){
            if (map [i][j]==-4){
              i+=L;
              j+=C;
            }
          }
        }
        i-=L+1;
        j-=C+1;
        do{
          a=rand()%4;
          switch (a) {
            case 1:
              if (map [i][j+1]!=3 && map [i][j+1]>=0 && l[3][1]!=j+1){
                if (map [i][j+1]==4){
                  map [i][j]=b[0];
                  b[0]=map [i][1];
                  map [i][1]=-4;
                }
                else{
                  map[i][j]=b[0];
                  b[0]=map[i][j+1];
                  map[i][j+1]=-4;
                }
                a=0;
              }
              break;
            case 2:
            if (map [i-1][j]!=3 && map [i-1][j]>=0 && l[3][0]!=i-1){
              if (map [i-1][j]==4){
                map [i][j]=b[0];
                b[0]=map [L-1][j];
                map [L-1][j]=-4;
              }
              else{
                map[i][j]=b[0];
                b[0]=map[i-1][j];
                map[i-1][j]=-4;
              }
              a=0;
            }
            break;
            case 3:
              if (map [i+1][j]!=3 && map [i+1][j]>=0 && l[3][0]!=i+1){
                if (map [i+1][j]==4){
                  map [i][j]=b[0];
                  b[0]=map [1][j];
                  map [1][j]=-4;
                }
                else{
                  map[i][j]=b[0];
                  b[0]=map[i+1][j];
                  map[i+1][j]=-4;
                }
                a=0;
              }
              break;
            case 4:
              if(map [i][j-1]!=3 && map [i][j-1]>=0 && l[3][1]!=j-1){
                if (map [i][j-1]==4){
                  map [i][j]=b[0];
                  b[0]=map [i][C-3];
                  map [i][C-3]=-4;
                }
                else{
                  map[i][j]=b[0];
                  b[0]=map[i][j-1];
                  map[i][j-1]=-4;
                }
                a=0;
              }
          }
        }while (a!=0);
        l[3][0]=i;
        l[3][1]=j;
        break;
      case 5: print();Sleep(50);system("cls");t=0;break;
    }
  }
}

int main (){
  load();
  print();
  for (int i=0;i<L;i++){
    for (int j=0;j<C;j++){
      printf(" %d",map[i][j]);
    }
    printf("\n" );
  }
  printf("\n" );

  enemy();
}

















































//si
