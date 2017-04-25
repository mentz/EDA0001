#ifndef MPE_H
#define MPE_H

#define SUCESSO 1
#define FRACASSO 0

typedef struct mp MP;

int cria(MP **pp, int N, int L, int tamInfo);
int insereNaPilha(MP *p, int nPilha, void* novo);
int removeDaPilha(MP *p, int nPilha, void* removido);
int consultaTopo(MP *p, int nPilha, void* consultado);
void destroi(MP **pp);

#endif
