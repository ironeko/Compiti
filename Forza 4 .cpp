/*Forza 4:
	0 | 1 | 2 | 3 | 4 | 5 | 6 |
	gioco 1,
	0 | 1 | 2 | 3 | 4 | 5 | 6 |
	  | X |   |   |   |   |   |
	gioco 3
	0 | 1 | 2 | 3 | 4 | 5 | 6 |
	  | X |   | O |   |   |   |
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
const int R=6,C=7;

void stampa (int [][C]);
int vincere(int [][C]);

int main(){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int table[R][C]={0};
	int in,insert[2][C]={0},it=1,b,posizione=0,v=0;
	bool turno=0;

  do{
    //input
  	do{
      system("cls");
      stampa(table);
  		if (turno==0){
        SetConsoleTextAttribute(hConsole, 12);
  			printf("X ");
        SetConsoleTextAttribute(hConsole, 7);
      }
  		else{
        SetConsoleTextAttribute(hConsole, 9);
  			printf("O ");
        SetConsoleTextAttribute(hConsole, 7);
      }
  		printf("inserisci posizione:\t");
  		scanf("%d",&in);
      if (in<=-1 || in>=C){
        it=0;
        printf("\n***\nnumero inserito in modo errato\n***\n");
        system("PAUSE");
      }
      else{
    		for (int i=0;i<C;i++){
    			if (insert[0][i]==in && insert [1][i]==R){
    				it=0;
    				printf("\n***\nnumero inserito troppe volte\n***\n");
            system("PAUSE");
            i+=C+1;
    			}
    			else
    				it=1;
    		}
      }
  	}while(it==0);
    //salvbataggio input
  	for (b=0;b<C;b++){
  		if (insert[0][b]==in){
    		insert[1][b]++;
        it=0;
        b+=C+1;
  		}
  	}

  	if (it!=0) {
  		posizione++;
  		insert [0][posizione]=in;
  		insert [1][posizione]++;
  	}

    // inserimento tabella con animazione (si consiglia di modificare il tempo dello Sleep [ms] per una migliore esperienza)
    if (turno==0){
      for (int i=0;i<R;i++){
        if (table[i][in]==0){
          table[i][in]++;
          system("cls");
          stampa(table);
          Sleep(10);
          table[i][in]--;
        }
        if (table[i][in]!=0){
          table[i-1][in]++;
          i+=R+1;
        }
        else if (i==R-1){
          table[i][in]++;
          i+=R+1;
        }
      }
    }
    else if (turno==1){
      for (int i=0;i<R;i++){
        if (table[i][in]==0){
          table[i][in]--;
          system("cls");
          stampa(table);
          Sleep(10);
          table[i][in]++;
        }
        if (table[i][in]!=0){
          table[i-1][in]--;
          i+=R+1;
        }
        else if (i==R-1){
          table[i][in]--;
          i+=R+1;
        }
      }
    }
    //vincere
    v=vincere(table);
    //cambio turno
    if (v==0){
      if (turno==0){
        turno++;
      }
      else {
        turno=false;
      }
    }

  }while (v==0);
  system("cls");
  stampa(table);
  if (turno==0){
    SetConsoleTextAttribute(hConsole, 12);
    printf("X Vince\n");
    SetConsoleTextAttribute(hConsole, 7);
  }
  else{
    SetConsoleTextAttribute(hConsole, 9);
    printf("O Vince\n");
    SetConsoleTextAttribute(hConsole, 7);
  }
	system("PAUSE");
	return 0;
}

void stampa (int tb[][C]){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("| 0 | 1 | 2 | 3 | 4 | 5 | 6 |\n");
	printf(" ---------------------------\n");
	for (int i=0;i<R;i++){
		for (int j=0;j<C;j++){
			if (tb[i][j]==0){
				printf("|   ");
			}
			else if (tb[i][j]==1){
        printf("| " );
        SetConsoleTextAttribute(hConsole, 12);
				printf("X ");
        SetConsoleTextAttribute(hConsole, 7);
			}
			else if (tb[i][j]==-1){
        printf("| " );
        SetConsoleTextAttribute(hConsole, 9);
				printf("O ");
        SetConsoleTextAttribute(hConsole, 7);
			}
		}
		printf("|\n");
		printf(" ---------------------------\n");
	}
}

int vincere(int tb[][C]){
  // righe
  for (int i=0;i<R;i++){
    for (int j=0;j<C;j++){
      if (tb[i][j]==1 && tb[i][j+1]==1 && tb[i][j+2]==1 && tb[i][j+3]==1 && (j+3)<C){
        return 1;
      }
      else if (tb[i][j]==-1 && tb[i][j+1]==-1 && tb[i][j+2]==-1 && tb[i][j+3]==-1 && (j+3)<C){
        return 1;
      }
    }
  }
  //colonne
  for (int i=0;i<C;i++){
    for (int j=0;j<R;j++){
      if (tb[i][j]==1 && tb[i+1][j]==1 && tb[i+2][j]==1 && tb[i+3][j]==1 && (i+3)<R){
        return 1;
      }
      else if (tb[i][j]==-1 && tb[i+1][j]==-1 && tb[i+2][j]==-1 && tb[i+3][j]==-1 && (i+3)<R){
        return 1;
      }
    }
  }
  //diagonale 1 no
  for (int i=0;i<R;i++){
    for (int j=0;j<C;j++){
      if (tb[i][j]==1 && tb[i+1][j+1]==1 && tb[i+2][j+2]==1 && tb[i+3][j+3]==1 && (j+3)<C && (i+3)<R){
        return 1;
      }
      else if (tb[i][j]==-1 && tb[i+1][j+1]==-1 && tb[i+2][j+2]==-1 && tb[i+3][j+3]==-1 && (i+3)<C && (j+3)<R){
        return 1;
      }
    }
  }
  //diagonale 2
  for (int i=0;i<R;i++){
    for (int j=0;j<C;j++){
      if (tb[i][j]==1 && tb[i+1][j-1]==1 && tb[i+2][j-2]==1 && tb[i+3][j-3]==1 && (i+3)<R && (j-3)>=0){
        return 1;
      }
      else if (tb[i][j]==-1 && tb[i+1][j-1]==-1 && tb[i+2][j-2]==-1 && tb[i+3][j-3]==-1 && (i+3)<R && (j-3)>=0){
        return 1;
      }
    }
  }
  return 0;
}
