#include <stdio.h>
#include "PDDE.h"

int main()
{
	PDDE *p = NULL;
	int i=0;

	if( !cria(&p, sizeof(int)) ) {
		return 1;
	}

	if( testaSeVazia(p) ) {
		printf("Vazia\n");
	}

	i = 1;
	insere(p, &i);

	i = 2;
	insere(p, &i);

	printf("tamanho = %d\n", tamanho(p));

	while( remove_(p, &i) ) {
		printf("%d\n", i);
	}

	printf("tamanho = %d\n", tamanho(p));

	return 0;
}
