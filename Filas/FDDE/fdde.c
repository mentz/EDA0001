#include "fdde.h"

int cria(FDDE** pp, int tamInfo)
{
    int ret = SUCESSO;
    FDDE* desc = (FDDE*) malloc(sizeof(FDDE));
    if (desc != NULL)
    {
        desc->tamInfo = tamInfo;
        desc->cauda = NULL;
        desc->frente = NULL;
    }
    else
    {
        ret = FRACASSO;
    }

    *pp = desc;

    return ret;
}

void destroi(FDDE** pp)
{
    while ((*pp)->cauda != NULL)
    {
        desenfileira((*pp));
    }

    free((*pp));
    *pp = NULL;
}

void purga(FDDE* p)
{
    while (p->cauda != NULL)
    {
        desenfileira(p);
    }
}

int buscaNaFrente(FDDE* p, void* dest)
{
    int ret = SUCESSO;
    if (p->frente == NULL)
        ret = FRACASSO;
    else
        memcpy(dest, p->frente->dados, p->tamInfo);

    return ret;
}

int buscaNaCauda(FDDE* p, void* dest)
{
    int ret = SUCESSO;
    if (p->cauda == NULL)
        ret = FRACASSO;
    else
        memcpy(dest, p->cauda->dados, p->tamInfo);

    return ret;
}

int enfileira(FDDE* p, void* novo)
{
    int ret = SUCESSO;
    pNoFDDE new = (pNoFDDE) malloc(sizeof(NoFDDE));
    if (new == NULL)
        ret = FRACASSO;
    else
    {
        new->detras = NULL;
        new->defronte = p->cauda;
        new->dados = (void*) malloc(p->tamInfo);
        memcpy(new->dados, novo, p->tamInfo);
        if (filaVazia(p))
            p->cauda = p->frente = new;
        else
        {
            p->cauda->detras = new;
            p->cauda = new;
        }
    }

    return ret;
}

int desenfileira(FDDE* p)
{
    int ret = SUCESSO;
    if (filaVazia(p))
        ret = FRACASSO;
    else
    {
        if (p->frente == p->cauda)
        {
            free(p->frente);
            p->frente = p->cauda = NULL;
        }
        else
        {
            p->frente = p->frente->detras;
            free(p->frente->defronte);
            p->frente->defronte = NULL;
        }
    }

    return ret;
}

int filaVazia(FDDE* p)
{
    return (p->cauda == NULL) && (p->frente == NULL);
}
