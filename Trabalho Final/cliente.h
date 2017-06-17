#include "ABB.h"

typedef struct {
	unsigned int matricula;
	int idade;
} info;

unsigned short comparaChaves(void *pInfo1, void *pInfo2);
void exibeChave(void *pInfo);
void flush(FILE *in);
void menu(pABB p);
