// 1.i:
p->topo = q; // apontando o ponteiro de topo da pilha para o endereço q
q->dados = r; // apontando o ponteiro de dados para o endereço r
p->topo->dados = r; // essa linha funciona do mesmo modo que a anterior

// 1.ii:
p->topo = q;
p->topo->dados = r; // ou:  q->dados = r;
p->topo->abaixo = p->topo; // ou:  q->abaixo = q;

// 2:
q->dir = p;
q->esq = p->esq;
q->esq->dir = q;
p->esq = q;
