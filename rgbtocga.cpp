#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
/* ricontrollare i colori, possibili light a 255-0
Full CGA 16-color palette
0	black #000000	RGB=0 0 0-----------3*
1	blue #0000AA	RGB=0 0 170-----------5*
2	green #00AA00	RGB=0 170 0-----------5*
3	cyan #00AAAA	rgb(0, 170, 170)-----------7*
4	red #AA0000	RGB=170 0 0-----------5*
5	magenta #AA00AA	RGB=170 0 170-----------7*
6	brown #AA5500	RGB=170 85 0-----------6*
7	light gray #AAAAAA	RGB=170 170 170-----------9*
8	dark gray #555555 RGB=85 85 85-----------6*
9	light blue #5555FF RGB=85 85 255-----------8*
10	light green #55FF55 rgb(85, 255, 85)-----------8*
11	light cyan #55FFFF rgb(85, 255, 255)-----------10*
12  light red #FF5555 rgb(255, 85, 85)-----------8*
13	light magenta #FF55FF rgb(255, 85, 255)-----------10*
14	yellow #FFFF55 rgb(255, 255, 85)-----------10*
15	white #FFFFFF rgb(255, 255, 255)-----------12*
*/

int rgb(int r,int g,int b);
int strange(int r,int g,int b){
  if (r<128 && r>0)
    r--;
  else if (r<255)
    r++;
  if (g<128 && g>0)
    g--;
  else if (g<255)
    g++;
  if (b<128 && b>0)
    b--;
  else if (b<255)
    b++;
  printf("%d %d %d\n",r,g,b );
  return (rgb(r,g,b));

}

int five(int r,int g,int b){
  if (r==0){
    if (g==0){
      return 1;
    }
    else if (b==0){
      return 2;
    }
  }
  else if (g+b==0){
    return 4;
  }
  return(strange (r,g,b));
}
int six(int r,int g,int b){
  if (r==170 && g==85 && b==0){
    return 6;
  }
  else if (r==85 && g==85 && b==85){
    return 8;
  }
  return(strange (r,g,b));
}
int seven(int r,int g,int b){
  if (r==0 && g==170 && b==170){
    return 3;
  }
  else if (r==170 && g==0 && b==170){
    return 5;
  }
  return(strange (r,g,b));
}
int eight(int r,int g,int b){
  if (r==85){
    if (g==85){
      return 9;
    }
    else if (b==85){
      return 10;
    }
  }
  else if (g==85 && b==85){
    return 12;
  }
  return(strange (r,g,b));
}
int nine(int r,int g,int b){
  if (r==170 && g==170 && b==170)
    return 7;
  return(strange (r,g,b));
}
int ten(int r,int g,int b){
  if (r==255){
    if (g==255){
      return 14;
    }
    else if (b==255){
      return 13;
    }
  }
  else if (g+b==510){
    return 11;
  }
  return(strange (r,g,b));
}


int rgb(int r,int g,int b){

  // 0-1 85-2 170-3 255-4
  //42 127 215
  if (r<=255 && r>=0){
    int a,d,c;
    // r
    if (r<42)
      a=1;
    else if (r<127)
      a=2;
    else if (r<215)
      a=3;
    else
      a=4;

    // g
    if (g<42)
      d=1;
    else if (g<127)
      d=2;
    else if (g<215)
      d=3;
    else
      d=4;

    // b
    if (b<42)
      c=1;
    else if (b<127)
      c=2;
    else if (b<215)
      c=3;
    else
      c=4;
    printf("swich %d\n",a+d+c );
    switch (a+d+c){
      case 3:return 0;break;
      case 5: return(five(r,g,b));
      case 6: return(six(r,g,b));
      case 7: return(seven(r,g,b));
      case 8: return(eight (r,g,b));
      case 9: return(nine(r,g,b));
      case 10: return(ten(r,g,b));
      case 12:return 15;
      default:printf("sos\n" ); return(strange (r,g,b));
    }
  }
  return 0;
}

int main (){
  int a=0;
  srand((unsigned)time(NULL));
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 4);
  printf("ciao\n");
  int r=rand ()%255,g=rand ()%255,b=rand ()%255;
  r=255;g=85;b=85;
  printf("%d %d %d\n",r,g,b);
  a=rgb(r,g,b);
  printf ("%d",a);
  SetConsoleTextAttribute(hConsole, a);
  printf("ciao\n");
}


















































//i need space
