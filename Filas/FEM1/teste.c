#include <stdio.h>
#include <stdlib.h>
#include "fem1.h"

int main(void)
{
    FEM *p = NULL;
    cria(&p, 10, sizeof(int));
    int *n = malloc(sizeof(int)), *c = malloc(sizeof(int)), *f = malloc(sizeof(int));
    *n = 10;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    *n = 11;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    *n = 12;
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    *n = 13;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    *n = 9;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("Cauda: %d\tFrente: %d\n", *c, *f);
    printf("Erro? %d\n", desenfileira(p));

    destroi(&p);
    return 0;
}
