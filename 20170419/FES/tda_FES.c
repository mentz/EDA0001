#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tdaFESPriv.h"

int cria(FES **pp, int capMax, int tamInfo)
{
	int i, ret = SUCESSO;
	FES *desc = (FES*) malloc( sizeof(FES) ); /* Descritor é criado internamente */

	if( desc != NULL ) { /* Verifica se o descritor foi devidamente alocado */
		desc->vet = (void**) malloc( sizeof(void*) * capMax );

		if( desc->vet != NULL ) { /* Verifica se o vetor foi alocado com sucesso */
			desc->tamVet = capMax;
			desc->tamInfo = tamInfo;
			desc->cauda = -1;
			desc->frente = 0;
			for(i=0; i < capMax; i++) { /* Aloca cada posição do vetor. Em caso de falha, desaloca tudo */
				desc->vet[i] = (void*) malloc( tamInfo );
				if( desc->vet[i] == NULL ) {
					for(--i; i >= 0; i--) {
						free(desc->vet[i]);
					}
					free(desc->vet);
					free(desc);
					desc = NULL;
					ret = FRACASSO;
					break;
				}
			}
		}
		else {
			free(desc);
			desc = NULL;
			ret = FRACASSO;
		}
	}
	else {
		desc = NULL;
		ret = FRACASSO;
	}

	*pp = desc; /* Ponteiro recebe o descritor devidamente alocado (ou NULL em caso de erro) */

	return ret;
}
	
/*-------------------------------------------------------------------------------*/
void destroi(FES **pp)
{
	int i;

	for(i=0; i < (*pp)->tamVet; i++) {  /*libera memória que inicializa os ponteiros void*/
		free( (*pp)->vet[i]);           /* equivalente a: *(p->vet + i));*/
	}
	free((*pp)->vet);
	free(*pp);
	*pp = NULL;
}


/*-------------------------------------------------------------------------------*/
void purga(FES *p)
{
	p->cauda = -1;
	p->frente = 0;
}
/*-----------------------------------------------------------------------------*/
int buscaNocauda(FES *p, void *pReg) 
{
	int ret;

	if( p->cauda < p->frente ) { /* acesso direto ao cauda */
		ret = FRACASSO;
	}
	else {
		memcpy(pReg, (p->vet[p->cauda]), p->tamInfo); /* equivalente a: memcpy(pReg,*(p->vet+p->cauda), p->tamInfo); */
		ret = SUCESSO;
	}
	
	return ret;
}

/*-----------------------------------------------------------------------------*/
int buscaNofrente(FES *p, void *pReg) 
{
	int ret;

	if (p->cauda < p->frente) { /* acesso direto ao cauda */
		ret = FRACASSO;
	}
 	else {
		memcpy(pReg, (p->vet[p->frente]), p->tamInfo); /* equivalente a: memcpy(pReg,*(p->vet+p->cauda), p->tamInfo); */
		ret = SUCESSO;
 	}

 	return ret;
}
/*------------ATENÇÃO: pelo conceito de transação atômica
desenfileira #apenas# decrementaria o cauda ---------------------*/
int desenfileira(FES *p)
{ 
	int ret;

	if (p->cauda < p->frente) {
		ret = FRACASSO;
	}
	else {  
		p->frente++;
		ret = SUCESSO;
	}

	return ret;
}

/*------------------------------------------------------------------------------*/
int enfileira(FES *p, void *novo)
{ 
	int ret = FRACASSO;

	if (p->cauda < p->tamVet-1) {
		p->cauda++;

        /*cópia um bloco de tamanho definido deste o endereço novo até o endereço
		 * definido por *(p->vet+p->cauda) 
		 */
		memcpy(*(p->vet+p->cauda), novo, p->tamInfo); /* equivalente a: memcpy(p->vet[p->cauda],novo,p->taminfo);*/
		
		ret = SUCESSO;
    }
		
	return ret;
}


/*--------------------------------------------------------------------------------*/
int testaVazia(FES *p) 
{
	int ret;

	if (p->cauda < p->frente) { /* acesso direto ao cauda */
		ret = SIM;
	}
    else {
		ret = NAO;
	} 

    return ret;
}

/*---------------------------------------------------------------------------------*/
int testaCheia(FES *p) 
{
	int ret;

  	if( p->cauda >= p->tamVet-1 ) { /* acesso direto ao cauda */
		ret = SIM;
	}
  	else {
		ret = NAO;
	}

	return ret;
}
