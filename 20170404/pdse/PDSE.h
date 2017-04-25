#ifndef PDSE_H
#define PDSE_H

#define FRACASSO 0
#define SUCESSO 1
#define NAO 0
#define SIM 1

typedef struct pdse PDSE;

int cria(PDSE **pp, int tamInfo);

/*************** EMPILHA NO TOPO A PARTIR DO ENDEREÇO FORNECIDO PELO O CHAMADOR **************/
int insere(PDSE *p, void *novo);

/*************** RETORNA A PILHA À CONDIÇÃO "VAZIA" **************/
void reinicia(PDSE *p);

int testaSeVazia(PDSE *p);

void destroi(PDSE **pp);

/*************** BUSCA NO TOPO E COPIA ITEM P/ O CHAMADOR **************/
int busca(PDSE *p, void *reg);

/*************** DESEMPILHA E COPIA ITEM REMOVIDO P/ O CHAMADOR **************/
int remove_(PDSE *p, void *reg);

#endif
