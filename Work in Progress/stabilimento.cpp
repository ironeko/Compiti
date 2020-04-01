/*stabilimento balneare*/

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
void salva();
void carica();

int main (){
  int a;
  char b[4];
  carica();
  char abba[N];
  fgets(abba,N,stdin);
  sistemare(abba);
  printf("%s\n",abba );
  do{
    printf("ancora nulla\n" );
    fgets(b,4,stdin);
    a=atoi(b);
    printf("\n\n");
    switch (a) {
      case 1: printf("boh\n" );break;
      case 0: salva();break;
      default: printf("\aERRORE INSERIMENTO\n");system("pause");
    }
    //sistem();
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

void carica(){

}

void salva(){

}








































//space
