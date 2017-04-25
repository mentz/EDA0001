#ifndef FDDE_PRIV_H
#define FDDE_PRIV_H

#include "tdaFDDE.h"

typedef struct noPilha {
	void *dados;
	struct noPilha *atras;
	struct noPilha *defronte;
} NoFila;

struct fila {
	NoFila *frente;
	NoFila *cauda;
	int tamInfo;
};

#endif
