/*
  * Vettori paralleli e Stringhe
  * Gestione squadre di calcio
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library1.c"
#define MaxN 100


void inizializzaSquadre(char[][30], char[], int[], int );
void visualizzaSerie(char[][30], char[], char ,int);
void informazioniSquadra(char[][30], char[], int[], int );
void campione(char[][30], char[], int[], char ,int );
void visualizzaClassifica (char V[][30], char [], int [], char, int);
void ordina (int[], int );
void ordinaNome (char[][30], char[], int[], char, int);


int main(){

  char nomeS[MaxN][30];	//vettore di stringhe con i momi delle squadre
  char serie[MaxN];	 	//cettore di char che contiene la serie dove gioca la squadra
  int punti[MaxN];		//vettore di interi col punteggio della sqradra
  char s;
  int N,k;
  printf ("\nInserisci il numero totale di squadre serie A + serie B:\n");
  //scanf ("%d",&N);
  N=6; // per velocizzare il tuttecose
  inizializzaSquadre(nomeS,serie,punti,N);

  do{
	  printf ("\nInserisci 1 per  elenco squadre serie A:\n");
	  printf ("Inserisci 2 per  elenco squadre serie B:\n");
	  printf ("Inserisci 3 per informazioni squadra :\n");
	  printf ("Inserisci 4 per classifica squadre serie richiesta:\n");
	  printf ("Inserisci 5 per ricerca squadra campione della serie richiesta:\n");
	  printf ("Inserisci 6 per ordinare le squadre della serie richiesta in ordine alfabetico:\n");
	  printf ("Inserisci 0 per terminare:\n");
	  printf ("Inserisci la tua scelta :\n");
	  scanf ("%d",&k);
	  switch (k){
		  case 1:
        visualizzaSerie(nomeS, serie,'A',N );
	    	break;
	    case 2:
        visualizzaSerie(nomeS, serie,'B',N );
  	    break;
	    case 3:
        informazioniSquadra(nomeS, serie ,punti,N);
	    	break;
	    case 4:
		     printf ("Inserisci la serie che vuoi visualizzare :\n");
         fflush(stdin);
			   scanf("%c",&s);
         fflush(stdin);
			   visualizzaClassifica (nomeS, serie ,punti,s,N);
         break;
	    case 5:
	    	printf ("Inserisci la serie che vuoi visualizzare :\n");
        scanf("%c",&s);
        campione(nomeS, serie ,punti,s,N);
	    	break;
	    case 6:
        printf ("Inserisci la serie che vuoi visualizzare :\n");
			  scanf("%c",&s);
			  ordinaNome(nomeS,serie,punti,s,N);
	      break;
	    case 0:
	    	break;
	    default :
	    	printf ("Scelte consentite 1,2,3,4,6 o 0 :\n");
	}

	} while(k!=0 );

  printf("grazie e arrivederci\n");
  return (0);
 // system("PAUSE");
}


void visualizzaSerie (char V[6][30], char S[], char cat, int n){
    for (int i=0;i<n;i++){
      if (S[i]==cat){
        printf("- %s\n",V[i] );
      }
    }
	//visualizza le squadre della serie  specificata dal parametro cat
}

void visualizzaClassifica (char V[][30], char S[],int P[], char cat , int n){
  char C[n][30],cc[30];
  int a[n]{0},b=0;

  for (int i=0;i<n;i++){
    if (S[i]==cat){
      strcpy(C[i],V[i]);
      a[i]=P[i];
      b++;
    }
  }

  int i, j, app;

 for (i = 1; i < n; i++){
    app = a[i];
    strcpy(cc,C[i]);

    for (j = i - 1; (j >= 0) && (a[j] > app); j--){
       a[j+1] = a[j];
       strcpy(C[j+1],C[j]);
     }

    a[j + 1] = app;
    strcpy(C[j+1],cc);
  }

  for (int x=n-1;x>=b;x--)
    printf("squadra %s  punti %d\n",C[x],a[x] );
	//Crea un nuovo vettore che conterr� solo le squadre della  serie richiesta, lo ordina e visualizza la classifica.
}

void ordina (int a[], int dim){
}

void ordinaNome (char V [][30], char serie[], int punti[],char s, int n){
	// effettua l'ordinamento delle squadre della serie S in ordine alfabetico
}

void informazioniSquadra(char V[][30], char S[], int P[], int n ){
  char nome[30];
  int c=0;
  printf("dimmi la squadra da ricercare:\t");
  fflush(stdin);
  gets(nome);
  for (int i=0;i<n;i++){
    if (strcmp(V[i],nome)==0){
      printf("Serie %c punti %d\n",S[i],P[i] );
      c++;
    }
  }
  if (c==0)
    printf("squadra non trovata\n");
	// dato il nome di una squadra, se compare tra quelle inserite nell'elenco ne stampa
	// la serie e i punti, altrimenti da un messaggio di errore
}

void campione (char V[][30], char S[], int P[], char s, int n ){
	// ricerca tra le squadre della serie richiesta quella con punteggio massimo
	// senza creare nessun vettore di appoggio (SENZA NESSUNA COPIA, ne dei nomi delle squadre ne dei punteggi)
}

void inizializzaSquadre (char V[6][30], char S[], int P[],int N){
	// inizializza i vettori nomesquadre, serie e punti e  N


	strcpy(V[0],"Fiore");
	strcpy(V[1],"Juve");
	strcpy(V[2],"Napule");
	strcpy(V[3],"Bari");
	strcpy(V[4],"Pescia");
	strcpy(V[5],"Livorno");

	S[0]='A';
	S[1]='B';
	S[2]='A';
	S[3]='A';
	S[4]='B';
	S[5]='B';

	P[0]=12;
	P[1]=2;
	P[2]=3;
	P[3]=4;
	P[4]=31;
	P[5]=3;
}
