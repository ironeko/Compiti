#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "../Librerie/menu.c"

int main (){
  int N=4;
  char *pass[N];
  pass[0]="Florida";
  pass[1]="Oregon";
  pass[2]="California";
  pass[3]="Georgia";
  printf("\n\n\n%d\n\n\n",create_menu("inizio bello\n\n",N,pass));
}
