/*
Aggiungere:
-multithreading
-inserimento senza invio
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
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>

const int L=21,C=20;
int point=0;

void print (int [L][C]);
void input (int [L][C],char);
void load (int [L][C]);

int main (){
  int map[L][C]; // the map
  char a;       // the choose

  for (int i=0;i<L;i++){ // for now, set to 0
    for (int j=0;j<C;j++){
      map [i][j]=0;
    }
  }
  load (map);

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
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// color cange
  SetConsoleTextAttribute(hConsole, 9);// color cange
  printf("\n\n\n\n" );
  for (int i=0;i<L;i++){
    printf("\t" );
    for (int j=0;j<C;j++){
      SetConsoleTextAttribute(hConsole, 14);// color cange
      if (map [i][j]==0){ // if is empty don't write
        printf("  " );
      }
      else if (map [i][j]==1){// if is 1 write player
        printf(" @" );
      }
      else if (map [i][j]==2){// if is 2 write point
        printf(" o" );
      }
      else if (map [i][j]==3){// if is 3 write wall
        SetConsoleTextAttribute(hConsole, 9);// color cange
        printf("[]" );
      }
      else if (map [i][j]==4){// if is 3 write wall
        SetConsoleTextAttribute(hConsole, 0);// color cange
        printf("{}" );
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
            if (i-1>=0 && map [i-1][j]!=3){
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
            if (i+1<L && map [i+1][j]!=3){
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
      if (c=='W'){
        map[i][j]=3;
      }
      else if (c=='P'){
        map[i][j]=1;
      }
      else if (c=='B'){
        map[i][j]=2;
      }
      else if (c=='E'){
        map[i][j]=-1;
      }
      else if (c=='V'){
        map[i][j]=0;
      }
      else if (c=='T'){
        map[i][j]=4;
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












































// i need space
