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
        case -5:SetConsoleTextAttribute(hConsole, 9);printf("[]" );break;//enemy hose
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
  int i=0,j=0,b1=0,b2=0,b3=0,b4=0,x=0,y=0;
  srand(time(NULL));
  for (int t=0;t<=6;t++){
    printf("ciao for della t\n" );
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
      printf("%d %d,   %d\n",i,j,map[i][j] );

      if (point<10){// search angol possibiltà if srand le i 2 possibili muovimenti else gli altri 2
        printf("sono nel primo if bella\n" );
        if (map [i-1][j+1]!=3 && map [i-1][j+1]>=0){
          map [i][j]=b1;
          b1=map [i-1][j+1];
          map [i-1][j+1]=-1;
        }
        else {
          do{
            do{
              do{
                x=rand()%2-1;
                y=rand()%2-1;
              }while(x==y);
            }while(x!=0 || y!=0);

            printf("%d %d ,%d %d\n",y,x,i+y,j+x );
          }while (map[i+y][i+x]==3 && map [i+y][j+x]<=0 );
            map [i][j]=b1;
            b1=map [i+y][j+x];
            map [i+y][j+x]=-1;

        }
        print();
      }
      case 2:
      case 3:
      case 4:
      case 5: sleep(500);t=0;break;
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
