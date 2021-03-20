/*beta 0.3  ~ Ironeko ~

example:

int main (){
  int const N=4;
  char *pass[N]={'\0'};
  pass[0]="Florida";
  pass[1]="Oregon";
  pass[2]="California";
  pass[3]="Georgia";
  printf("\n\n\n%d\n\n\n\n",menuu("inizio bello\n\n",N,pass));
}

Problems:
- warning: deprecated conversion from string constant to 'char*'
- multi platform
- not use cls

*/

int create_menu(char *caption,int MAX,char **menu){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int ch1, ch2,now=0,finish=0; //ch1 and e are use for getch(), now is the select line and finish is a boolean value for the loop
    do{
      SetConsoleTextAttribute(hConsole, 15);
      printf("%s",caption );
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
      switch (ch1){
        case 0xE0:
          ch2 = getch();
          switch(ch2){
            case 72: now--; break;//up
            case 80: now++; break;//down
          };break;
        case 13:finish++;break;//enter
        case 119:now--;break;//w
        case 115:now++;break;//s
        default:printf("key pressed: %d %c\n", ch1, ch2);//error case
      }
      if (now<0) now=0;
      if (now>MAX-1) now=MAX-1;
      system ("cls");
    }while(finish!=1);

  SetConsoleTextAttribute(hConsole, 15);
  return now;
}
