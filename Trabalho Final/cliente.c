#include "cliente.h"

int main(void)
{
	pABB pT = NULL;
	//FILE * tree = NULL;
	FILE * arquivo = NULL;

	// TODO: Fazer abrir árvore do arquivo, fazer salvar quando fechar
	/*
	if (!(tree = fopen("abb_head.bin", "rb")))
	{
		puts("Erro ao abrir o arquivo. Criando nova árvore.");
		if (criaABB(&pT, sizeof(info)) == SUCESSO)
		{

		}
	}
	else {

	}
	*/

	if (!(arquivo = fopen("arq.txt", "r")))
	{
		puts("Erro na leitura do arquivo \"arq.txt\".");
		return 1;
	}

	if (criaABB(&pT, sizeof(info)) == FRACASSO)
	{
		puts("Erro na criação da árvore binária.");
		return 1;
	}

	info * pInfo = NULL;
	rewind(arquivo);
	int i = 0;
	while (1)
	{
		pInfo = malloc(sizeof(info));
		pInfo->linha = i;
		fseek(arquivo, sizeof(char) * 60 * i, SEEK_SET);
		if (fscanf(arquivo, "%d", &pInfo->matricula) == EOF)
			break;
		if (insereABB(pT, pInfo, comparaChaves) == SUCESSO)
		{
			printf("%d -> %d\n", pInfo->linha, pInfo->matricula);
		}
		i++;
	}

	int op = -1;
	// menu
	while (op != 0)
	{
		puts("\n---------------------------");
		puts("Escolha uma opção:");
		puts("1 - Pesquisar por matrícula");
		puts("2 - Adicionar um cadastro");
	}

	/*
	unsigned int opc=1,i=0;
	if (criaABB(&p, sizeof(info)) == SUCESSO)
	{
		system("clear");
		i=0;
		do{ // carregando a ABB
			if(insereABB(p,&vet[i],comparaCamposChaves1)==SUCESSO)
			{
				printf("%i) inserido: %s, idade: %i anos, matricula: %i \n",
					i+1,vet[i].nome,vet[i].idade,vet[i].matricula);
				i++;
			}
			else
			{
				puts(">>> Fracasso na inserção");
				return;
			}
		} while(vet[i].idade>0);
		puts("");
		puts("tecle para continuar...");
		getchar();
		menu(p);
	}
	*/

	fclose(tree);
	fclose(arquivo);

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////
/*dados os endereços de duas instancias de registros, há a comparação dos
respectivos campos chaves e o retorno da relação entre eles: >, < ou = */
unsigned short comparaChaves(void *pInfo1, void *pInfo2)
{
	int a1 = ((info *)pInfo1)->matricula, a2 = ((info *)pInfo2)->matricula;
	if (a1 > a2)
		return '>';
	else
		if (a1 < a2)
			return '<';
		else
			return '=';
}

///////////////////////////////////////////////////////////
void exibeChave(void *pInfo)
{
	printf(" %u; ", ((info *)pInfo)->matricula);
}

//////////////////////////////////////////////////////////
void flush(FILE *in)
{
	int c;
	do
	{
		c = fgetc(in);
	} while(c != '\n' && c != EOF);
}


/////////////////////////////////////////////////////////
/*
void menu(pABB p)
{
	unsigned int opc=1;
	info aux,retorno;
	while(1)
	{
		system("clear");
		printf("\n");
		puts("0:sair		 1:inserir		  2:remover			 3:buscar  ");
		puts("4:reiniciar	5:perc. em ordem   6:perc. em pos-ordem  7:perc. em pre-ordem");
		puts("8:ABB vazia? ");
		printf("\n:>");
		scanf("%u",&opc);

		switch (opc)
		{
			case 0:
			  	destroiABB(&p);
				return;
			case 1:
			  	printf("entre com matricula: ");
				flush(stdin);
			  	scanf("%i", &(aux.campoChave));
					if (insereABB(p,&aux,comparaCamposChaves1)==SUCESSO)
			  		puts(">>> Sucesso na inserção");
			  	else
						puts(">>> Fracasso na inserção");
			  	break;
			case 2:
					printf("entre com matricula: ");

			  	scanf("%i", &aux.campoChave);
			  	if (removeABB(p,&aux.campoChave,comparaCamposChaves2,&retorno)==SUCESSO)
			  		printf(">>> Removeu: %i",retorno.campoChave);
			  	else
					puts(">>> Fracasso na remocao");
				break;
			case 3:
				printf("entre com matricula: ");

				  	scanf("%i", &aux.campoChave);
				  	if (buscaABB(p,&retorno,&aux.campoChave,comparaCamposChaves2)==SUCESSO)
					printf(">>> Buscou: %s",retorno.nome);
				else
					puts(">>> Fracasso na busca");
				break;
			case 4:
				reiniciaABB(p);
				puts(">>> ABB purgada!");
			 	break;
			case 5:
				if (emOrdem(p,exibeChave)==FRACASSO)
		 			puts(">>> ABB vazia");
				break;
			case 6:
				if (posOrdem(p,exibeChave)==FRACASSO)
					puts(">>> ABB vazia");
				break;
			case 7:
				if (preOrdem(p,exibeChave)==FRACASSO)
					puts(">>> ABB vazia");
				break;
			case 8:
				if (testaVaziaABB(p)==SIM)
					puts(">>> ABB vazia");
				else
					puts(">>> ABB nao vazia");
				break;
		}
	 	printf("\n tecle para continuar...");
		flush(stdin);
		getchar();
	}

	return;
}
*/