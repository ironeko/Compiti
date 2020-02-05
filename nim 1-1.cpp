/*gioco di nim*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#define L 6
#define N 3

void stampa(int []);
void onevsone();
int singleplayer();
int ai(int []);
void decbin(int *[],int);

int main() {
	int a;
	do{
		printf("vuoi giocare da solo o con qualcuno?\n1 = da solo\n2 = con un amico\n");
		scanf("%d",&a);
		if (a==1){
			singleplayer();
			break;
		}
		else if (a==2){
			onevsone();
			break;
		}
		else
			printf("inserimento errato\n");
	}while(a!=1||a!=2);
	system("pause");
}

void stampa(int array []){
	for (int i=0;i<L;i++){
		printf("\n%d\t",i);
		for (int j=0;j<array[i];j++){
			printf("O");
		}
	}
	printf("\n\n\n");
}

void decbin(int *ret[],int dec){
	int m=0,bin[N];
	for (int i=0;i<N;++i){
		if (dec!=0){
			bin[i]=dec%2;
			dec/=2;
		}
		else
			bin[i]=2;
	}
	for (int i=N-1;i>=0;--i){
		if (bin[i]==0 || bin[i]==1){//porca troia, parte il riassuntone, allora il merda non traduce benme i numeri, così ho provato cion le matrici ma che non riesco a passare bene via funzione, per chui ho provato a mettere sto uno a caso ma non va bene ovviamente perchè il merda deve sapere in quale riga del matrice infilare il coso, il vettore dovrebbe essere 6x3 ma boh, tra l'altro non sto leggendo menbtre schrivo quindi ci sarò merda in sto commento ma va beh
			m++;
			ret[m][1]=bin[i];
		}
	}
}

void onevsone(){
	system("cls");
	int array[L],a,b,c=0,turno=0;
	printf("una volta a testa per un totale di %d volrte,\ndatetemi dei numeri per costruire il gioco\n",L);
	for(int i=0;i<L;i++){
		printf("%d: ",++i );
		i--;
		scanf("%d",&a);
		array[i]=a;
	}
	printf("in seguito vi chiedo di mettere il numero di riga e di seguito quanti punti avdranno levati:\nES: (0-6)\n vi ricordo che non si possono levare più elementi di quanti che ne siano in una riga\n");
	do{
		system("cls");
		if (turno==0){
			printf("turno del giocatore uno\n");
			turno=1;
		}
		else{
			printf("turno del giocatore due\n");
			turno=0;
		}
		stampa(array);
		scanf("%d-%d",&a,&b);
		if (array[a]>=b && b!=0 && array[a]!=0 && a<=L && a>=0){
			array[a]-=b;
			c=0;
		}
		else{
			printf("errore numero errato\n");
			c=1;
			if (turno==0)
				turno=1;
			else
				turno=0;
		}
		for (int i=0;i<L;i++){
			if (array[i]==0){
				c=1;
			}
			else{
				c=0;
				i+=L+1;
			}
		}
	}while(c==0);
	if (turno==1){
		printf("complimenti giocatore uno hai vinto\n");
	}
	else{
		printf("complimenti giocatore due hai vinto\n");
	}
}

int singleplayer(){
	int array[L],a,b,c=0,turno=0,vediamo=0; //ricorda che turno deve essere 0
	system("cls");
	printf("sto creando il tavolo di gioco...\n");
	srand (time(NULL));
	for (int i=0;i<L;i++){
		array[i] = rand() %5+1;
	}
	Sleep(900);
	system("cls");
  printf("ok ho fatto eccolo:\n");
	stampa(array);
	printf("ti chiedo di mettere il numero della riga e di seguito quanti punti avdranno levati:\nES: (0-6)\nti ricordo che non si possono levare piu elementi di quanti ce ne siano in una riga\n\n\n\n");



	do{
		system("cls");
		printf("\n********************%d\n",vediamo );
		vediamo++;
		stampa(array);


		if (turno==0){
			do{
				printf("e' il tuo turno:\n");
				scanf("%d-%d",&a,&b);
				if (array[a]>=b && b!=0 && array[a]!=0 && a<=L && a>=0){
					array[a]-=b;
					b=0;
				}
				else{
					printf("errore numero errato\n");
					b=1;
					}
			}while(b!=0);
			turno=1;
		}
		else{
			b=array[0];
			a=0;
			for (int i=0;i<L;i++){
				if (array[i]>b){
					b=array[i];
					a=i;
				}
			}

		b=ai(array);
		if (array[a]<b){
			printf("Fatal Error\n");
			return 0;
		}
		printf("io levo (%d-%d)\n",a,b);
		Sleep(1000);
		array[a]-=b;
		turno=0;
		}
		for (int i=0;i<L;i++){
			if (array[i]==0){
				c=1;
			}
			else{
				c=0;
				i+=L+1;
			}
		}
	}while(c==0);






	//quando sarà
	// possibili più difficooltà, facile: il bot leva i punti in maniera casuale media: una casuale e una ponderata difficile: tutte ponderate
	if (turno==1){
		printf("complimenti giocatore uno hai vinto\n");
	}
	else{
		printf("complimenti giocatore due hai vinto\n");
	}
	return 0;
}

int ai(int ar []){
	int bin[N][L],sott=0;
	for (int i=0;i<L;i++){
		decbin(&bin,ar);
	}/*
	for(int i=0;i<N;i++){
		printf("bin0=%d\nbin1=%d\nbin2=%d\nbin3=%d\nbin4=%d\nbin5=%d\n",bin0[i],bin1[i],bin2[i],bin3[i],bin4[i],bin5[i]);
		work[i]=bin0[i]+bin1[i]+bin2[i]+bin3[i]+bin4[i]+bin5[i];
		printf("------------>work[%d]=%d\n",i,work[i] );
		while (work[i]>=2)
			work[i]-=2;
	}

	for (int i=0;i<N;i++)
		printf("%d",work[i] );
	system("pause");

	for (int i=0;i<N;i++){
		if(work[i]==1){
			sott+=pow(2,i);
		}
	}*/
	return sott;
}











































//i need space
