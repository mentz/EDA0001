#ifndef TDA_PILHA_H
#define TDA_PILHA_H

#define LIVRE 0
#define OCUPADA 1
#define FRACASSO 0
#define SUCESSO 1
#define VERDADEIRO 1
#define VAZIA -1
#define SIM 1
#define NAO 0

typedef struct descPE PE;

int cria(PE **pp, int capMax, int tamInfo);
void destroi(PE **pp);
void purga(PE *p);
int buscaNoTopo(PE *p, void *pReg);

/*------------ATENÇÃO: pelo conceito de transação atômica
desempilha  #apenas# decrementa o topo ---------------------*/
int desempilha(PE *p);
int empilha(PE *p, void * novo);
int testaVazia(PE *p);
int testaCheia(PE *p);

#endif
