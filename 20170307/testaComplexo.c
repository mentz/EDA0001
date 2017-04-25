
#include "complexo.h" 

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

int main()
{ 	
	Complexo *pZ1 = NULL, *pZ2 = NULL, *pZ3 = NULL;
	double w = 5,k = 9;

    	if (cria(&pZ1, w, k) == SUCESSO)
	{

    		//pZ1->a; /* remova  comentario e compile para testar o encapsulamento dos dados 				privativos do TDA numero complexo */
		printf("Z1:");
  	    	displayNumComplexo(pZ1);

    		quadrado(&pZ2,pZ1);
		printf("Z2=Z1*Z1\n");	
		printf("Z2:");
	    	displayNumComplexo(pZ2);
 
    		soma(&pZ3,pZ1,pZ2);	
		printf("Z3=Z1+Z2\n");
		printf("Z3:");
	    	displayNumComplexo(pZ3);

	    	getc(stdin);
	    	destroiNumComplexo(&pZ1);
		return 1;	
	}
	else
		return FRACASSO;
}
