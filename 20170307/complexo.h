#ifndef COMPLEXO_H
#define COMPLEXO_H

#define SUCESSO 1
#define FRACASSO 0
#include <stdio.h>
#include <math.h>
/* especificação parcial do modelo de dados */
typedef struct NumComplexo Complexo;  /*<<<<< importante */

/* protótipos das operações sobre o TDA – sem as pré ou pós-condições */

/* Construtora
pré-condições...
pós-condições...
*/
int cria(Complexo **pp, double real, double imaginaria);

/* Soma dois num. complexos
pré-condições...
pós-condições...
*/
int soma(Complexo **pp,Complexo *Z1, Complexo *Z2);

/* Num. complexo elevado ao quadrado
pré-condições...
pós-condições...
*/
int quadrado(Complexo **pp, Complexo *Z);

/* Divisão de dois num. complexos
pré-condições...
pós-condições...
*/
int quociente(Complexo **pp, Complexo *Z1, Complexo *Z2);

/* Exibição de num. complexo
pré-condições...
pós-condições...
*/
void displayNumComplexo(Complexo *Z);

/* Destrutora
pré-condições...
pós-condições...
*/
void destroiNumComplexo(Complexo **pp);


#endif
