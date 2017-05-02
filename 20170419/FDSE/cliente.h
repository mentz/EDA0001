#ifndef CLIENTE_H
#define CLIENTE_H

#define FRACASSO 0
#define SUCESSO 1

#include "FDSE.h"

typedef struct {
    int matricula;
} info;

void flush(FILE *in);
void menu(FDSE *p);

#endif
