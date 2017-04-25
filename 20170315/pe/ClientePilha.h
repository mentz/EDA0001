#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdlib.h>
#include "tda_pilha.h"

#ifdef  __unix__
   #define clrscr() system("clear") 
	/*printf("[2J")*/
#else
   #define clrscr() system("cls")
#endif

// ******************************************
// Nome: void flush_in
// Descrição: Função que "limpa" o teclado
// evitando problemas com a leitura de dados
// do tipo CHAR.
// Código baseado em exemplo de
// Marco Aurélio Stelmar Netto
// stelmar@pinus.cpad.pucrs.br
// ******************************************
#define flush_in() {int ch; while( (ch=fgetc(stdin)) != EOF && ch != '\n' ){}}

/* UTILIZE __fpurge(stdin) ao inves de fflush(stdin)*/ 

/*#define M 10*/

typedef struct {
	int matricula;
} info;

void menu(PE *p);

#endif
