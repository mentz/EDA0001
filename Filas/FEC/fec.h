#ifndef FEC_H
#define FEC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct {
    void ** vet;
    int frente;
    int cauda;
    int tamInfo;
    int tamVet;
    int tamFila;
} FEC;

int cria(FEC** pp, int tamVet, int tamInfo);
void destroi(FEC** pp);
void purga(FEC* p);
int buscaNaFrente(FEC* p, void* dest);
int buscaNaCauda(FEC* p, void* dest);
int enfileira(FEC* p, void* novo);
int desenfileira(FEC* p);
int filaCheia(FEC* p);
int filaVazia(FEC* p);

#endif
