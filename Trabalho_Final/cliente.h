#include "ABB.h"

typedef struct {
	int matricula;
	int linha;
} info;

typedef struct
{
	int matricula;
	char nome[10];
	int telefone;
	double salario;
	int idade;
	char departamento[30];
} Pessoa;

unsigned short comparaChaves(void *pInfo1, void *pInfo2);
void exibeChave(void *pInfo);
void flush(FILE *in);
int constroiArvoreIndices(pABB pT, FILE ** arquivo);
int removerMatricula(ppABB ppT, info * pInfo, FILE ** arquivo);
