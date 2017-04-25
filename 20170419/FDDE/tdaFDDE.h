#ifndef FDDE_H
#define FDDE_H

/* no turboC para DOS use:
 #include "client~1.h"*/

#define LIVRE 0
#define OCUPADA 1
#define FRACASSO 0
#define SUCESSO 1
#define FALSO 0
#define VERDADEIRO 1
#define NAO 0
#define SIM 1
#define MAIOR 1
#define IGUAL 0
#define MENOR -1

#ifdef  __unix__
   #define clrscr() system("clear");
#else
   #define clrscr() system("cls")
#endif

typedef struct fila FDDE;

int cria(FDDE** pp, int tamInfo);
int insere(FDDE* p, void *novo);
int buscaNaFrente(FDDE* p, void *pReg);
int buscaNaCauda(FDDE* p, void *pReg);
int retira(FDDE* p, void *pReg);
void destroi(FDDE** pp);
int purga(FDDE* p);
int testaVazia(FDDE* p);
void vaivem(FDDE* p, void (*  func)(void* x) );

#endif
