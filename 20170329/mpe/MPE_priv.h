#ifndef MPE_PRIV_H
#define MPE_PRIV_H

#include "MPE.h"

/* Nó descritor da uma pilha */
typedef struct {
    short int topo;
    short int inicioParticao;
} DescPilha;

/* Nó da Multi-Pilha */
typedef union {
    DescPilha descritor;
    void* dados;
} NoMP;

/* Descritor da Multi-Pilha */
typedef struct mp {
    int N; /* N = Número de Pilhas*/
    int L; /* L = Tamanho máximo da partição de cada Pilha*/
    int tamInfo;
    NoMP *vet;
} MP;

#endif
