#ifndef FDP_H
#define FDP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct noFDP {
    void* dados;
    struct noFDP* detras;
    struct noFDP* defronte;
} NoFDP, *pNoFDP;

typedef struct {
    pNoFDP cauda;
    pNoFDP frente;
    int tamInfo;
    int (*compara)(void* inf1, void* inf2);
} FDP;

int cria(FDP** pp, int tamInfo, int (*compara)(void* inf1, void* inf2));
void destroi(FDP** pp);
void purga(FDP* p);
int buscaNaFrente(FDP* p, void* dest);
int buscaNaCauda(FDP* p, void* dest);
int insere(FDP* p, void* novo);
int remover(FDP* p);
int filaVazia(FDP* p);
void printLista(FDP* p);

#endif
