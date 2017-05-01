#include "fes.h"

int cria(FES **pp, int capMax, int tamInfo) 
{
    int i, ret = SUCESSO;
    FES * desc = (FES*) malloc(sizeof(FES));
    if (desc != NULL)
    {
        desc->frente = 0;
        desc->cauda = -1;
        desc->tamInfo = tamInfo;
        desc->tamVet = capMax;
        desc->vet = NULL;
        desc->vet = (void **) malloc(sizeof(void*) * capMax);
        if (desc->vet != NULL)
        {
            for (i = 0; i < capMax; i++)
            {
                desc->vet[i] = (void*) malloc(tamInfo);
                if (desc->vet[i] == NULL)
                {
                    for (--i; i >= 0; i--)
                        free(desc->vet[i]);
                    free(desc->vet);
                    free(desc);
                    desc = NULL;
                    ret = FRACASSO;
                    break;
                }
            }
        }
        else
        {
            free(desc);
            desc = NULL;
            ret = FRACASSO;
        }
    }
    else
    {
        desc = NULL;
        ret = FRACASSO;
    }

    *pp = desc;

    return ret;
}

void destroi(FES **pp)
{
    int i;
    for (i = 0; i < (*pp)->tamVet; i++)
    {
        free( (*pp)->vet[i] );
    }
    free( (*pp)->vet );
    free(*pp);
    *pp = NULL;
}

void purga(FES *p)
{
    p->cauda = -1;
    p->frente = 0;
}

int buscaNaCauda(FES *p, void * pReg)
{
    int ret = SUCESSO;
    if (filaVazia(p) == SUCESSO)
    {
        ret = FRACASSO;
    }
    else
    {
        memcpy(pReg, p->vet[p->cauda], p->tamInfo);
    }

    return ret;
}

int buscaNaFrente(FES *p, void * pReg)
{
    int ret = SUCESSO;
    if (filaVazia(p) == SUCESSO)
    {
        ret = FRACASSO;
    }
    else
    {
        memcpy(pReg, p->vet[p->frente], p->tamInfo);
    }

    return ret;
}

int desenfileira(FES *p)
{
    int ret = SUCESSO;
    if (filaVazia(p))
    {
        ret = FRACASSO;
    }
    else
    {
        p->frente++;
    }

    return ret;
}

int enfileira(FES *p, void * novo)
{
    int ret = SUCESSO;
    if (filaCheia(p) == SUCESSO)
    {
        ret = FRACASSO;
    }
    else
    {
        memcpy(p->vet[++p->cauda], novo, p->tamInfo);
    }

    return ret;
}

int filaVazia(FES *p)
{
    int ret;
    if (p->cauda < p->frente)
        ret = SUCESSO;
    else
        ret = FRACASSO;

    return ret;
}

int filaCheia(FES *p)
{
    int ret;
    if (p->cauda == p->tamVet - 1)
        ret = SUCESSO;
    else
        ret = FRACASSO;

    return ret;
}
