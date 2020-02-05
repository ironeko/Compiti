/* bancomat */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

int d=5,v=5,c=5; //variabili globali soldi d=10 v=20 c=50

void prelievo();
void inserimento();

int main() {
	int a;
	do{
		system("cls");
		printf("1)prelevare\n2)insernimento\n3)esci\n\n");
		scanf("%d",&a );
		switch (a) {
			case 1:prelievo();
			case 2:if (a==2)inserimento();
			case 3:break;
			default:printf("ERRORE\n");
		}
	}while(a!=3);
	printf("grazie e arrivederci\n");
	system("pause");
}

void prelievo(){
	system("cls");
	int soldi,i=0,d1=0,v1=0,c1=0;
	char a[2],b[2]={'s','i'};
	printf("quanto vuoi prelevare (meno di 250 e niente unita'):\t");
	scanf("%d",&soldi);
	if (soldi>250 || soldi%10!=0){//se viene richiesto più di 250 errore o unità
		printf("ERRORE\n");
		system("pause");
		prelievo(); // richiamo la funzione per poter farriprovare l'utente
	}
	else{
	while (i<=250){//finchè i= soldi erogati è minore di 250
			if (d!=0){//posso dartene da 10?
				d--;
				d1++;
				i+=10;
			}
			else if(v!=0 && d==0){//posso dartene da 20?
				v--;
				v1++;//aggungo 1 da venti al slaldo momentaneo
				i-=30;//e levo 30 per poi riaggiungere quelli da 10
				d=d1;
				d1=0;
			}
			else if(c!=0 && v==0){//posso dartene da 50?
				c--;
				c1++;
				i-=50;//simile a su
				v=v1;
				v1=0;
			}
			if (i==soldi){
				printf("->10=%d  20=%d  50=%d\n",d1,v1,c1);
				printf("vuoi prelevare?\n");//controllo se la combimnazione va bene all'untente
				fflush(stdin);
				gets(a);
				if (strcmp(a,b)==0){
					d=-d1;
					v=-v1;
					c=-c1;
					i=251;
				}
			}
		}
	}
}

void inserimento(){// spiegare questo mi sembra inutile
	system("cls");
	int a;
	printf("quante banconote da 10 vuoi inserire?\n");
	scanf("%d",&a);
	d+=a;
	a=0;
	printf("quante banconote da 20 vuoi inserire?\n");
	scanf("%d",&a);
	v+=a;
	a=0;
	printf("quante banconote da 50 vuoi inserire?\n");
	scanf("%d",&a);
	c+=a;
	a=0;
}
