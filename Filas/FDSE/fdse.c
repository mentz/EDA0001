#include "fdse.h"

int cria(FDSE** pp, int tamInfo)
{
    int ret = SUCESSO;
    FDSE* desc = (FDSE*) malloc(sizeof(FDSE));
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

void destroi(FDSE** pp)
{
    while ((*pp)->cauda != NULL)
    {
        desenfileira((*pp));
    }

    free((*pp));
    *pp = NULL;
}

void purga(FDSE* p)
{
    while (p->cauda != NULL)
    {
        desenfileira(p);
    }
}

int buscaNaFrente(FDSE* p, void* dest)
{
    int ret = SUCESSO;
    if (p->frente == NULL)
        ret = FRACASSO;
    else
        memcpy(dest, p->frente->dados, p->tamInfo);

    return ret;
}

int buscaNaCauda(FDSE* p, void* dest)
{
    int ret = SUCESSO;
    if (p->cauda == NULL)
        ret = FRACASSO;
    else
        memcpy(dest, p->cauda->dados, p->tamInfo);

    return ret;
}

int enfileira(FDSE* p, void* novo)
{
    int ret = SUCESSO;
    pNoFDSE new = (pNoFDSE) malloc(sizeof(NoFDSE));
    if (new == NULL)
        ret = FRACASSO;
    else
    {
        new->atras = NULL;
        new->dados = (void*) malloc(p->tamInfo);
        memcpy(new->dados, novo, p->tamInfo);
        if (p->cauda == NULL)
            p->cauda = p->frente = new;
        else
        {
            p->cauda->atras = new;
            p->cauda = new;
        }
    }

    return ret;
}

int desenfileira(FDSE* p)
{
    int ret = SUCESSO;
    pNoFDSE tmp = NULL;
    if (p->frente == NULL)
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
            tmp = p->frente->atras;
            free(p->frente);
            p->frente = tmp;
        }
    }

    return ret;
}

int filaVazia(FDSE* p)
{
    return (p->cauda == NULL) && (p->frente == NULL);
}
