#include <stdio.h>
#include <stdlib.h>
#include "ClienteFILA.h"

int main(void)
{ 
	FES *ptr = NULL;

	if( cria(&ptr, 5, sizeof(info)) == SUCESSO ) {
		menu(ptr);
     	destroi(&ptr);

     	return 0;
	}
	
	return 1;
}

void menu(FES *p)
{
	char opc;
  	info reg;

	do {
		clrscr();
   		puts(" 0 busca na frente\n 1 busca na cauda\n 2 enfileira\n 3 desenfileira \n 4 sair \n\n opcao: ");
   		scanf("%c", &opc);
	 	clrscr();
		switch (opc) {
			case '0':
				if( buscaNofrente(p, (void*) &reg) == FRACASSO ) {
    	  			puts("Fila vazia!");
				}
       			else {
        			printf("\n frente: %i \n", reg.matricula);
				}
         		flush_in();/*fflush(stdin);*/
				getc(stdin);
				break;
			case '1':
				if( buscaNocauda(p, (void*) &reg) == FRACASSO ) {
    	  			puts("Fila vazia!");
				}
       			else {
        			printf("\n cauda: %i \n", reg.matricula);
				}
         		flush_in();/*fflush(stdin);*/
				getc(stdin);
				break;
     		case '2':
				printf("\ninforme a matrícula:\n");
				scanf("%i",&reg.matricula);
				if( enfileira(p, (void*) &reg) == FRACASSO ) {
					puts("erro na insercao");
				}
            	else {
               		puts("sucesso na insercao");
				}
			   	flush_in();/*fflush(stdin);*/
			   	getc(stdin);
        		break;
     		case '3':
       			 if( desenfileira(p) == FRACASSO ) {
          			printf("\nfila vazia!\n");
				 }
        		else {
					printf("\n retirou da fila\n");
				}
		  		flush_in();/*fflush(stdin);*/
		 		getc(stdin);
        		break;
		}
	} while(opc != '4');
}
