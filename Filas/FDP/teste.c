#include <stdio.h>
#include <stdlib.h>
#include "fdp.h"

int compara(void* f1, void* f2)
{
    int a, b, ret = -2;
    memcpy((void*) &a, f1, sizeof(int));
    memcpy((void*) &b, f2, sizeof(int));
    if (a < b)
        ret = -1;
    if (a == b)
        ret =  0;
    if (a > b)
        ret =  1;

    return ret;
}

int main(void)
{
    FDP *p = NULL;
    cria(&p, sizeof(int), &compara);
    int *n = malloc(sizeof(int));
    *n = 156;
    insere(p, n);
    printLista(p);
    *n = 42;
    insere(p, n);
    printLista(p);
    *n = 275;
    remover(p);
    printLista(p);
    insere(p, n);
    printLista(p);
    *n = 20;
    insere(p, n);
    printLista(p);
    *n = 6;
    insere(p, n);
    printLista(p);
    remover(p);
    printLista(p);
    remover(p);
    printLista(p);
    remover(p);
    printLista(p);
    remover(p);
    printLista(p);
    *n = 1563;
    insere(p, n);
    printLista(p);
    *n = 485;
    insere(p, n);
    printLista(p);
    *n = 499;
    remover(p);
    printLista(p);
    insere(p, n);
    printLista(p);
    *n = 4653;
    insere(p, n);
    printLista(p);
    *n = -1250;
    insere(p, n);
    printLista(p);
    remover(p);
    printLista(p);
    remover(p);
    printLista(p);
    remover(p);
    printLista(p);
    remover(p);
    printLista(p);
 
    destroi(&p);
    return 0;
}
