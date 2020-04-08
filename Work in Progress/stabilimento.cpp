/*Stabilimenti Balneari

Definire una tabella adatta a contenere, per N stabilimenti balneari, il nome, il numero di ombrelloni disponibili, la tariffa giornaliera e se vi è il servizio di ristorazione.
Una volta caricati i dati da un file di testo chiamato stabilimenti.txt il programma dovrà svolgere le seguenti funzioni :

1.	Stampa dati stabilimenti
2.	Dato il nome di uno stabilimento, visualizzare i suoi dati.
Effettuare una ricerca approssimata, pulizia della stringa in ingresso
3.	Visualizzare il nome dello stabilimento più a buon prezzo
4.	Visualizzare il prezzo medio degli stabilimenti con e senza servizio di ristorazione
5.	Costruire e visualizzare una tabella STABRIST contenente nome e prezzo degli  stabilimenti che hanno un servizio di ristorazione ordinati per prezzo
6.	Aggiungere un nuovo stabilimento
Effettuare il controllo Dell'input e gestire l'input di stringhe con spazi. Il codice dello stabilimento deve essere dato in automatico dal programma
7.	Cancellare un stabilimento
Prevedere una procedura per sostituire la riga eliminata

Il programma dovrà presentare un menu di scelta e prima di terminare l'esecuzione salvare tutte le modifiche.

char str[20]
fgets(str,20,fp)
fgets(str,20,stdin)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define NMAX 100   // Lunghezza massima vettori
#define N 20
int c=0;

void sistemare(char *stringa);
void minuscolo(char *stringa);
void salva(char [N][NMAX],int [N],float [N],char [N]);
void carica(char [N][NMAX],int [N],float [N],char [N]);

int main (){
  int a,ombrelloni[N];
  char b[4],nome[N][NMAX],ristorante[N];
  float costo[N];
  carica(nome,ombrelloni,costo,ristorante);
  do{
    printf("inserisci numero cose\n" );
    fgets(b,4,stdin);
    a=atoi(b);
    printf("\n\n");
    switch (a) {
      case 1: printf("boh\n" );break;
      case 0: salva(nome,ombrelloni,costo,ristorante);break;
      default: printf("\aERRORE INSERIMENTO\n");system("pause");
    }
    system("pause");
    system("cls");
  }while(a!=0);
  return 0;
}

void sistemare(char *stringa){
  char app[N];
  int b=0,a=0;
  for (int i=0;i<N;i++){
    if (stringa[i]==' ' && a==0){
      a=0;
    }
    else {
      a=1;
      app[b]=stringa[i];
      b++;
    }
  }
  strcpy(stringa,app);
  for (int i=0;i<N;i++){
    app[i]='\0';
  }
  b=strlen(stringa);
  a=0;
  for (int i=strlen(stringa);i>=0;i--){
    if (stringa[i]<=126 && stringa[i]>=33 && a==0){
      a=1;
      app[b]=stringa[i];
    }
    else if (a==1){
      app[b]=stringa[i];
    }
    b--;
  }
  strcpy(stringa,app);
}

void minuscolo(char *stringa){
  for (int i=0;i<N;i++){
    if (stringa[i]>=65 && stringa[i]<=90){
      stringa[i]=tolower(stringa[i]);
    }
  }
}

void carica(char nome[N][NMAX],int ombrelloni[N],float costo[N],char ristorante[N]){
  FILE *file;
  file = fopen("spiaggia.txt", "r");
  if (file!=NULL){
    while (feof(file) == 0 && c==N){
      fscanf(file,"%100s %d %f %c",nome[c],&ombrelloni[c],&costo[c],&ristorante[c]);
      c++;
    }
  }
  else{
    printf("ERRORE\n" );
  }
  fclose(file);
}

void salva(char nome[N][NMAX],int ombrelloni[N],float costo[N],char ristorante[N]){
  FILE *file;
  file = fopen("inventario.txt", "w");
  if (file!=NULL){
    for (int i=0;i<c;i++){
      fprintf(file,"%100s %d %f %c",nome[i],ombrelloni[i],costo[i],ristorante[i]);
    }
  }
  else{
    printf("ERRORE\n" );
  }
  fclose(file);
}








































//space
