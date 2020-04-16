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

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <strings.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "../Librerie/menu.c"

#define NMAX 100
#define N 20
int n=0;

typedef struct {
  char nome[N];
  int ombrelloni;
  float costo;
  int ristorante;
} stabilimento;

void sistemare(char *stringa);
void minuscolo(char *stringa);
void pulito (char *stringa);
void aggiungi(stabilimento[]);
void ricerca(stabilimento[]);
void cancella(stabilimento[]);
void printone(stabilimento);
void printall(stabilimento[]);
void minimo(stabilimento[]);
void medio(stabilimento[]);
void carica(stabilimento[]);
void salva(stabilimento[]);

int main() {
  stabilimento dati[NMAX];
  carica(dati);
  char *pass[N]={'\0'};
  pass[0]="1) Stampa stabilimenti";
  pass[1]="2) Ricerca stabilimento";
  pass[2]="3) Stampa prezzo minimo";
  pass[3]="4) Stampa prezzi medi";
  pass[4]="5) Aggiungi stabilimento";
  pass[5]="6) Cancella stabilimento";
  pass[6]="ESCI";
  int now=0;
  do{
    now=create_menu("********Stabilimenti Balneari**********\n\n*/*/*/Usa le frecce direzionali per muoverti nel menu'*/*/*/\n\n",7,pass);
    switch (now) {
      case 0: printall(dati);break;
      case 1: ricerca(dati);break;
      case 2: minimo(dati);break;
      case 3: medio(dati);break;
      case 4: aggiungi(dati);break;
      case 5: cancella(dati);break;
      case 6: break;
      default: printf("\aERRORE INSERIMENTO\n");
    }
    salva(dati);
    system("pause");
    system("cls");
  } while (now != 6);
}

void pulito(char *stringa){
  sistemare(stringa);
  minuscolo(stringa);
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

void aggiungi(stabilimento dati[]) {
  if (n==NMAX) {
    printf("Spazio esaurito.\n");
    return;
  }
  char b[N];
  printf("inserire nome stabilimento:\t" );
  fgets(b,N,stdin);
  pulito(b);
  strcpy(dati[n].nome, b);
  printf("inserire numero di ombrelloni:\t");
  fgets(b,N,stdin);
  pulito(b);
  dati[n].ombrelloni = atoi(b);
  printf("inserire la costo giornaliera:\t");
  fgets(b,N,stdin);
  pulito(b);
  dati[n].costo = atof(b);
  printf("Servizio ristorante? \nrispondi con S o N:\t");
  fgets(b,N,stdin);
  pulito(b);
  if (b[0] == 's' || b[0] == 'S'){
    dati[n].ristorante = 1;
  }
  else
    dati[n].ristorante = 0;
  n++;
  salva(dati);
  printf("Stabilimento aggiunto.\n");
}

void ricerca(stabilimento dati[]) {
  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }
  char b[N];
  printf("inserire nome stabilimento:\t" );
  fgets(b,N,stdin);
  pulito(b);
  printf("stabilimenti trovati:\n");
  for (int i=0; i<n; i++) {
    if (strstr(dati[i].nome, b) != NULL) {
      printone(dati[i]);
    }
  }
}

void cancella(stabilimento dati[]) {
  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }
  char b[N];
  int i;

  printf("inserire nome stabilimento:\t" );
  fgets(b,N,stdin);
  pulito(b);
  for (i=0; i<n; i++) {
    if (strcasecmp(dati[i].nome, b)==0){
      break;
    }
  }
  if (i==n) {
    printf("Nessun risultato.\n");
  }
  else {
    for (int j=i; j<n-1; j++) {
      dati[j] = dati[j+1];
    }
    n--;
    salva(dati);
    printf("Stabilimento cancellato.\n");
  }
}

void printone(stabilimento dati) {
  printf("%-*s%-12d%-12.2f", N, dati.nome, dati.ombrelloni, dati.costo);
  if (dati.ristorante==1){
    printf("%-12s\n","Si");
  }
  else{
    printf("%-12s\n","No");
  }
}

void printall(stabilimento dati[]) {
  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }
  int ris=0;
  char b[N];

  printf("controllare l'esistenza del ristorante? (\"Si\" o \"No\"):\t");
  fgets(b,N,stdin);
  pulito(b);
  if (b[0]=='s'||b[0]=='S'){
    ris = 1;
  }
  printf("\n%-*s%-12s%-12s%-12s\n", N, "Nome", "Ombrelloni", "costo", "Ristorante");

  for (int i=0; i<n; i++) {
    if (ris==1) {
      if (dati[i].ristorante==1){
        printone(dati[i]);
      }
    }
    else{
      printone(dati[i]);
    }
  }
}

void minimo(stabilimento dati[]) {
  float min = 0;
  int mI = 0;

  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }

  for (int i=0; i<n; i++) {
    if (min > dati[i].costo) {
      min = dati[i].costo;
      mI = i;
    }
  }
  printf("Stabilimento con la costo minore: \n");
  printone(dati[mI]);
}

void medio(stabilimento dati[]) {
  float sRis=0,s=0;
  int contRis=0;

  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }
  for (int i=0; i<n; i++) {
    s+=dati[i].costo;
    if (dati[i].ristorante == 1) {
      sRis+= dati[i].costo;
      contRis++;
    }
  }

  printf("costo medio: %.2f\ncosto medio senza ristorante: %.2f\ncosto medio con ristorante: %.2f\n",s/n,(s-sRis)/(n-contRis),sRis/contRis);
}

void carica(stabilimento dati[]) {
  int i=0;
  char b[4][N];
  n=0;

  FILE *file = fopen("inventario.txt", "a");
  fclose(file);

  file =fopen("inventario.txt", "r");

  if (file == NULL) {
    printf("ERRORE file\n");
    return;
  }

  while (fgets(b[i % 4], N, file) != NULL) {
    b [i%4][strlen (b[i % 4])-1]='\0';

    if (++i % 4 == 0) {
      strcpy(dati[n].nome, b[0]);
      dati[n].ombrelloni = atoi (b[1]);
      dati[n].costo = atof (b[2]);
      dati[n].ristorante = atoi (b[3]);
      n++;
    }
  }
  if (i / 4 != n) {
    printf("Errore in lettura. Dei dati potrebbero essero corrotti.\n");
  }
  fclose(file);
}

void salva(stabilimento dati[]) {
  FILE *file =fopen("inventario.txt", "w");

  if (file == NULL) {
    printf("ERRORE file\n");
    return;
  }

  for (int i=0; i<n; i++) {
    fprintf(file, "%s\n", dati[i].nome);
    fprintf(file, "%d\n", dati[i].ombrelloni);
    fprintf(file, "%f\n", dati[i].costo);
    fprintf(file, "%d\n", dati[i].ristorante);
  }

  fclose(file);
}
