#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
const int R=5,C=3; // R=quota prfondità mine C=mare daproteggere
int mare[R][C];

void setrandom(int *,int *,int *,int *);
void stampa ();

int main(){
  int t=0,a=0,b=0,v=0,x1,y1,x2,y2;
  setrandom(&x1,&y1,&x2,&y2);
  do{
    system("cls");
    printf("inserisci le coordinate in cui vuoi provare, ti rimangono %d tentativi\nx y\n",10-t );
    stampa();
    scanf("%d %d",&b,&a );
    if (a<R && b<C){
      switch (mare [a][b]){
        case 0:mare [a][b]=2;printf("Acqua\n");break;
        case 1:mare [a][b]=3;printf("sommergibile colpito e affondato\n");v++;break;
        case 2:printf("acqua hai già provato in questa posizione\n");break;
        case 3:printf("sommergibile gia' colpito e affondato\n");break;
        default: printf("Errore, numero errato\n");
      }
      t++;
    }
    else
      printf("numero errato\n" );
     system ("pause");
  }while(v!=2 && t!=10);
  if (v==2)
    printf("********************\nHai vinto\n****************************\n");
  else{
    printf("********************\nHai perso\n****************************\n");
    printf("x1=%d y1=%d x2=%d y2=%d\n",x1,y1,x2,y2);
  }
}

void setrandom(int *x1,int *y1,int *x2,int *y2){
  srand((unsigned)time(NULL));

  *x1=rand()%3;
  *y1=rand()%5;
  do{
    *x2=rand()%3;
    *y2=rand()%5;
  }while(*x1!=*x2 && *y1!=*y2);
  for (int i=0;i<R;i++){
    for (int j=0;j<C;j++){
      mare [i][j]=0;
    }
  }
  mare[*y1][*x1]=1;
  mare[*y2][*x2]=1;
}

void stampa (){
  int f;
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("    | 0 | 1 | 2 |\n");
	printf("-----------------\n");
	for (int i=0;i<R;i++){
    printf("%d   ",f );
    f++;
		for (int j=0;j<C;j++){
			if (mare[i][j]==0 || mare [i][j]==1){
				printf("|   ");
			}
			else if (mare[i][j]==3){
        printf("| " );
        SetConsoleTextAttribute(hConsole, 12);
				printf("C ");
        SetConsoleTextAttribute(hConsole, 7);
			}
			else if (mare[i][j]==2){
        printf("| " );
        SetConsoleTextAttribute(hConsole, 9);
				printf("A ");
        SetConsoleTextAttribute(hConsole, 7);
			}
		}
		printf("|\n");
		printf("-----------------\n");
	}
}
