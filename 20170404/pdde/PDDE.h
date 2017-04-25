#ifndef PDDE_H
#define PDDE_H

#define FRACASSO 0
#define SUCESSO 1
#define NAO 0
#define SIM 1

typedef struct pdde PDDE;

int cria(PDDE **pp, int tamInfo);

/*************** Empilha NO TOPO A PARTIR DO ENDEREÇO FORNECIDO PELO O CHAMADOR **************/
int insere(PDDE *p, void *novo);

/*************** RETORNA A PILHA À CONDIÇÃO "VAZIA" **************/
void reinicia(PDDE *p);

int testaSeVazia(PDDE *p);

void destroi(PDDE **pp);

/*************** BUSCA NO TOPO E COPIA ITEM P/ O CHAMADOR **************/
int busca(PDDE *p, void *reg);

/*************** Desempilha E COPIA ITEM REMOVIDO P/ O CHAMADOR **************/
int remove_(PDDE *p, void *reg);

int tamanho(PDDE *p);

#endif
