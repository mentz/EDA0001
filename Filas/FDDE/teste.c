#include <stdio.h>
#include <stdlib.h>
#include "fdde.h"

int main(void)
{
    FDDE *p = NULL;
    cria(&p, sizeof(int));
    int *n = malloc(sizeof(int)), *c = malloc(sizeof(int)), *f = malloc(sizeof(int));
    *n = 1;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    *n = 2;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    *n = 3;
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    *n = 4;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    *n = 5;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);
    *n = 6;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    *n = 7;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    *n = 8;
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    *n = 9;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    *n = 0;
    enfileira(p, n);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("E\tCauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);
    desenfileira(p);
    buscaNaCauda(p, c); buscaNaFrente(p, f);
    printf("D\tCauda: %d\tFrente: %d\n", *c, *f);

    destroi(&p);
    return 0;
}
