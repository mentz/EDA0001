#ifndef FDSE_H
#define FDSE_H

#define FRACASSO 0
#define SUCESSO 1
#define SIM 1
#define NAO 0

typedef struct FDSE FDSE;

int cria(FDSE **pp, int tamInfo);
int insere(FDSE *p, void *novo);
int tamanho(FDSE *p);
void reinicia(FDSE *p);
void destroi(FDSE **pp);
int buscaNaCauda(FDSE *p, void *reg);
int buscaNaFrente(FDSE *p, void *reg);
int remove_(FDSE *p, void *reg);
int testaVazia(FDSE *p);
int inverte(FDSE *p);

#endif
