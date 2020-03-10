// thenk you Toru Iwatani

/*
on map.txt
W=wall
P=player
B=point
E=enemy house
V=void
T=teleport

in the code
-5=ghost house
-4=Clyde  (the orange Ghost)
-3=Pinky  (the pink Ghost)
-2=Inky   (the blue Ghost)
-1=Blinky (the red Ghost)
0=empty
1=player
2=point
3=wall
4=teleport
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
int point=0,map[L][C];

void print ();
void input (char);
void load ();
int win ();

int main (){
  int v=0; // possibility of win
  char a;       // the choose



  for (int i=0;i<L;i++){ // for now, set to 0
    for (int j=0;j<C;j++){
      map [i][j]=0;
    }
  }
  load ();

  vts_cursorXY(0,0);
  print ();

  /*
  while (v!=1) {
    print ();
    fflush(stdin);
    a=getche();
    input (a);
    system ("cls");
    v=win();
  }*/
  printf("you win\n" );
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

void input (char a){ //control of the input
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

int win (){
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
