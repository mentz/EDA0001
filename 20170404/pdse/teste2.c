#include <stdio.h>
#include "PDSE.h"

int main()
{
	PDSE *p = NULL;
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

	while( remove_(p, &i) ) {
		printf("%d\n", i);
	}

	return 0;
}
