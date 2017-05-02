#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int main()
{ 
    FDSE *ptr = NULL;
    if( cria(&ptr, sizeof(info)) == SUCESSO ) {     
        menu(ptr);
        destroi(&ptr);
        return 1;
    }

    return 0;
}

void menu(FDSE *p)
{
    unsigned int opc;
    info *reg, x;
    reg = &x;

    do { 
        system("clear");
        puts("\n 1 insere \n 2 busca na frente \n 3 busca na cauda \n 4 remove");
        puts("\n 5 reinicia a fila  \n 6 tamanho \n 0 sair");

        printf("\n:> ");
        scanf("%ui", &opc);

        flush(stdin);
        switch (opc) {	 
            case 1:
                printf("\ninforme a matrícula: ");

                scanf("%i",&reg->matricula);
                if(insere(p, reg) == FRACASSO)
                    puts("erro na insercao");
                else
                    puts("sucesso na insercao");
                break;

            case 2:
                if(buscaNaFrente(p, reg) == FRACASSO)
                    puts("fila vazia");
                else
                    printf("\nconteudo na frente = %i", reg->matricula);
                break;
            case 3:
                if(buscaNaCauda(p, reg) == FRACASSO)
                    puts("fila vazia");
                else
                    printf("\nconteudo na cauda = %i", reg->matricula);
                break;
            case 4:
                if(remove_(p, reg) == FRACASSO)
                    puts("fila vazia");
                else
                    printf("removido: %i", reg->matricula);
                break;
            case 5:
                reinicia(p);
                printf("fila reiniciada");
                break;
            case 6:
                printf("tamanho: %i", tamanho(p));
                break;
            case 0:
                puts("fim");
                break;
            default:
                puts("informe uma opcao correta");
        }

        flush(stdin);
    } while(opc != 0);
}


void flush(FILE *in)
{ 
    int c;

    do { 
        c = fgetc(in);
    } while(c != '\n' && c != EOF);
}
