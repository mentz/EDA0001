#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ClienteFDDE.h"


void pause_(void);

int main()
{
	FDDE* ptr = NULL;  /*MANTENHA PTR COMO REFERNCIA PARA O (INICIO DO) TDA. */
	/*poderia até fornecer o tamanho do tipo !!!! nesse caso o odefine seria interno a cliente .c*/
	if( cria(&ptr, sizeof(info)) == FRACASSO ) {
		puts("erro fatal durante a criação do tda");
		pause_();
	}
	else { 
		clrscr();
		menu(ptr);
	}

	return 1;
}

void menu(FDDE* p)
{  
	char opc;
	info auxInfo;

	do { 
		fflush(stdin);
		puts("FILA");
		puts(" entre com uma opcao 1 (busca na frente), 2 (enfileira),");
   		puts("                      3 (remove da fila),4 (busca na cauda), 5 purga, 6 vaivem");
   		puts("                      0 (\"zero\") para encerrar");
   		printf("\n");
		opc = getchar();
		clrscr();
		switch (opc) { 
			case '1':
				if( buscaNaFrente(p,&auxInfo) == FRACASSO ) {
					puts("fila vazia!");
				}
				else {
					printf("\n consultado : %i \n", auxInfo.chave);
				}
				break;
			case '2':
				printf("\nentre com o RG:\n");
            	fflush(stdin);
            	scanf("%i", &auxInfo.chave);
            	if(	insere(p, &auxInfo) == FRACASSO ) {
					puts("erro na insercao: estrutura de dados cheia !");
				}
              	break;
			case '3':
				if( retira(p, &auxInfo) == FRACASSO ) {
					puts("fila vazia!");
				}
				else {
					printf("\n item retirado : %i \n", auxInfo.chave);
				}
				break;
			case '4':
				if( buscaNaCauda(p, &auxInfo) == FRACASSO ) {
            	   puts("fila vazia!");
				}
            	else {
            	   printf("\n consultado : %i \n", auxInfo.chave);
				}
				break;
			case '5':
				purga(p);
				puts("limpou a fila !!!");
				break;
			case '6':
				vaivem(p, exibe);
				break;
		}
		pause_();
	} while(opc != '0');
}

void pause_(void)
{
	char ch='\0';

	do { 
		fflush(stdin);
		scanf("%c",&ch);
	} while (ch =='\0');
}

void exibe(void *a)
{   
	printf("\n");
	printf("chave %i \n ",((info*)a)->chave); /* (((info*)a)->chave > ((info*)b)->chave) */
}
