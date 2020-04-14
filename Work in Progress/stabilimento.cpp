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

#define NS 100
#define LS 32
int n=0;

typedef struct {
  char nome[LS];
  int ombrelloni;
  float tariffa;
  int ristorante;
} stabilimento;

// cambiare nomi delle costanti e delle funzioni
void sistemare(char *stringa);
void minuscolo(char *stringa);
void pulito (char *stringa);
void aggiungiStabilimento(stabilimento[]);
void ricercaNome(stabilimento[]);
void cancellaStabilimento(stabilimento[]);
void stampaStabilimento(stabilimento);
void stampaStabilimenti(stabilimento[]);
void stampaPrezzoMinimo(stabilimento[]);
void stampaPrezzoMedio(stabilimento[]);
void carica(stabilimento[]);
void salva(stabilimento[]);

int main() {
  stabilimento dati[NS];
  int a;
  char b[4];
  carica(dati);
  do {
    printf("   Stabilimenti Balneari\n1) Stampa stabilimenti\n2) Ricerca stabilimento\n3) Stampa prezzo minimo\n4) Stampa prezzi medi \n5) Aggiungi stabilimento \n6) Cancella stabilimento \n0) Esci\n\nInput:");
    fgets(b,4,stdin);
    pulito(b);
    a=atoi(b);
    switch (a) {
      case 1: stampaStabilimenti(dati);break;
      case 2: ricercaNome(dati);break;
      case 3: stampaPrezzoMinimo(dati);break;
      case 4: stampaPrezzoMedio(dati);break;
      case 5: aggiungiStabilimento(dati);break;
      case 6: cancellaStabilimento(dati);break;
      case 0: break;
      default: printf("\aERRORE INSERIMENTO\n");
    }
    salva(dati);
    system("pause");
    system("cls");
  } while (a != 0);
  return 0;
}

void pulito(char *stringa){
  sistemare(stringa);
  minuscolo(stringa);
}

void sistemare(char *stringa){
  char app[LS];
  int b=0,a=0;
  for (int i=0;i<LS;i++){
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
  for (int i=0;i<LS;i++){
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
  for (int i=0;i<LS;i++){
    if (stringa[i]>=65 && stringa[i]<=90){
      stringa[i]=tolower(stringa[i]);
    }
  }
}

void aggiungiStabilimento(stabilimento dati[]) {
  if (n==NS) {
    printf("Spazio esaurito.\n");
    return;
  }
  char b[LS];
  printf("inserire nome stabilimento:\t" );
  fgets(b,LS,stdin);
  pulito(b);
  strcpy(dati[n].nome, b);
  printf("inserire numero di ombrelloni:\t");
  fgets(b,LS,stdin);
  pulito(b);
  dati[n].ombrelloni = atoi(b);
  printf("inserire la tariffa giornaliera:\t");
  fgets(b,LS,stdin);
  pulito(b);
  dati[n].tariffa = atof(b);
  printf("Servizio ristorante? \nrispondi con S o N:\t");
  fgets(b,LS,stdin);
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

void ricercaNome(stabilimento dati[]) {
  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }
  char b[LS];
  printf("inserire nome stabilimento:\t" );
  fgets(b,LS,stdin);
  pulito(b);
  printf("stabilimenti trovati:\n");
  for (int i=0; i<n; i++) {
    if (strstr(dati[i].nome, b) != NULL) {
      stampaStabilimento(dati[i]);
    }
  }
}

void cancellaStabilimento(stabilimento dati[]) {
  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }
  char b[LS];
  int i;

  printf("inserire nome stabilimento:\t" );
  fgets(b,LS,stdin);
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

void stampaStabilimento(stabilimento dati) {
  printf("%-*s%-12d%-12.2f", LS, dati.nome, dati.ombrelloni, dati.tariffa);
  if (dati.ristorante==1){
    printf("%-12s\n","Si");
  }
  else{
    printf("%-12s\n","No");
  }
}

void stampaStabilimenti(stabilimento dati[]) {
  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }
  int ris=0;
  char b[LS];

  printf("controllare l'esistenza del ristorante? (\"S\" o \"N\"):\t");
  fgets(b,LS,stdin);
  pulito(b);
  if (b[0]=='s'||b[0]=='S'){
    ris = 1;
  }
  printf("\n%-*s%-12s%-12s%-12s\n", LS, "Nome", "Ombrelloni", "Tariffa", "Ristorante");

  for (int i=0; i<n; i++) {
    if (ris==1) {
      if (dati[i].ristorante==1){
        stampaStabilimento(dati[i]);
      }
    }
    else{
      stampaStabilimento(dati[i]);
    }
  }
}

void stampaPrezzoMinimo(stabilimento dati[]) {
  float min = 0;
  int mI = 0;

  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }

  for (int i=0; i<n; i++) {
    if (min > dati[i].tariffa) {
      min = dati[i].tariffa;
      mI = i;
    }
  }
  printf("Stabilimento con la tariffa minore: \n");
  stampaStabilimento(dati[mI]);
}

void stampaPrezzoMedio(stabilimento dati[]) {
  float sRis=0,s=0;
  int contRis=0;

  if (n==0) {
    printf("Nessuno stabilimento inserito\n");
    return;
  }
  for (int i=0; i<n; i++) {
    s+=dati[i].tariffa;
    if (dati[i].ristorante == 1) {
      sRis+= dati[i].tariffa;
      contRis++;
    }
  }

  printf("costo medio: %.2f\ncosto medio senza ristorante: %.2f\nTariffa media con ristorante: %.2f\n",s/n,(s-sRis)/(n-contRis),sRis/contRis);
}

void carica(stabilimento dati[]) {
  int i=0;
  char b[4][LS];
  n=0;

  FILE *file = fopen("inventario.txt", "a");
  fclose(file);

  file =fopen("inventario.txt", "r");

  if (file == NULL) {
    printf("ERRORE file\n");
    return;
  }

  while (fgets(b[i % 4], LS, file) != NULL) {
    b [i%4][strlen (b[i % 4])-1]='\0';

    if (++i % 4 == 0) {
      strcpy(dati[n].nome, b[0]);
      dati[n].ombrelloni = atoi (b[1]);
      dati[n].tariffa = atof (b[2]);
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
    fprintf(file, "%f\n", dati[i].tariffa);
    fprintf(file, "%d\n", dati[i].ristorante);
  }

  fclose(file);
}
