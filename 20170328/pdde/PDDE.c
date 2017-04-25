#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "PDDE_priv.h"

/*************** CRIA ***************/
int cria(PDDE **pp, int tamInfo)
{
	int ret = FRACASSO;
	PDDE *desc = NULL; /* Descritor é alocado internamente ao TDA */

	desc = (PDDE*) malloc( sizeof(PDDE) );

	if( desc != NULL ) {
		desc->topo = NULL;
		desc->tamInfo = tamInfo;

		ret = SUCESSO;
	}

	*pp = desc; /* Busca-se o descritor através da passagem por referência */

	return ret;
}

/*************** Empilha ***************/
int insere(PDDE *p, void *novo)
{  
	int ret = FRACASSO;
	NoPDDE *temp = NULL;

	temp = (NoPDDE*) malloc( sizeof(NoPDDE) );

	if( temp != NULL ) {
		temp->dados = (void*) malloc(p->tamInfo);

		if( temp->dados != NULL ) {
			memcpy(temp->dados, novo, p->tamInfo);
			temp->abaixo = p->topo;
			temp->acima = NULL;
			if (p->topo != NULL) { // <<< caso seja a primeira inserção
				p->topo->acima = temp;
			}
			p->topo = temp;

			ret = SUCESSO;
		}
		else
			free(temp);
	}

	return ret;
}

/*************** DESEMPILHA E COPIA ITEM REMOVIDO P/ O CHAMADOR **************/
int remove_(PDDE *p, void *reg)
{  
	int ret = FRACASSO;
	NoPDDE *aux=NULL;

	if(p->topo != NULL) { 
		aux = p->topo->abaixo;
		memcpy(reg, p->topo->dados, p->tamInfo);
		free(p->topo->dados);
		free(p->topo);
		if (aux != NULL) { // caso seja a remoção do unico item
			aux->acima = NULL;
		}
		p->topo = aux;

		ret = SUCESSO;
	}

	return ret;
}

/*************** BUSCA ***************/
int busca(PDDE *p, void *reg)
{  
	int ret = FRACASSO;

	if(p->topo != NULL) { 
		memcpy(reg, p->topo->dados, p->tamInfo);

		ret = SUCESSO;
	}

	return ret;
}


int testaSeVazia(PDDE *p)
{    
	if(p->topo != NULL) {
		return NAO;
	}

	return SIM;
}


/*************** PURGA ***************/
void reinicia(PDDE *p)
{	
	if(p->topo != NULL) {

		while(p->topo->abaixo != NULL) {
			p->topo = p->topo->abaixo;
			free(p->topo->acima->dados);
			free(p->topo->acima);
		}

		free(p->topo->dados);
		free(p->topo);
		p->topo = NULL;
	}
}

/*************** DESTROI ***************/
void destroi(PDDE **pp)
{
	reinicia(*pp);
	free(*pp);
	(*pp) = NULL;
}

/*************** Retorna o tamanho da pilha ***************/
int tamanho(PDDE *p)
{ 
	NoPDDE *aux = NULL;
	int cont = 0;

	if(p->topo != NULL) { 
		aux = p->topo;

		while(aux->abaixo != NULL) {   
			cont++;
			aux = aux->abaixo;
		}

		cont++;
	}
	return cont;
}
