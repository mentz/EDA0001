#include "fec.h"

int cria(FEC** pp, int tamVet, int tamInfo)
{
    int i, ret = SUCESSO;
    FEC* desc = (FEC*) malloc(sizeof(FEC));
    if (desc == NULL)
    {
        ret = FRACASSO;
    }
    else
    {
        desc->tamFila = 0;
        desc->cauda = -1;
        desc->frente = 0;
        desc->tamVet = tamVet;
        desc->tamInfo = tamInfo;
        desc->vet = (void**) malloc(sizeof(void*) * desc->tamVet);
        if (desc->vet == NULL)
        {
            free(desc);
            desc = NULL;
            ret = FRACASSO;
        }
        else
        {
            for (i = 0; i < desc->tamVet; i++)
            {
                desc->vet[i] = (void*) malloc(desc->tamInfo);
                if (desc->vet[i] == NULL)
                {
                    for (--i; i >= 0; i--)
                        free(desc->vet[i]);
                    free(desc->vet);
                    free(desc);
                    desc = NULL;
                    ret = FRACASSO;
                }
            }
        }
    }

    *pp = desc;

    return ret;
}

void destroi(FEC** pp)
{
    int i;
    for (i = 0; i < (*pp)->tamVet; i++)
        free( (*pp)->vet[i] );
    free( (*pp)->vet );
    free((*pp));
    *pp = NULL;
}

void purga(FEC* p)
{
    p->tamFila = 0;
    p->frente = 0;
    p->cauda = -1;
}

int buscaNaFrente(FEC* p, void* dest)
{
    int ret = SUCESSO;
    if (filaVazia(p) != SUCESSO)
        memcpy(dest, p->vet[p->frente], p->tamInfo);
    else
        ret = FRACASSO;

    return ret;
}

int buscaNaCauda(FEC* p, void* dest)
{
    int ret = SUCESSO;
    if (filaVazia(p) != SUCESSO)
        memcpy(dest, p->vet[p->cauda], p->tamInfo);
    else
        ret = FRACASSO;

    return ret;
}

int enfileira(FEC* p, void* novo)
{
    int ret = SUCESSO;
    if (filaCheia(p) != SUCESSO)
    {
        p->cauda = (p->cauda + 1) % p->tamVet;
        memcpy(p->vet[p->cauda], novo, p->tamInfo);
        p->tamFila++;
    }
    else
        ret = FRACASSO;

    return ret;
}

int desenfileira(FEC* p)
{
    int ret = SUCESSO;
    if (filaVazia(p) != SUCESSO)
    {
        p->frente = (p->frente + 1) % p->tamVet;
        p->tamFila--;
    }
    else
        ret = FRACASSO;

    return ret;
}

int filaCheia(FEC* p)
{
    return p->tamFila == p->tamVet;
}

int filaVazia(FEC* p)
{
    return p->tamFila == 0;
}
