#ifndef PDDE_PRIV_H
#define PDDE_PRIV_H

#include "PDDE.h"

typedef struct noPDDE {
	void *dados;
	struct noPDDE *abaixo;
	struct noPDDE *acima;
} NoPDDE;

typedef struct pdde { 
	int tamInfo;
	NoPDDE *topo;
} PDDE;

#endif
