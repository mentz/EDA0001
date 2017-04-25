#ifndef COMPLEXO_PRIV_H
#define COMPLEXO_PRIV_H

#include "complexo.h"
/* especificação completa do modelo de dados para a representação do estado interno do TDA: Z = a + bi */
typedef struct NumComplexo {
    double a;
    double b;
} Complexo;

#endif
