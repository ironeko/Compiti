// Programma Bibilioteca

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define NMAX 10   // Lunghezza massima vettori
#define N 20
int c=0;

struct Libro{
  char titolo [N];   //Titolo del libro
  char autore [N];   // Autore del libro (cognome)
  char casaEditrice [N];   // Casa editrice del libro (Mondadori, Feltrinelli...)
  char genere [N];   // genere del libro (horror, sci-fi...)
  int annoPubblicazione ;  // Anno della prima edizione del libro
  float prezzo;   // Prezzo in euro
}libri[NMAX];

void elimina();
//void caricalibri();
void stampa(int );
void cercaAutore();
void aggiungi();
void sistemare();


int main (){
  int a;
  char b[3];
  //caricalibri();
  do{
    printf ("************************");
    printf ("\n  BIBLIOTECA \n");
    printf ("************************");
    printf ("\n\nInserire una scelta:");
    printf ("\n 1 - Elimina Libro");//fatto
    printf ("\n 2 - Stampa catalogo");//fatto
    printf ("\n 3 - Aggiungi un libro");//fatto
    printf ("\n 4 - Ricerca libro per Autore");
    printf ("\n 5 - Ricerca libro per anno di pubblicazione");
    printf ("\n 6 - Classifica Autori chi ha pių libri pubblicati");
    printf ("\n 7 - Ordina per autore crescente");
    printf ("\n 8 - Ricerca libro per genere e anno di pubblicazione");
    printf ("\n 9 - Elimina Autore e tutti i suoi libri");
    printf ("\n 9 - Modifica Autore e se vuoi anche qualche suoo libro");
  	printf ("\n 10 - Creare un file BINARIO o .DAT ---- VEDI SLIDE date qualche settimana fa");
  	printf ("\n 0 - Esci e Salva le modifiche al file TXT");
    printf ("\ninserisci il numero della tua scelta:\t" );
    fgets(b,3,stdin);
    a=atoi(b);
    switch (a) {
      case 1:;break;
      case 2: for (int i=0;i<c;i++) {stampa(i);} ;break;
      case 3: aggiungi();break;
      case 4: cercaAutore();break;
      case 5:;break;
      case 6:;break;
      case 7:;break;
      case 8:;break;
      case 9:;break;
      case 10:;break;
      case 0:;break;
      default: printf("\aERRORE INSERIMENTO\n");system("pause");
    }
    system("pause");
    system("cls");
  }while(a!=0);
  return 0;
}

void stampa(int i){
  printf("%s %s %s %s %d %f\n",libri[i].titolo,libri[i].autore,libri[i].casaEditrice,libri[i].genere,libri[i].annoPubblicazione,libri[i].prezzo);
}

void elimina(int a){
  int b;
  for (int i=a;i<c;i++){
    b=i+1;
    strcpy(libri[i].titolo,libri[b].titolo);
    strcpy(libri[i].autore,libri[b].autore);
    strcpy(libri[i].casaEditrice,libri[b].casaEditrice);
    strcpy(libri[i].genere,libri[b].genere);
    libri[i].annoPubblicazione=libri[b].annoPubblicazione;
    libri[i].prezzo=libri[b].prezzo;
  }
}

void aggiungi(){
  char app[N];
  printf("dimmi il titolo:");
  fgets(libri[c].titolo,N,stdin);
  printf("dimmi l'autore:");
  fgets(libri[c].autore,N,stdin);
  printf("dimmi la casa editrice:");
  fgets(libri[c].casaEditrice,N,stdin);
  printf("dimmi il genere:");
  fgets(libri[c].genere,N,stdin);
  printf("dimmi l' anno di pubblicazione:");
  fgets(app,N,stdin);
  libri[c].annoPubblicazione=atof(app);
  printf("dimmi il codto:");
  fgets(app,N,stdin);
  libri[c].prezzo=atoi(app);
  c++;
  sistemare();
}

void sistemare(){
  int num=0;
  char app[N];
  for (int a=0;a<c;a++){
    //1
    for (int i=0;i<N;i++){
      if(libri[a].titolo[i]==' ' && num==0){
        num=0;
      }
      else{
        num=1;
        app[i]=libri[a].titolo[i];
      }
    }
    strcpy(libri[a].titolo,app);
    num=0;
    for (int i=N-1;i>=0;i--){
      if (num==0){
        if (libri[a].titolo[i]==' ' || libri[a].titolo[i]=='\n'){
          num=0;
        }
      }
      else{
        num=1;
        app[i]=libri[a].titolo[i];
      }
    }
    strcpy(libri[a].titolo,app);
    //2
    for (int i=0;i<N;i++){
      if(libri[a].autore[i]==' ' && num==0){
        num=0;
      }
      else{
        num=1;
        app[i]=libri[a].autore[i];
      }
    }
    strcpy(libri[a].autore,app);
    num=0;
    for (int i=N-1;i>=0;i--){
      if (num==0){
        if (libri[a].autore[i]==' ' || libri[a].autore[i]=='\n'){
          num=0;
        }
      }
      else{
        num=1;
        app[i]=libri[a].autore[i];
      }
    }
    strcpy(libri[a].autore,app);
    //3
    for (int i=0;i<N;i++){
      if(libri[a].casaEditrice[i]==' ' && num==0){
        num=0;
      }
      else{
        num=1;
        app[i]=libri[a].casaEditrice[i];
      }
    }
    strcpy(libri[a].casaEditrice,app);
    num=0;
    for (int i=N-1;i>=0;i--){
      if (num==0){
        if (libri[a].casaEditrice[i]==' ' || libri[a].casaEditrice[i]=='\n'){
          num=0;
        }
      }
      else{
        num=1;
        app[i]=libri[a].casaEditrice[i];
      }
    }
    strcpy(libri[a].casaEditrice,app);
    //4
    for (int i=0;i<N;i++){
      if(libri[a].genere[i]==' ' && num==0){
        num=0;
      }
      else{
        num=1;
        app[i]=libri[a].genere[i];
      }
    }
    strcpy(libri[a].genere,app);
    num=0;
    for (int i=N-1;i>=0;i--){
      if (num==0){
        if (libri[a].genere[i]==' ' || libri[a].genere[i]=='\n'){
          num=0;
        }
      }
      else{
        num=1;
        app[i]=libri[a].genere[i];
      }
    }
    strcpy(libri[a].genere,app);
  }
}

void cercaAutore(){
  char autore[N],app[N];
  int a=0,b=N-1;
  printf("inserisci nome autore:\t");
  fgets(autore,N,stdin);
  for (int i=0;i<N;i++){
    if (autore[i]=='\n'){
      autore[i]=' ';
    }
  }
  for (int i=N;i>=0;i--){
    printf("%d %d\n",a,autore[i] );
    if (autore[i]<=126 && autore[i] >=33){
      a=1;
      app[b]=autore[i];
      b--;
    }
  }
  a=0;b=0;
  for (int i=0;i<N;i++){
    if (autore[i]==' ' && a==0){
      a=0;
    }
    else {
      a=1;
      app[b]=autore[i];
      b++;
    }
  }
  strcpy(autore,app);
  printf("*************%s***************",autore);

  for (int i=0;i<c;i++){
    if (strcmp(autore,libri[i].autore)==0)
      printf("%s\n",libri[i].autore);
  }
}
































/*
void caricalibri(){
  FILE *file;
  file = fopen("catalogo.txt", "r");
  while (feof(file) == 0){
    fscanf(file,"%s %s %s %s %d %f",libri[c].titolo,libri[c].autore,libri[c].casaEditrice,libri[c].genere,&libri[c].annoPubblicazione,&libri[c].prezzo);
    c++;
  }
  fclose(file);
  for (int i=0;i<c;i++){
    for (int j=0;j<c;j++){
    }
  }
}
*/

//ciao
