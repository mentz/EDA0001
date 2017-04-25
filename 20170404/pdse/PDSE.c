#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "PDSE_priv.h"

/*************** CRIA ***************/
int cria(PDSE **pp, int tamInfo)
{
	int ret = FRACASSO;
	PDSE* desc = NULL; /* Aloca o descritor dentro do TDA */

	desc = (PDSE*) malloc( sizeof(PDSE) );

	if( desc != NULL ) {
		desc->topo = NULL;	
		desc->tamInfo = tamInfo;
		ret = SUCESSO;
	}

	*pp = desc; /* Retorna o descritor ao cliente da aplicação */

	return ret;
}

/*************** INSERE ***************/
int insere(PDSE *p, void *novo)
{  
	int ret = FRACASSO;
	NoPDSE *temp;

	temp = (NoPDSE*) malloc( sizeof(NoPDSE) );

	if( temp != NULL) { 
		temp->dados = (void*) malloc( p->tamInfo );

		if( temp->dados != NULL ) {
			memcpy(temp->dados, novo, p->tamInfo);
			temp->abaixo = p->topo;
			p->topo = temp;

			ret = SUCESSO;
		}
		else {
			free(temp);
		}
	}

	return ret;
}

/*************** REMOVE E COPIA ITEM REMOVIDO P/ O CHAMADOR **************/
int remove_(PDSE *p, void *reg)
{  
	int ret = FRACASSO;
	NoPDSE *aux = NULL;

	if(p->topo != NULL) { 
		aux = p->topo->abaixo;
		memcpy(reg, p->topo->dados, p->tamInfo);
		free(p->topo->dados);
		free(p->topo);
		p->topo = aux;

		ret = SUCESSO;
	}

	return ret;
}

/*************** BUSCA ***************/
int busca(PDSE *p, void *reg)
{  
	int ret = FRACASSO;

	if(p->topo != NULL) { 
		memcpy(reg,p->topo->dados,p->tamInfo);
		ret = SUCESSO;
	}

	return ret;
}

int testaSeVazia(PDSE *p)
{    
	if(p->topo != NULL) {
		return NAO;
	}
	
	return SIM;
}


/*************** PURGA ***************/
void reinicia(PDSE *p)
{	
	NoPDSE *aux = NULL;

	if(p->topo != NULL) {	
		aux = p->topo->abaixo;

		while(aux != NULL) {
			free(p->topo->dados);
			free(p->topo);
			p->topo = aux;
			aux = p->topo->abaixo;
		}
		free(p->topo->dados);
		free(p->topo);
		p->topo = NULL;
	}

}

/*************** DESTROI ***************/
void destroi(PDSE **pp)
{
	reinicia(*pp);
	free(*pp);
	(*pp) = NULL;
}

