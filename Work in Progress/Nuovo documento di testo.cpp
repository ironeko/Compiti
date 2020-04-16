#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "../Librerie/menu.c"

int main (){
  int const N=4;
  char *pass[N]={'\0'};
  pass[0]="Florida";
  pass[1]="Oregon";
  pass[2]="California";
  pass[3]="Georgia";
  printf("\n\n\n%d\n\n\n",menuu("inizio bello\n\n",N,pass));
}
