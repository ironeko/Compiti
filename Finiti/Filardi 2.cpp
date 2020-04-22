/*Esercizio 2
Sia dato il file Esami.txt contenente una sequenza di studenti iscritti per una prova d’esame con le seguenti voci matricola, Cognome, Nome, Anno di corso di uno studente e il Voto ottenuto. Come ad esempio.
29333 Rossi Alberto 2RG 28
34211 Neri Franco 3FC 15 (esame non superato)
23432 Bianchi Luca 3RG 24
35211 Verdi Federico 4FC 28
22222 Blu Chiara 2RG 27
34211 Neri Franco 3FC 18 (esame superato)
Si noti che:
I dati sono separati da uno spazio vuoto;
Nome e Cognome non contengono spazi;
L’anno di corso è composto dall'anno, e due caratteri FC o RG, a seconda che lo studente sia fuori corso o regolare.
Si scriva una programma C che una volta caricati i dati da file fornisce all’utente un menù di scelta, con le seguenti voci:
1. Ricerca frazionata delle informazioni di uno studente: Prima viene chiesto il cognome, il programma fornisce l'elenco di tutto gli alunni con quel cognome e poi chiede il nome e quindi fa la selezione anche per nome sul risultato precedente
2. Conteggio studenti Fuori Corso: Preso in ingresso un anno di corso (un intero tra 1 e 5), restituire il numero di studenti iscritti fuori corso per quell’anno.
3. visualizzare i dati di tutti degli studenti che hanno ottenuto un voto maggiore o uguale a V inserito da tastiera*/

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

int c=0;
const int MAX=100;

struct studente{
  int matricola;
  char cognome [MAX];
  char nome [MAX];
  char anno [3];
  int voto;
} studenti[MAX];

void ricerca();
void conto();
void maggiore();
void printone(int co);

int main(){
  const int N=4;
  FILE *file = fopen("Esami.txt", "a");
  fclose(file);
  file= fopen("Esami.txt", "r");
  if (file == NULL) {
    printf("Errore.\n");
  }
  char buffer[MAX];
  while (fgets(buffer,MAX*5,file)!=NULL) {
   sscanf(buffer,"%d %s %s %s %d ",&studenti[c].matricola,studenti[c].cognome,studenti[c].nome,studenti[c].anno,&studenti[c].voto);
   c++;
 }
 fclose(file);
  printf ("%d",c);

  char *pass[N];//i warning sono dati dal pèassaggio di un vetore di puntatori a stringhe alla libreria
  pass[0]="Ricerca per cognome";//non dannoproblemi in alcun modo, ho controllato
  pass[1]="conteggio studenti fuori corso";//non ho trovato un modo migliore, ma sto cercando di miogliorarla
  pass[2]="voto maggiore";
  pass[3]="Esci";
  int s;
  do{
    s=create_menu("Programma universita'\n\n",N,pass);
    switch(s){
      case 0:ricerca();break;
      case 1:conto();break;
      case 2:maggiore();break;
    }
    system ("pause");
    system ("cls");
  }while(s!=3);
}

void ricerca(){
  char b[MAX],bb[MAX];
  int array[MAX],a=0;
  printf("inserire cognome:\t" );
  scanf("%s",b);
  for (int i=0; i<c; i++) {
    if (strstr(studenti[i].cognome, b) != NULL) {
      printf("%d %s %s %s %d \n", studenti[i].matricola,studenti[i].cognome,studenti[i].nome,studenti[i].anno,studenti[i].voto);
      array[a]=i;
      a++;
    }
  }
  printf("inserire nome:\t" );
  scanf("%s",bb);
  for (int i=0; i<a; i++) {
    if (strstr(studenti[array[i]].nome, bb) != NULL) {
      printf("%d %s %s %s %d \n", studenti[array[i]].matricola,studenti[array[i]].cognome,studenti[array[i]].nome,studenti[array[i]].anno,studenti[array[i]].voto);
    }
  }
}

void conto(){
  int a;
  for (int i=0;i<c;i++){
    if (studenti[i].anno[2]=='F'){
      a++;
    }
  }
  printf("ci sono %d styudenti fuori corso\n",a );
}

void maggiore(){
  int a,b=0;
  printf("dimmi il voto di riferimento:\t");
  scanf("%d",&a);
  for (int i=0;i<=c;i++){
    if (studenti[i].voto>a){
      b++;
    }
  }
  printf("ci sono %d persone col voto maggiore\n",b);
}

void printone(int co) {
  printf("%d %s %s %s %d ", studenti[co].matricola,studenti[co].cognome,studenti[co].nome,studenti[co].anno,studenti[co].voto);
}
































//space
