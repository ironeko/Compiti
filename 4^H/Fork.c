// gcc Fork.c
// ./a.out 5
// 5 = numero di figli

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define figlio(io) printf("%d) Processo figlio -> pid = %d & ppid = %d\n", io, getpid(), getppid())
#define padre printf("Processo padre -> pid = %d\n", getpid())
static inline void controllo(int pid, int figli, int pMax){pid == 0 ? figlio(figli) : figli < pMax ? controllo(fork(), ++figli, pMax) : padre;}
int main(int argc, char *argv[]){atoi(argv[1]) > 0 ? controllo(fork(), 1, atoi(argv[1])) : padre;}