#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include "../Librerie/vts-nf.c"

int main (){
  float a,x=0;
  printf("inserisci base:\t");
  scanf("%f",&a);
  system ("cls");
  for (int i=0;i<=10;i++){
    vts_cursorXY(0,i);
    printf("%2d|",++i);
    i--;
  }
  for (int i=10;i>=0;i--){
    vts_cursorXY(3+pow(a,x),i);
    printf("%.0f",pow(a,x));
    x++;
  }
  vts_cursorXY(11,11);
}
