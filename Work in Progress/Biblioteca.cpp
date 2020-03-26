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

void elimina(int );
void caricalibri();
void stampa(int );
void cercaAutore();
void aggiungi();
void sistemare(char *stringa);
void anno();
int numeroLibriAutore(int a);//dargli il numero del vettore dello struct
void piuLibri();
void sistem();
int altro();
void salvalibri();
void autorescresce();
void otto();

int main (){
  int a;
  char b[3];
  caricalibri();
  do{
    printf ("************************");
    printf ("\n  BIBLIOTECA \n");
    printf ("************************");
    printf ("\n\nInserire una scelta:");
    printf ("\n 1 - Elimina Libro");//fatto
    printf ("\n 2 - Stampa catalogo");//fatto
    printf ("\n 3 - Aggiungi un libro");//fatto
    printf ("\n 4 - Ricerca libro per Autore");//forse
    printf ("\n 5 - Ricerca libro per anno di pubblicazione");//fatto
    printf ("\n 6 - Classifica Autori chi ha pių libri pubblicati");
    printf ("\n 7 - Ordina per autore crescente");//fatto
    printf ("\n 8 - Ricerca libro per genere e anno di pubblicazione");
    printf ("\n 9 - Elimina Autore e tutti i suoi libri");
  	printf ("\n 10 - Creare un file BINARIO o .DAT ---- VEDI SLIDE date qualche settimana fa");
  	printf ("\n 0 - Esci e Salva le modifiche al file TXT");
    printf ("\ninserisci il numero della tua scelta:\t" );
    fgets(b,3,stdin);
    a=atoi(b);
    switch (a) {
      case 1: a=altro(); elimina(a);break;
      case 2: for (int i=0;i<c;i++) {stampa(i);} ;break;
      case 3: aggiungi();break;
      case 4: cercaAutore();break;
      case 5: anno();break;
      case 6: piuLibri();break;
      case 7: autorescresce();break;
      case 8: otto();break;
      case 9:;break;
      case 10:;break;
      case 0: salvalibri();break;
      default: printf("\aERRORE INSERIMENTO\n");system("pause");
    }
    sistem();
    system("pause");
    system("cls");
  }while(a!=0);
  return 0;
}

void stampa(int i){
  printf("%s %s %s %s %d %.2f\n",libri[i].titolo,libri[i].autore,libri[i].casaEditrice,libri[i].genere,libri[i].annoPubblicazione,libri[i].prezzo);
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
  printf("dimmi il titolo:\t");
  fgets(libri[c].titolo,N,stdin);
  printf("dimmi l'autore:\t");
  fgets(libri[c].autore,N,stdin);
  printf("dimmi la casa editrice:\t");
  fgets(libri[c].casaEditrice,N,stdin);
  printf("dimmi il genere:\t");
  fgets(libri[c].genere,N,stdin);
  printf("dimmi l' anno di pubblicazione:\t");
  fgets(app,N,stdin);
  libri[c].annoPubblicazione=atof(app);
  printf("dimmi il codto:\t");
  fgets(app,N,stdin);
  libri[c].prezzo=atoi(app);
  c++;
  //sistemare();
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

void cercaAutore(){
  char autore[N];
  int a=0;
  printf("inserisci nome autore:\t");
  fgets(autore,N,stdin);
  sistemare(autore);
  a=1;
  for (int i=0;i<c;i++){
    if (strstr(autore,libri[i].autore)!=NULL){
      printf("%d)\n",a );
      stampa(i);
      a++;
    }
  }
  if (a==1){
    printf ("Autore non trovato\n");
  }
}

void anno(){
  char b[50];
  int a,d=1;
  printf("dimmi l'anno di pubblicazione:\t");
  fgets(b,50,stdin);
  a=atoi(b);
  for (int i=0;i<c;i++){
    if (libri[i].annoPubblicazione==a){
      printf("%d)\n",d );
      stampa(i);
      d++;
    }
  }
  if (a==1){
    printf ("anno non trovato\n");
  }
}

int numeroLibriAutore(int a){
  int num=0;
  for (int i=0;i<c;i++){
    if (strcmp(libri[a].autore,libri[i].autore)==0){
      num++;
    }
  }
  return num;
}

void piuLibri(){
  char books[c][N];
  int linea[c],linea2[c];
  linea [0]=0;
  int a=1;
  strcpy(books[0],libri[0].autore);
  for (int i=0;i<c;i++){
    for (int j=0;j<c;c++){
      if (strcasecmp(libri[j].autore,books[i])!=0){
        strcpy(books[a],libri[j].autore);
        linea[a]=j;
        a++;
      }
    }
  }
  for (int i=0;i<a;i++){
    linea2[i]=numeroLibriAutore(linea[i]);
  }
  int j,val,val2;
	for(int i=1;i<c;i++){
		val = linea2[i];
    val2=linea[i];
		j=i-1;
		for(;j>=0 && linea2[j]>val; j--){
			linea2[j+1]=linea2[j];
      linea[j+1]=linea[j];
		}
		linea2[j+1] = val;
    linea[j+1]=val2;
	}

  for (int i=0;i<c;i++){
    printf("%s %d\n",libri[linea[i]].autore,linea2[i] );
  }
}

void sistem(){
  for (int i=0;i<c;i++){
    sistemare(libri[i].titolo);
    sistemare(libri[i].autore);
    sistemare(libri[i].casaEditrice);
    sistemare(libri[i].genere);
  }
}

int altro(){
  char b[3];
  int a;
  for (int i=0;i<c;i++) {
    printf("%d)\t",++i );
    stampa(i);
    i--;
  }
  fgets(b,3,stdin);
  a=atoi(b);
  return a;
}

void caricalibri(){
  FILE *file;
  file = fopen("inventario.txt", "r");
  if (file!=NULL){
    while (feof(file) == 0){
      fscanf(file,"%s %s %s %s %d %f",libri[c].titolo,libri[c].autore,libri[c].casaEditrice,libri[c].genere,&libri[c].annoPubblicazione,&libri[c].prezzo);
      c++;
    }
  }
  else{
    printf("ERRORE\n" );
  }
  fclose(file);
}

void salvalibri(){
  FILE *file;
  file = fopen("inventario.txt", "w");
  if (file!=NULL){
    for (int i=0;i<c;i++){
      fprintf(file,"%s %s %s %s %d %f\n",libri[i].titolo,libri[i].autore,libri[i].casaEditrice,libri[i].genere,libri[i].annoPubblicazione,libri[i].prezzo);
    }
  }
  else{
    printf("ERRORE\n" );
  }
  fclose(file);
}

void autorescresce(){
  int i,j;
  char str[25][25],temp[25];
  for(i=0;i<=c;i++)
    strcpy(str[i],libri[i].autore);
  for(i=0;i<=c;i++)
    for(j=i+1;j<=c;j++){
      if(strcasecmp(str[i],str[j])>0){
        strcpy(temp,str[i]);
        strcpy(str[i],str[j]);
        strcpy(str[j],temp);
      }
  }
  for(i=0;i<=c;i++)
    puts(str[i]);
}

void otto(){
  char n[50],app[c][N],autore[N];
  int a,d=1,v=0;
  printf("dimmi l'anno di pubblicazione:\t");
  fgets(n,50,stdin);
  a=atoi(n);
  for (int i=0;i<c;i++){
    if (libri[i].annoPubblicazione==a){
      printf("%d)\n",d );
      stampa(i);
      d++;
      strcpy(app[v],libri[i].genere);
      v++;
    }
  }
  if (a==1){
    printf ("anno non trovato\n");
  }
  a=0;
  printf("inserisci nome autore:\t");
  fgets(autore,N,stdin);
  sistemare(autore);
  a=1;
  for (int i=0;i<c;i++){
    if (strstr(autore,app[i])!=NULL){
      printf("%d)\n",a );
      stampa(i);
      a++;
    }
  }

  if (a==1){
    printf ("Autore non trovato\n");
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
