#ifndef PDSE_PRIV_H
#define PDSE_PRIV_H

#include "PDSE.h"

typedef struct noPDSE {
	void *dados;
	struct noPDSE *abaixo;
} NoPDSE;

typedef struct pdse { 
	int tamInfo;
	NoPDSE *topo;
} PDSE;

#endif
