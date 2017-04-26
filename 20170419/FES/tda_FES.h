#ifndef FES_H
#define FES_H

#define LIVRE 0
#define OCUPADA 1
#define FRACASSO 0
#define SUCESSO 1
#define VERDADEIRO 1
#define VAZIA -1
#define SIM 1
#define NAO 0

typedef struct descFES FES;

int cria(FES **pp, int capMax, int tamInfo);
void destroi(FES **pp);
void purga(FES *p);
int buscaNocauda(FES *p, void *pReg);
int buscaNofrente(FES *p, void *pReg);

/*------------ATENÇÃO: FESlo conceito de transação atômica
desempilha  #aFESnas# decrementa o topo ---------------------*/
int desenfileira(FES *p);
int enfileira(FES *p, void *novo);
int testaVazia(FES *p);
int testaCheia(FES *p);

#endif
