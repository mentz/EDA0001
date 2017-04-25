#include <stdio.h>
#include <stdlib.h>
#include "MPE.h"

#ifdef  __unix__
   #define clrscr() system("clear")
#else
   #define clrscr() system("cls")
#endif

int main(void)
{ 
    MP *ptr = NULL; 
    int nPilha, lPilha;
    
    printf(">Digite o numero de pilhas da MPE:\n");
    scanf("%d", &nPilha);
    printf(">Digite o tamanho das pilhas da MPE:\n");
    scanf("%d", &lPilha);
    clrscr();
    
    if( cria(&ptr, nPilha, lPilha, sizeof(int)) == SUCESSO ) {
        printf(">>criadas %d pilhas de int de tamanho %d\n", nPilha, lPilha);
	}
    else {
        return 1;
	}

    getchar();
    clrscr();
    
    int opc, novo, consultado, removido;
    
    do {
        printf("1. inserir matricula\n2. remover matricula\n3. consultar topo\n0. sair\n\n> ");
        scanf("%d", &opc);
        
        switch(opc){
			
            clrscr();

            case 1:
                printf("\nDigite a pilha para insercao:\n> ");
                scanf("%d", &nPilha);
                printf("\nDigite a matricula:\n> ");
                scanf("%d", &novo);
                if( insereNaPilha(ptr, nPilha, &novo) == SUCESSO ) {
                    printf("\nsucesso na insercao!\n");
				}
                getchar(); getchar();
                clrscr();
                break;
            case 2:
                printf("\nDigite a pilha para remocao:\n> ");
                scanf("%d", &nPilha);
                if( removeDaPilha(ptr, nPilha, &removido) == SUCESSO ) {
                    printf("\nELEMENTO REMOVIDO:\n-------------------\n%d\n-------------------\n", removido);
                    printf("\nsucesso na remocao!\n");
                }
                getchar(); getchar();
                clrscr();
                break;
            case 3:
                printf("\nDigite a pilha para consulta:\n> ");
                scanf("%d", &nPilha);
                if( consultaTopo(ptr, nPilha, &consultado) == SUCESSO ) {
                    printf("\nTOPO ATUAL:\n-------------------\n%d\n-------------------\n", consultado);
                    printf("\nsucesso na consulta!\n");
                }
                getchar(); getchar();
                clrscr();
                break;
            case 0:
                destroi(&ptr);
                break;
        }
    } while(opc!=0);
    
    return 0;
}


