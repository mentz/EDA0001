#include <stdio.h>
#include "PDSE.h"

int main(void)
{ 
	PDSE *p = NULL; //<<<< atencao: essa declaracao tem que ser com o typedef
	char ch;

	if( cria(&p,sizeof(int)) ) { 
		ch = 'a';
		insere(p, &ch);
		busca(p, &ch);
		printf("topo: %c\n", ch);
		getchar();
		
		ch = 'b';
		insere(p, &ch);
		busca(p, &ch);
		printf("topo: %c\n", ch);
		getchar();

		ch = 'c';
		insere(p, &ch);
		busca(p, &ch);
		printf("topo: %c\n", ch);

		destroi(&p);

		return 0;
	}

	return 1;
}
