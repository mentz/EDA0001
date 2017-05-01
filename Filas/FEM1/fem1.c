#include "fem1.h"

int cria(FEM ** pp, int tamVet, int tamInfo)
{
    int i, ret = SUCESSO;
    FEM * desc = (FEM *) malloc(sizeof(FEM));
    if (desc == NULL)
    {
        ret = FRACASSO;
    }
    else
    {
        desc->cauda = -1;
        desc->frente = 0;
        desc->tamVet = tamVet;
        desc->tamInfo = tamInfo;
        desc->vet = (void **) malloc(sizeof(void *) * desc->tamVet);
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
                        free( desc->vet[i] );
                    free(desc->vet);
                    free(desc);
                    desc = NULL;
                    ret = FRACASSO;
                    break;
                }
            }
        }
    }

    *pp = desc;

    return ret;
}

void destroi(FEM ** pp)
{
    int i;
    for (i = 0; i < (*pp)->tamVet; i++)
        free( (*pp)->vet[i] );
    free( (*pp)->vet );
    free(*pp);
    *pp = NULL;
}

void purga(FEM * p)
{
    p->cauda = -1;
    p->frente = 0;
}

int buscaNaCauda(FEM* p, void* dest)
{
    int ret = SUCESSO;
    if (filaVazia(p) == SUCESSO)
        ret = FRACASSO;
    else
        memcpy(dest, p->vet[p->cauda], p->tamInfo);

    return ret;
}

int buscaNaFrente(FEM* p, void* dest)
{
    int ret = SUCESSO;
    if (filaVazia(p) == SUCESSO)
        ret = FRACASSO;
    else
        memcpy(dest, p->vet[p->frente], p->tamInfo);

    return ret;
}

int desenfileira(FEM* p)
{
    int i, ret = SUCESSO;
    if (filaVazia(p) == SUCESSO)
        ret = FRACASSO;
    else
    {
        for (i = 0; i < p->cauda; i++)
            memcpy(p->vet[i], p->vet[i+1], p->tamInfo);
        p->cauda--;
    }

    return ret;
}

int enfileira(FEM* p, void* novo)
{
    int ret = SUCESSO;
    if (filaCheia(p) == SUCESSO)
        ret = FRACASSO;
    else
    {
        p->cauda++;
        memcpy(p->vet[p->cauda], novo, p->tamInfo);
    }

    return ret;
}

int filaVazia(FEM* p)
{
    return p->cauda < p->frente;
}

int filaCheia(FEM* p)
{
    return p->cauda == p->tamVet-1;
}
