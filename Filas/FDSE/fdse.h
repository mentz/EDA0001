#ifndef FDSE_H
#define FDSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct noFDSE {
    void* dados;
    struct noFDSE* atras;
} NoFDSE, *pNoFDSE;

typedef struct {
    pNoFDSE cauda;
    pNoFDSE frente;
    int tamInfo;
} FDSE;

int cria(FDSE** pp, int tamInfo);
void destroi(FDSE** pp);
void purga(FDSE* p);
int buscaNaFrente(FDSE* p, void* dest);
int buscaNaCauda(FDSE* p, void* dest);
int enfileira(FDSE* p, void* novo);
int desenfileira(FDSE* p);
int filaVazia(FDSE* p);

#endif
