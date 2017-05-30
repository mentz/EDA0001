#ifndef LDSE_H
#define LDSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct noLDSE
{
    struct noLDSE* prox;
    void* dados;
} NoLDSE, *pNoLDSE;


typedef struct {
    int tamInfo;
    void* inicio;
} LDSE, *pLDSE, **ppLDSE;

int cria(ppLDSE pp, int tamInfo);
void destroi(ppLDSE pp);
void reinicia(pLDSE p);
int filaVazia(pLDSE p);
int tamFila(pLDSE p);
int buscaPrimeiro(pLDSE p, void* dest);
int insereNovoPrimeiro(pLDSE p, void* novo);
int removePrimeiro(pLDSE p);
int buscaUltimo(pLDSE p, void* dest);
int insereNovoUltimo(pLDSE p, void* novo);
int removeUltimo(pLDSE p);
int buscaNaPosicao(pLDSE p, void* dest);
int insereNaPosicao(pDLSE p, void* novo);
int removeNaPosicao(pLDSE p);

#endif
