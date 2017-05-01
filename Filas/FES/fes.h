#ifndef FES_H
#define FES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct {
    void ** vet;
    int frente;
    int cauda;
    int tamVet;
    int tamInfo;
} FES;

int cria(FES **, int, int);
void destroi(FES **);
void purga(FES *);
int buscaNaCauda(FES *, void *);
int buscaNaFrente(FES *, void *);
int desenfileira(FES *);
int enfileira(FES *, void *);
int filaVazia(FES *);
int filaCheia(FES *);

#endif
