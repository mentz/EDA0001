#ifndef CLIENTE_H
#define CLIENTE_H

#include "tdaFDDE.h"

#define N 30

#define chave RG

typedef int tipoChave;

typedef struct {  
	char matricula[N];
	tipoChave chave;
} info;

void menu(FDDE* p);
void exibe(void *a);

#endif
