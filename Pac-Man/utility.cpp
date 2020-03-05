//le mie prove cl multithreading

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <pthread.h>
#include "vts-nf.c"
const int L=21,C=20;

void *colorchange(void *vargp){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  for (int i=0;i<16;i++){
    SetConsoleTextAttribute(hConsole, i);
    if (i==15)
      i=0;
  }
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
  printf("\n\n\t" );
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

int main(){
  vts_activateCommands();
  int map[L][C];
  load (map);
  print(map);
  char ch;
  pthread_t thread;
  pthread_create(&thread, NULL, colorchange, NULL);
  vts_cursorXY(19,8);//11-3
  printf("c");
  pthread_exit(NULL);
  return 0;
}














































//si
