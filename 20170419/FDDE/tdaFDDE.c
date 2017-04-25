#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tdaFDDE_priv.h"

#ifdef debugging
    int aux;
#endif

int cria(FDDE** pp, int tamInfo)
{
	int ret = FRACASSO;
	FDDE* desc = (FDDE*) malloc( sizeof(FDDE) );

	if( desc != NULL ) {
		desc->frente = NULL;
		desc->cauda = NULL;
		desc->tamInfo = tamInfo;
		ret = SUCESSO;
	}

	*pp = desc;

	return ret;
}

int testaVazia(FDDE* p)
{ 
	if( p->frente == NULL && p->cauda == NULL )
		return SIM;

	return NAO;
}

int insere(FDDE* p, void *novo)
{
	NoFila *temp;

	temp = (NoFila*) malloc( sizeof(NoFila) );
	if( temp == NULL ) {
		return FRACASSO;
	}
	else {
		temp->dados = (void*) malloc(p->tamInfo);
		if( temp->dados == NULL ) {
			free(temp);
			return FRACASSO;
		}
		else { 
			memcpy(temp->dados, novo, p->tamInfo);

			if(p->frente == NULL) { /*vazia*/
				temp->atras = temp->defronte = NULL;
    		    p->frente = p->cauda = temp;
    		}
    		else {  
				p->cauda->atras = temp;
				temp->defronte = p->cauda;
    		   	p->cauda = temp;
    		   	temp->atras = NULL;
    		}
        }
	}

	return SUCESSO;
}

int buscaNaFrente(FDDE* p, void *pReg)
{ 
	if( p->frente == NULL ) {
  		return FRACASSO;
	}

	memcpy(pReg, p->frente->dados, p->tamInfo);

	return SUCESSO;
}

int buscaNaCauda(FDDE* p, void *pReg)
{ 
	if( p->frente == NULL ) {
  		return FRACASSO;
	}

	memcpy(pReg,p->cauda->dados, p->tamInfo);

	return SUCESSO;
}

int retira(FDDE* p, void *pReg)
{
	if( p->frente == NULL ) {
		return FRACASSO;
	}

	memcpy(pReg,p->frente->dados, p->tamInfo);

	if( p->frente == p->cauda ) { /* um único elemento inserido */
		free(p->frente->dados);
		free(p->frente);
		p->frente = NULL;
		p->cauda = NULL;
	}
	else {  	
		p->frente = p->frente->atras;
		free(p->frente->defronte->dados);
		free(p->frente->defronte);
		p->frente->defronte = NULL;
    }

	return SUCESSO;
}

int purga(FDDE* p)
{   
	int ret;

    if( p->frente == NULL ) {
		ret = FRACASSO;
	}
    else {   
		while( p->frente->atras != NULL ) {   
			p->frente = p->frente->atras;
			free(p->frente->defronte->dados);
			free(p->frente->defronte);
        }

        free(p->frente->dados);
        free(p->frente);
		p->frente = NULL;
		p->cauda = NULL;
        ret= SUCESSO;
    }

    return ret;
}

void destroi(FDDE** pp)
{ 
	purga(*pp);
	free(*pp);
	*pp = NULL;
}

void vaivem(FDDE* p, void (*  func)(void* x) )
{ 
	NoFila* aux = NULL;

	if( testaVazia(p) == SIM ) {
		return;
	}
	
	aux = p->frente;
    while( aux ) {
		func(aux->dados);
		aux = aux->atras;
    }

    aux = p->cauda;
    while( aux ) { 
		func(aux->dados);
		aux=aux->defronte;
	}
}
