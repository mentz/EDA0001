#ifndef FEM1_H
#define FEM1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct {
    void ** vet;
    int cauda;
    int frente;
    int tamVet;
    int tamInfo;
} FEM;

int cria(FEM **, int, int);
void destroi(FEM **);
void purga(FEM *);
int buscaNaCauda(FEM *, void*);
int buscaNaFrente(FEM *, void*);
int desenfileira(FEM *);
int enfileira(FEM *, void*);
int filaVazia(FEM *);
int filaCheia(FEM *);

#endif
