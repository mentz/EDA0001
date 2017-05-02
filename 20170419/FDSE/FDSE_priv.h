#ifndef FDSE_PRIV_H
#define FDSE_PRIV_H

#include "FDSE.h"

typedef struct noFDSE {
    void *dados;
    struct noFDSE *atras;
} NoFDSE;

typedef struct FDSE { 
    int tamInfo;
    NoFDSE *cauda;
    NoFDSE *frente;
} FDSE;

#endif
