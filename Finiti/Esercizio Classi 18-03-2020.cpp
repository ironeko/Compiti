//creato dal Provessor Geroli
/******************************************************************
* Il programma riceve in input un file cognomi.txt
* dove in ogni riga vi sono i cognomi degli studenti della classe
* In output produrr� un file tabellone.txt come da struttura
*******************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;
#define N 100  //numero max alunni
#define NMAT 5 //numero materie
enum materie {ita,mate,sis,inf,ing};

//struttuta alunno; cognome voto[ita]   voto[mate]  ...
struct Alunno {
    char cognome[20];
    int voti[NMAT];
    float media;
    int votoAlto, votoBasso;
    int votiPos, votiNeg;//numero voti positivi e numero voti negativi
    int debiti;
    char esito[20];
};
// carica i cognomi letti la file cognomi.txt
int caricaCognomi(Alunno classe[]);
void inserimentoVoti(Alunno classe[],int);
void statistiche(Alunno classe[],int);
int salvataggioDati(Alunno classe[],int);
//void aggiuntaAlunno();

int main(){
    int scelta,n=0;
    struct Alunno classe[N];

    do{system("cls");
      printf("\n=========MENU===========");
      printf("\n\t1. Carica Cognome studenti dal file");
      printf("\n\t2. Inserimento voti per Alunno (voti casuali)");
      printf("\n\t3. Genera Statistiche");
      printf("\n\t4. Salvataggio Dati");
      printf("\n\t0. Esci\nSscegli: ");
      scanf("%d",&scelta);
      switch (scelta){
            case 1:
                n=caricaCognomi(classe);
                printf("\nCaricati %d Nomi\n\n",n);
                break;
            case 2:
                if (n>0){
                    inserimentoVoti(classe,n);
                    printf("\n voti caricati\n\n");
                }else{
                    printf("\n devi prima caricare i cogmoni - Scelta:1 - \n\n");
                }
                break;
            case 3:
                if (n>0){
                    statistiche(classe,n);
                    printf("\n statistiche generate\n\n");
                }else{
                    printf("\n devi prima caricare i cogmoni - Scelta:1 - \n\n");
                }
                break;
            case 4:
                if (salvataggioDati(classe,n)==-1){
                        printf("\n Dati non salvati\n\n");

                }
                break;
             /*case 5:
                aggiuntaAlunno();
                break;*/

        }
        system("pause");
    }while(scelta!=0);

    return 0;
}

int caricaCognomi(Alunno classe[]){
   FILE *fp;
   int conta=0;
   fp=fopen("cognomi.txt","r");
   if(fp==NULL){
    printf("Errore di I/O");
    return -1;
   }

   while(!feof(fp)){
        fscanf(fp,"%s",classe[conta].cognome);
        conta++;
   }
   fclose(fp);
    return conta;
}

void inserimentoVoti(Alunno classe[],int n){
    srand((unsigned)time(NULL));
    for(int i; i<n; i++){
        for(int j=ita; j<=ing;j++){
            classe[i].voti[j]=(rand()%8)+3;
        }
    }

}

void statistiche(Alunno classe[],int n){
    for(int i=0;i<n;i++){
        classe[i].media=0;
        classe[i].votiPos=0;
        classe[i].votoAlto=3;
        classe[i].votoBasso=10;
        for(int j=ita;j<=ing;j++){
            classe[i].media+=classe[i].voti[j];
            if (classe[i].voti[j]>=classe[i].votoAlto){
                classe[i].votoAlto=classe[i].voti[j];
            }
            if (classe[i].voti[j]<classe[i].votoBasso){
                classe[i].votoBasso=classe[i].voti[j];
            }
            if (classe[i].voti[j]>=6){
                classe[i].votiPos++;
            }
        }
        classe[i].votiNeg=NMAT-classe[i].votiPos;
        classe[i].debiti=classe[i].votiNeg;
        classe[i].media/=NMAT;
        switch(classe[i].debiti){
            case 0:
                strcpy(classe[i].esito,"Promosso");
                break;
            case 1: case 2: case 3:
                strcpy(classe[i].esito,"Debito a Settembre");
                break;
            default:
                strcpy(classe[i].esito,"Bocciato");

        }
    }
    return;
}

int salvataggioDati(Alunno classe[],int n){
    FILE *fp;
    fp=fopen("tabellone.txt","w");
    if (fp==NULL){
        printf("errore di I/O");
        return -1;
    }

    fprintf(fp,"Cognome\tita\tmate\tsis\tinf\ting\tPos\tNeg\tvBasso\tvAlto\tMedia\tDebiti\tEsito\n");

    for(int i;i<n;i++){
        fprintf(fp,"%s\t",classe[i].cognome);
        for(int j=ita;j<=ing;j++){
            fprintf(fp,"%d\t",classe[i].voti[j]);
        }
        fprintf(fp,"%d\t",classe[i].votiPos);
        fprintf(fp,"%d\t",classe[i].votiNeg);
        fprintf(fp,"%d\t",classe[i].votoBasso);
        fprintf(fp,"%d\t",classe[i].votoAlto);
        fprintf(fp,"%.2f\t",classe[i].media);
        fprintf(fp,"%d\t",classe[i].debiti);
        fprintf(fp,"%s\n",classe[i].esito);
    }
    fclose(fp);
    return 0;
}
/*void aggiuntaAlunno(){
    char cogn[20];
    FILE *fp;
    printf("inserisci il Cognome dello stodente");
    scanf("%s",cogn);
    fp=fopen("cognomi.txt","a+");
    fprintf(fp,"%s",cogn);
    fclose(fp);

}
*/
