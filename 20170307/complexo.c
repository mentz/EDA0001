#include <stdio.h>
#include <stdlib.h>
#include "complexoPriv.h"

/*
--------comando p/ compilação-----------
>> gcc  -Wall -o prog *.c -lm
----------------------------------------
*/


int cria(Complexo **pp, double real, double imaginaria)
{
    Complexo *p=NULL;

    if ( (p = (Complexo*) malloc(sizeof(Complexo))) != NULL ) {
        p->a = real;
        p->b = imaginaria;
	*pp=p;
	return SUCESSO;
    }

    return FRACASSO;
}

int soma(Complexo **pp, Complexo *Z1, Complexo *Z2)
{
    double real,imag;
    Complexo *p=NULL;

    real = Z1->a + Z2->a;
    imag = Z1->b + Z2->b;

    if ( (p = (Complexo*) malloc(sizeof(Complexo))) != NULL ) {
        p->a = real;
        p->b = imag;
	*pp=p;
	return SUCESSO;
    }

    return FRACASSO;
}

int quadrado(Complexo **pp, Complexo *Z)
{
    double real, imag;
    Complexo *p=NULL;
    real = pow(Z->a, 2) + Z->b*Z->b;
    imag = 2 * Z->a * Z->b;
    if ( (p = (Complexo*) malloc(sizeof(Complexo))) != NULL ) {
        p->a = real;
        p->b = imag;
	*pp=p;
	return SUCESSO;
    }

    return FRACASSO;
}

int quociente(Complexo **pp, Complexo *Z1, Complexo *Z2)
{
    double real, imag, den;
    Complexo *p=NULL;	
    den = pow(Z1->a, 2) + pow(Z1->b, 2);
    real = (Z1->a * Z2->a + Z1->b * Z2->b) / den;
    imag = (Z1->b * Z2->a) - (Z1->a * Z2->b ) / den;
    if ( (p = (Complexo*) malloc(sizeof(Complexo))) != NULL ) {
        p->a = real;
        p->b = imag;
	*pp=p;
	return SUCESSO;
    }

    return FRACASSO;
}

void displayNumComplexo(Complexo *Z)
{
   // system("clear");
    printf("parte Real: %f, parte Imaginaria: %f\n", Z->a, Z->b);
}

void destroiNumComplexo(Complexo **pp)
{
    free(*pp);
    *pp=NULL;
}
