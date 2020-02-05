#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#define L 3 //per aumentare questo sistemate i case dello swich

void stampa(int[L][L]);
int controllo(int[L][L]);

int main (){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int squere [L][L],pos,posnum[L*L],arr=0,a=0;
  bool tur=0,con=0;
  for (int i=0;i<L*L;i++)
    posnum[i]=0;
  printf("********Informazioni e Regole********\n\n\n");
  printf("Il tris \n(noto anche come filetto, fila tre, crocetta e pallino, zero per, cerchi e croci, tria, OXO, XOXO) \nè un popolarissimo gioco di carta e matita astratto a informazione perfetta.\n Si gioca su una griglia quadrata di 3×3 caselle.\n A turno, i giocatori scelgono una cella vuota e vi disegnano il proprio simbolo \n(di solito un giocatore ha come simbolo una \"X\" e l'avversario un cerchio). \nVince il giocatore che riesce a disporre tre dei propri simboli in linea \nretta orizzontale, verticale o diagonale.\nSe la griglia viene riempita senza che nessuno dei giocatori sia riuscito a completare una linea retta di tre simboli, \nil gioco finisce in parità. \nNel caso in cui il gioco finisse in parità, la partita è detta \"patta\", \ncome nel gioco da tavolo degli scacchi.\n");
  printf("\n\n********source wikipedia********\n\n\n");
  // azzeramento
  for(int i=0;i<=L;i++){
    for (int j=0;j<=L;j++){
      squere[i][j]=0;
    }
  }
  //porte ripetutamentazione
  do{
    //stampaggio e scaneffaggio
    con=0;
    do {
      stampa(squere);
      if (tur==0){
        printf("inserire il numero in cui \"");
        SetConsoleTextAttribute(hConsole, 12);
        printf("X");
        SetConsoleTextAttribute(hConsole, 7);
        printf("\" vuole inserire i'oggetto:\t");
      }
      else{
        printf("inserire il numero in cui \"");
        SetConsoleTextAttribute(hConsole, 9);
        printf("O");
        SetConsoleTextAttribute(hConsole, 7);
        printf("\" vuole inserire i'oggetto:\t");
      }
      scanf ("%d",&pos);
      if (pos<=(L*L) && pos>=1){
        for (int i=0;i<arr;i++){
          if (pos==posnum[i]){
            con=1;
            i+=arr+1;
          }
          else
            con=0;
        }
      }
      else
        con=1;
      if (con==1){
        printf("inserimento errato\n");
        system ("pause");
        system("cls");
      }
    }while(con==1);
    posnum[arr]=pos;
    arr++;
    //disegnamentazione
    switch (pos) { //possibiltà di miglioramento con for: chrare un for che va avanti e ailimenti un if per i case (if(pos==i)) insegito creare una serie di if che costriscano il comando
      case 1:if (tur==0){squere[0][0]=1;tur=1;}else{squere[0][0]=2;tur=0;}break;
      case 2:if (tur==0){squere[0][1]=1;tur=1;}else{squere[0][1]=2;tur=0;}break;
      case 3:if (tur==0){squere[0][2]=1;tur=1;}else{squere[0][2]=2;tur=0;}break;
      case 4:if (tur==0){squere[1][0]=1;tur=1;}else{squere[1][0]=2;tur=0;}break;
      case 5:if (tur==0){squere[1][1]=1;tur=1;}else{squere[1][1]=2;tur=0;}break;
      case 6:if (tur==0){squere[1][2]=1;tur=1;}else{squere[1][2]=2;tur=0;}break;
      case 7:if (tur==0){squere[2][0]=1;tur=1;}else{squere[2][0]=2;tur=0;}break;
      case 8:if (tur==0){squere[2][1]=1;tur=1;}else{squere[2][1]=2;tur=0;}break;
      case 9:if (tur==0){squere[2][2]=1;tur=1;}else{squere[2][2]=2;tur=0;}break;
      default: printf("ERRORE\n");system("pause");
    }
    a=controllo(squere);
    system("cls");
    if(arr==9&&a==0)
      a=3;
  }while (a==0);
  //vincitoramentazione
  if (a==1){
    printf("\"X\" VINCE!!!!!!!!!!!!!!!!!!!!!!\n" );
  }
  else if (a==2){
    printf("\"O\" VINCE!!!!!!!!!!!!!!!!!!!!!!\n" );
  }
  else if (a==3){
    printf("Partita Patta\n" );
  }
  system("pause");
}

void stampa(int sq [L][L]){
  int a=1;
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  for(int i=0;i<L;i++){
    for (int j=0;j<L;j++){
      printf("\t");
      if (sq[i][j]==1){
        SetConsoleTextAttribute(hConsole, 12);
        printf("X");
      }
      else if (sq[i][j]==2){
        SetConsoleTextAttribute(hConsole, 9);
        printf("O");
      }
      else{
        SetConsoleTextAttribute(hConsole, 11);
        printf("%d",a);
      }
      SetConsoleTextAttribute(hConsole, 15);
      a++;
      if (j!=2)printf("  |");
    }
    if (i!=2)printf("\n\t________________\n" );
  }
  printf("\n\n\n" );
  SetConsoleTextAttribute(hConsole, 7);
}

int controllo(int sq [L][L]){
  int a=0;
  //rigamentazione
  for (int i=0;i<L;i++){
    if (sq[i][0]!=0 && sq[i][1]!=0 && sq[i][2]!=0){
      while (a<3){
        if (sq[i][0]==a && sq[i][1]==a && sq[i][2]==a){
          return a;
        }
        a++;
      }
    }
  }
  a=0;
  //colonette
  for (int i=0;i<L;i++){
    if (sq[0][i]!=0 && sq[1][i]!=0 && sq[2][i]!=0){
      while (a<3){
        if (sq[0][i]==a && sq[1][i]==a && sq[2][i]==a){
          return a;
        }
        a++;
      }
    }
  }
  a=0;
  //diagoanali
  if (sq[1][1]!=0){
    while (a<3){
      if (sq[1][1]==a){
        if (sq[0][0]==a && sq[2][2]==a)
          return a;
        if (sq[0][2]==a && sq[2][0]==a)
          return a;
      }
      a++;
    }
  }
  return 0;
}
