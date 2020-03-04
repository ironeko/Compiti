#include <stdio.h>
#include <windows.h>

int main(){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// color cange
  int c;
  FILE *file;
  file = fopen("map.txt", "r");
  if (file) {
    while ((c = getc(file)) != EOF){
      if (c=='W'){
        SetConsoleTextAttribute(hConsole, 9);
        printf("[]");
      }
      else if (c=='P'){
        SetConsoleTextAttribute(hConsole, 14);
        printf(" @");
      }
      else if (c=='B'){
        SetConsoleTextAttribute(hConsole, 14);
        printf(" o");
      }
      else if (c=='E'){
        SetConsoleTextAttribute(hConsole, 12);
        printf("[]");
      }
      else
        printf("\n" );
    }

    fclose(file);
}
}
