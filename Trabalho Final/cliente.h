#include "ABB.h"

typedef struct {
	unsigned int matricula;
	int idade;
} info;

unsigned short comparaCamposChaves1(void *pInfo1, void *pInfo2);
unsigned short comparaCamposChaves2(void *chave, void *pInfo);
void exibeChave(void *pInfo);
void flush(FILE *in);
void menu(pABB p);
