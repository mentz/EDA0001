#ifndef FDDE_H
#define FDDE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct noFDDE {
    void* dados;
    struct noFDDE* detras;
    struct noFDDE* defronte;
} NoFDDE, *pNoFDDE;

typedef struct {
    pNoFDDE cauda;
    pNoFDDE frente;
    int tamInfo;
} FDDE;

int cria(FDDE** pp, int tamInfo);
void destroi(FDDE** pp);
void purga(FDDE* p);
int buscaNaFrente(FDDE* p, void* dest);
int buscaNaCauda(FDDE* p, void* dest);
int enfileira(FDDE* p, void* novo);
int desenfileira(FDDE* p);
int filaVazia(FDDE* p);

#endif
