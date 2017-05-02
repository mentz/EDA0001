#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "FDSE_priv.h"

// gcc -c -Wall -O2 FDSE.c
// ar rvs FDSE.a FDSE.o
// gcc -o aplica.exe cliente.c FDSE.a

/*************** CRIA ***************/
int cria(FDSE **pp, int tamInfo)
{   	
    int ret = FRACASSO;
    FDSE *desc = (FDSE*) malloc(sizeof(FDSE));

    if(desc != NULL) {
        desc->cauda = NULL;
        desc->frente = NULL;
        desc->tamInfo = tamInfo;
        ret = SUCESSO;
    }

    *pp = desc;

    return ret;
}

/*************** INSERE NA CAUDA ***************/
int insere(FDSE *p, void *novo)
{  	
    NoFDSE *temp;
    int ret = FRACASSO;

    if( (temp = (NoFDSE*) malloc(sizeof(NoFDSE))) != NULL ) { 
        if( (temp->dados = (void *) malloc(p->tamInfo)) != NULL ) {   
            memcpy(temp->dados, novo, p->tamInfo);
            temp->atras = NULL;
            if(p->cauda == NULL && p->frente == NULL) {	
                p->cauda = temp;
                p->frente = temp;
            }
            else {	
                p->cauda->atras = temp;
                p->cauda = temp;
            }
            ret = SUCESSO;
        }
        else {
            free(temp);
        }
    }

    return ret;
}

/*************** REMOVE DA FRENTE ***************/
int remove_(FDSE *p, void *reg)
{  	
    int ret = FRACASSO;
    NoFDSE *aux = NULL;

    if(p->cauda != NULL && p->frente != NULL)
    {  	
        aux = p->frente->atras;
        memcpy(reg, p->frente->dados, p->tamInfo);
        free(p->frente->dados);
        free(p->frente);
        p->frente = aux;
        if(aux == NULL) { // existia apenas um elemento inserido?
            p->cauda = aux;
        }
        ret = SUCESSO;
    }

    return ret;
}

/*************** BUSCA NA FRENTE ***************/
int buscaNaFrente(FDSE *p, void *reg)
{  
    int ret = FRACASSO;

    if(p->frente != NULL && p->cauda != NULL) { 	
        memcpy(reg, p->frente->dados, p->tamInfo);
        ret = SUCESSO;
    }

    return ret;
}

/*************** BUSCA NA CAUDA ***************/
int buscaNaCauda(FDSE *p, void *reg)
{
    int ret = FRACASSO;

    if(p->cauda != NULL && p->frente != NULL) {
        memcpy(reg, p->cauda->dados, p->tamInfo);
        ret = SUCESSO;
    }

    return ret;
}

/*************** VAZIA? ***************/
int testaVazia(FDSE *p)
{
    if(p->frente == NULL && p->cauda == NULL) {
        return SIM;
    }

    return NAO;
}

/*************** TAMANHO ***************/
int tamanho(FDSE *p)
{ 
    int tam = 0;
    NoFDSE *aux = p->frente;

    if(aux == NULL) {
        tam = 0;
    }

    else { 
        while(aux != NULL) { 	
            aux = aux->atras;
            tam++;
        }
    }

    return tam;
}

/*************** PURGA ***************/
void reinicia(FDSE *p)
{ 
    NoFDSE *aux;

    if(p->frente != NULL && p->cauda != NULL) {  
        aux = p->frente->atras;
        while(aux != NULL) {
            free(p->frente->dados);
            free(p->frente);
            p->frente = aux;
            aux = aux->atras;
        }
        free(p->frente->dados);
        free(p->frente);
        p->frente = NULL;
        p->cauda = NULL;
    }
}

/*************** DESTROI ***************/
void destroi(FDSE **pp)
{
    NoFDSE *aux0;
    FDSE *aux1 = *pp;

    if(aux1->frente != NULL && aux1->cauda != NULL) {   
        aux0 = aux1->frente->atras;
        while(aux0 != NULL) {
            free(aux1->frente->dados);
            free(aux1->frente);
            aux1->frente = aux0;
            aux0 = aux0->atras;
        }
        free(aux1->frente->dados);
        free(aux1->frente);
        aux1->frente = NULL;
        aux1->cauda = NULL;
    }
    free(aux1);
    *pp = NULL; // aterra o ponteiro externo, declarado na aplicação
}
