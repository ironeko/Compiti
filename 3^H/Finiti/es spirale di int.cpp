/*Esercizio_2
Realizzare un programma che permetta di riempire una matrice Quadrata NxN con N pari dalla cornice partendo da 1 fino a N/2
ad esempio N=6
1	1	1	1	1	1
1	2	2	2	2	1
1	2	3	3	2	1
1	2	3	3	2	1
1	2	2	2	2	1
1	1	1	1	1	1*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
int N;



int main (){
	printf("dammi N, la dimensione della matrice:\t" );
	scanf("%d",&N );
	int mat [N][N]{0},a=N,b=0,c=N-1;
	for (int k=0;k<N;k++){
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				if (i==b || j==b || i==c || j==c){
					mat [i][j]=a;
				}
			}
		}
		b++;
		a--;
		c--;
	}
	int f;
	HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	for (int i=0;i<N;i++){
    printf("%d   ",f );
    f++;
		for (int j=0;j<N;j++){
			a= rand()%15;
			if (a!=0){
      SetConsoleTextAttribute(hConsole, a);
			printf("  %d ",mat [i][j] );
			}
			else
				j--;
		}
		SetConsoleTextAttribute(hConsole, 7);
		printf("\n");
		printf("-----------------\n");
	}
	system ("pause");
}
