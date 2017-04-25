/* no turboC para DOS use:
#include "client~1.h"*/
#include <stdio.h>
#include "ClientePilha.h"

int main()
{ 
	PE *ptr = NULL; 

	if( cria(&ptr, 5, sizeof(info)) == SUCESSO ) {
		menu(ptr);
		destroi(&ptr);

		return 0;
	}
	
	return 1;
}

void menu(PE *p)
{
	char opc;
	info reg;

	do {
		clrscr();
		puts(" 1 busca no topo\n 2 empilha\n 3 desempilha \n 4 sair \n\n opcao: ");
		scanf("%c", &opc);
		clrscr();
		switch (opc)
		{
			case '1':
				if(buscaNoTopo(p,(void *)&reg)==FRACASSO)
					puts("pilha vazia!");
				else
					printf("\n topo: %i \n", reg.matricula);
				flush_in();/*fflush(stdin);*/
				getc(stdin);
				break;

			case '2':
				printf("\ninforme a matrícula:\n");
				scanf("%i",&reg.matricula);
				if(empilha(p,(void *)&reg)==FRACASSO)
					puts("erro na insercao");
				else
					puts("sucesso na insercao");
				flush_in();/*fflush(stdin);*/
				getc(stdin);
				break;

			case '3':
				if(desempilha(p)== FRACASSO)
					printf("\npilha vazia!\n");
				else
					printf("\n retirou da pilha\n");
				flush_in();/*fflush(stdin);*/
				getc(stdin);
				break;
		}
	} while(opc != '4');
}
