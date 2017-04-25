// 1.i:
p->topo = q; // apontando o ponteiro de topo da pilha para o endereço q
q->dados = r; // apontando o ponteiro de dados para o endereço r
p->topo->dados = r; // essa linha funciona do mesmo modo que a anterior

// 1.ii:
p->topo = q;
p->topo->dados = r; // ou:  q->dados = r;
p->topo->abaixo = p->topo; // ou:  q->abaixo = q;

// 2.1:
q->dir = p;
q->esq = p->esq;
q->esq->dir = q;
p->esq = q;

// 2.2:
p->esq->dir->dir = p;
p->esq->dir->esq = p->esq;
p->esq = p->esq->dir;

// 3:


// 4:
b = p->vet[p->topo];
c = p->tamInfo;

// 5:
int buscaNaBase(Pilha *p, void *pReg)   // considerando uma Pilha Estática
{
    if (p->topo != -1)
    {
        memcpy(pReg, p->vet[0], p->tamInfo);
        return SUCESSO;
    }
    return FRACASSO;
}

// 6:


// 7:
