#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int const MAX=8; //change MAX to the numbero fo possibility +1 (for exit)
  int ch1, ch2,now=0,finish=0; //ch1 and e are use for getch(), now is the select line and finish is a boolean value for the loop
    do{
      SetConsoleTextAttribute(hConsole, 15);
      printf("***Caption****\n\n" );
      char menu [MAX][100]; //change operation with the text to print
      strcpy(menu [0],"operation 1");//change the number of thit line with MAX
      strcpy(menu [1],"operation 2");
      strcpy(menu [2],"operation 3");
      strcpy(menu [3],"operation 4");
      strcpy(menu [4],"operation 5");
      strcpy(menu [5],"operation 6");
      strcpy(menu [6],"operation 7");
      strcpy(menu [7],"EXIT");

      for (int i=0;i<MAX;i++){
        if (i==now){
          SetConsoleTextAttribute(hConsole, 12);//change color
          printf("-> ");
        }
        else SetConsoleTextAttribute(hConsole, 15);
        printf("%s\n",menu[i]);
      }

      ch1 = getch();
      ch2 = 0;
      if (ch1 == 0xE0) {
        ch2 = getch();
        switch(ch2){
          case 72: now--; break;//up
          case 80: now++; break;//down
        };
      }
      else if(ch1==13)finish++;//enter
      else printf("key pressed: %d %c\n", ch1, ch2);//in case of error
      if (now<0) now=0;
      if (now>MAX-1) now=MAX-1;
      system ("cls");
    }while(finish!=1);
  printf("output number %d\n",now );
  system("pause");
  return 0;
}
