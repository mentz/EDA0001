#include "fdp.h"

int cria(FDP** pp, int tamInfo, int (*compara)(void* inf1, void* inf2))
{
    int ret = SUCESSO;
    FDP* desc = (FDP*) malloc(sizeof(FDP));
    if (desc != NULL)
    {
        desc->tamInfo = tamInfo;
        desc->cauda = NULL;
        desc->frente = NULL;
        desc->compara = compara;
    }
    else
    {
        ret = FRACASSO;
    }

    *pp = desc;

    return ret;
}

void destroi(FDP** pp)
{
    while ((*pp)->cauda != NULL)
    {
        remover((*pp));
    }

    free((*pp));
    *pp = NULL;
}

void purga(FDP* p)
{
    while (!filaVazia(p))
    {
        remover(p);
    }
}

int buscaNaFrente(FDP* p, void* dest)
{
    int ret = SUCESSO;
    if (p->frente == NULL)
        ret = FRACASSO;
    else
        memcpy(dest, p->frente->dados, p->tamInfo);

    return ret;
}

int buscaNaCauda(FDP* p, void* dest)
{
    int ret = SUCESSO;
    if (p->cauda == NULL)
        ret = FRACASSO;
    else
        memcpy(dest, p->cauda->dados, p->tamInfo);

    return ret;
}

int insere(FDP* p, void* novo)
{
    int ret = SUCESSO;
    pNoFDP new = (pNoFDP) malloc(sizeof(NoFDP)), tmp;
    if (new == NULL)
        ret = FRACASSO;
    else
    {
        new->dados = (void*) malloc(p->tamInfo);
        if (new->dados == NULL)
        {
            free(new);
            new = NULL;
            ret = FRACASSO;
        }
        else
        {
            memcpy(new->dados, novo, p->tamInfo);
            if (filaVazia(p))
            {
                new->detras = new->defronte = NULL;
                p->cauda = p->frente = new;
            }
            else
            {
                tmp = p->frente;
                int found = 0, result = -2;
                do
                {
                    result = (*(p->compara))(tmp->dados, new->dados);
                    if (result == -1)
                    {
                        if (tmp->defronte == NULL) //Caso seja o de maior prioridade
                        {
                            tmp->defronte = new;
                            new->detras = tmp;
                            new->defronte = NULL;
                            p->frente = new;
                            printf("a");
                        }
                        else
                        {
                            new->defronte = tmp->defronte;
                            new->detras = tmp;
                            tmp->defronte = new;
                            new->defronte->detras = new;
                            printf("b");
                        }
                        found = 1;
                    }
                    else
                        tmp = tmp->detras;
                } while (tmp != NULL && !found);
                if (!found)
                {
                    p->cauda->detras = new;
                    new->defronte = p->cauda;
                    new->detras = NULL;
                    p->cauda = new;
                    printf("c");
                }
            }
        }
    }

    return ret;
}

int remover(FDP* p)
{
    int ret = SUCESSO;
    if (filaVazia(p))
        ret = FRACASSO;
    else
    {
        if (p->frente == p->cauda)
        {
            free(p->frente);
            p->frente = NULL;
            p->cauda = NULL;
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

int filaVazia(FDP* p)
{
    return (p->cauda == NULL) && (p->frente == NULL);
}

void printLista(FDP* p)
{
    pNoFDP tmp;
    tmp = p->cauda;
    int d;
    printf("Vetor: ");
    while (tmp != NULL)
    {
        memcpy((void*)&d, tmp->dados, sizeof(int));
        printf("%d ", d);
        tmp = tmp->defronte;
    }
    printf("\n");
}
