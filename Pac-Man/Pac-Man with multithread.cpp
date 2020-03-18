// thenk you Toru Iwatani
// non funziona 
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
int point=0,map[L][C],map1[L][C],v=0;

void print ();
void input (char);
void load ();
void *win (void *vargp);
void control();

int main (){
  char a;       // the choose
  pthread_t winning;
  pthread_create(&winning, NULL, win, NULL);

  for (int i=0;i<L;i++){ // for now, set to 0
    for (int j=0;j<C;j++){
      map [i][j]=0;
    }
  }
  load ();
  for (int i=0;i<L;i++){
    for (int j=0;j<C;j++){
      map1 [i][j]=map[i][j];
    }
  }
  print ();
  while (v!=1) {
    fflush(stdin);
    a=getche();
    input (a);
    control();
  }
  pthread_exit(NULL);
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

void control(){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// color cange
  for (int i=0;i<L;i++){
    for (int j=0;j<C;j++){
      if (map [i][j]!=map1[i][j]){
        vts_cursorXY(j*2,i);
        SetConsoleTextAttribute(hConsole, 14);// color cange
        switch (map [i][j]) {
          case -5:SetConsoleTextAttribute(hConsole, 0);printf("[" );vts_cursorXY(j*2+1,i);printf("]" );break;//enemy hose
          case -4:SetConsoleTextAttribute(hConsole, 10);printf(" " );vts_cursorXY(j*2+1,i);printf("&" );break;
          case -3:SetConsoleTextAttribute(hConsole, 13);printf(" " );vts_cursorXY(j*2+1,i);printf("&" );break;
          case -2:SetConsoleTextAttribute(hConsole, 5);printf(" " );vts_cursorXY(j*2+1,i);printf("&" );break;
          case -1:SetConsoleTextAttribute(hConsole, 12);printf(" " );vts_cursorXY(j*2+1,i);printf("&" );break;
          case 0:printf(" " );vts_cursorXY(j*2+1,i);printf(" " );break;                                      //empty
          case 1:printf(" " );vts_cursorXY(j*2+1,i);printf("@" );break;                                      //player
          case 2:printf(" " );vts_cursorXY(j*2+1,i);printf("o" );break;                                      //point
          case 3:SetConsoleTextAttribute(hConsole, 9);printf("[" );vts_cursorXY(j*2+1,i);printf("]" );break; //wall
          case 4:SetConsoleTextAttribute(hConsole, 0);printf("{" );vts_cursorXY(j*2+1,i);printf("}" );break; //teleport
        }
        SetConsoleTextAttribute(hConsole, 7);// color cange
      }
    }
  }
  for (int i=0;i<L;i++){
    for (int j=0;j<C;j++){
      map1 [i][j]=map[i][j];
    }
  }
  vts_cursorXY(L-5,C+1);
  printf("%d",point );
  vts_cursorXY(L-13,C+3);
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

void *win (void *vargp){
  int c=0;
  while (v!=1){
    for (int i=0;i<L;i++){
      for (int j=0;j<C;j++){
        if (map[i][j]==2){
          v=0;
          c=1;
        }
      }
    }
    if (c==0){
      v=1;
    }
  }
}












































// i need space
