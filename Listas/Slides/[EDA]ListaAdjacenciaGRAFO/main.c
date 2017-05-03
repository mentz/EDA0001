/***********************************************
*-------------ESTRUTURA DE DADOS---------------*
*Representação de um grafo através de          *
*Lista de Adjacência (Lista de Listas)         *
*para compilar: gcc -Wall -o main main.c LDSE.c*
*Aurelio Grott Neto                            *
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDSE.h"

void mostra_inteiro(void *info);

void listaAdjacente();

int main()
{
    int opcao;

    do
    {
        printf("> EDA\n");
        printf("1. Lista de Adjacencia de um grafo.\n"
               "0. Sair.\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            listaAdjacente();
            break;
        default:
            break;
        }
    } while(opcao != 0);

    return 0;
}

void listaAdjacente()
{
    char buffer[200];
    int temp, vertAtual, offset;
    int nVertices = 0;
    int i;
    pLDSE pListaAdjacente;
    cria(&pListaAdjacente, sizeof(ppLDSE));
    FILE *arquivo = fopen("grafo.txt", "r"); // ABre o grafo
    if(arquivo == NULL) // Se falhou abrir o arquivo
    {
        printf("Erro ao abrir arquivo!");
    }
    else
    {
        while( !feof(arquivo)) // Enquanto nao chegar no final do arquivo
        {
            nVertices++;
            pLDSE pL;
            cria(&pL, sizeof(int));
            fscanf(arquivo, "%d: ", &vertAtual); // Ler o vertice a ser analisado. Numero antes do ":" no arquivo
            fgets(buffer, sizeof(buffer), arquivo); // Le os numeros apos o vertice ao ser analisado e guarda na string
            sscanf(buffer, "%d", &temp);

            char *pBuffer = buffer; // Ponteiro para o buffer, para poder mover o ponteiro na hora de converter para inteiros
            while (sscanf(pBuffer, " %d%n", &temp, &offset) == 1) // Le numero por numero ate chegar ao final da linha
            {
                pBuffer += offset; // Aponta o ponteiro para o proximo numero
                insereNoFim(pL, &temp);
            }
            insereNoFim(pListaAdjacente, &pL);//insere na lista "principal" a sub-lista, que são os vertices "filhos"
        }
    }
    for (i = 0; i < nVertices-1; i++)
    {
        pLDSE pL=NULL;
        buscaNaPosLog(pListaAdjacente, &pL, i+1);
        printf("%d: ", i);
        mostra_lista(pL, mostra_inteiro);
        printf("-\n");
    }
}
void mostra_inteiro(void *info)
{
    int *n = (int*) info;
    printf("%d -> ", *n);
}
