#include "cliente.h"

int main(int argc, char * argv[])
{
	pABB pT = NULL;
	FILE * tree = NULL;
	FILE * arquivo = NULL;
	info * pInfo = malloc(sizeof(info));

	// Criação da ABB
	if (criaABB(&pT, sizeof(info)) != SUCESSO)
	{
		puts("Erro ao criar árvore.");
		return 1;
	}

	if (!(tree = fopen("abb_index.bin", "rb")))
	{
		// Se abb_index.bin não existe, criar nova ABB usando a base de dados arq.txt
		if (!(arquivo = fopen("arq.txt", "r")))
		{
			puts("Erro na leitura do arquivo \"arq.txt\".");
			return 1;
		}
		// Carregar a ABB lendo o arquivo de matrículas, deve acontecer só na primeira execução e nas remoções.
		if (constroiArvoreIndices(pT, &arquivo) != SUCESSO)
		{
			puts("Erro ao preencher a árvore.");
			return 1;
		}
	}
	else
	{
		// Carregar a ABB lendo arquivo binário que contém os nodos da ABB da última execução.
		rewind(tree);
		memcpy(pInfo, tree, sizeof(info));
		printf("%d -> %d\n", pInfo->matricula, pInfo->linha);
	}	

	int op = -1;
	// MENU LINDÃO
	while (op != 0)
	{
		puts("\n---------------------------");
		puts("1 - Pesquisar por matrícula");
		puts("2 - Adicionar um cadastro");
		puts("3 - Remover um cadastro");
		puts("0 - SAIR");
		printf("Escolha uma opção: ");
		
		scanf("%d", &op);
		printf("\n");
		int i = 1, confirmacao = 0;
		char linha[60], ch;
		switch (op)
		{
			case 1:
				printf("Digite a matrícula: ");
				scanf("%d", &(pInfo->matricula));
				if (!buscaABB(pT, pInfo, pInfo, comparaChaves))
					puts("Matrícula não encontrada.");
				else
				{
					fseek(arquivo, sizeof(char) * 60 * pInfo->linha, SEEK_SET);
					fscanf(arquivo, "%59[^\n]", linha);
					printf("Cadastro na linha %d:\n%s\n", pInfo->linha+1, linha);
				}
				break;

			case 2:
				// Número da matrícula gerado automaticamente, é a primeira matrícula disponível no momento.
				do {
					pInfo->matricula = i++;
				} while (buscaABB(pT, pInfo, pInfo, comparaChaves) == SUCESSO);
				rewind(arquivo);
				i = 0;
				// Contagem de linhas para saber onde adicionar o último registro.
				while (!feof(arquivo))
				{
					ch = getc(arquivo);
					if (ch == '\n')
						i++;
				}
				fscanf(arquivo, "%d", &i);
				pInfo->linha = i;
				printf("Nova matrícula: %d\n", pInfo->matricula);
				if (inserirMatricula(pT, pInfo, &arquivo) != SUCESSO)
				{
					puts("Erro ao inserir matrícula.");
					return 1;
				}
				break;

			case 3:
				puts("Escreva a matrícula a remover: ");
				scanf("%d", &(pInfo->matricula));
				if (!buscaABB(pT, pInfo, pInfo, comparaChaves))
					puts("Matrícula não encontrada.");
				else
				{
					fseek(arquivo, sizeof(char) * 60 * pInfo->linha, SEEK_SET);
					fscanf(arquivo, "%59[^\n]", linha);
					printf("Cadastro:\n%s\n", linha);
					printf("Deseja mesmo remover esta matrícula?\nDigite 1 para sim, 0 para não: ");
					scanf("%d", &confirmacao);
					if (confirmacao == 1)
					{
						destroiABB(&pT); // Limpar a árvore.
						if (criaABB(&pT, sizeof(info)) != SUCESSO)
						{
							puts("Erro ao criar árvore.");
							return 1;
						}
						if (removerMatricula(&pT, pInfo, &arquivo) != SUCESSO)
						{
							puts("Erro ao remover matrícula. Nada foi alterado.");
							return 1;
						}
						else
							puts("Matrícula removida.");
					}
				}
				break;

			default:
				break;
		}
	}

	// TODO: Fazer salvar quando fechar

	//fclose(tree);
	fclose(arquivo);

	return 0;
}

/////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////
void exibeChave(void *pInfo)
{
	printf(" %u; ", ((info *)pInfo)->matricula);
}

/////////////////////////////////////////////////////////
void flush(FILE *in)
{
	int c;
	do
	{
		c = fgetc(in);
	} while(c != '\n' && c != EOF);
}

/////////////////////////////////////////////////////////
int inserirMatricula(pABB pT, info * pInfo, FILE ** arquivo)
{

	// Reabrir arquivo no modo append.
	fclose(*arquivo);
	if (!(*arquivo = fopen("arq.txt", "a")))
	{
		puts("inserirMatricula: Erro ao reabrir \"arq.txt\" em modo append.");
		return FRACASSO;
	}

	int matricula = pInfo->matricula, telefone, idade;
	char nome[15], departamento[15];
	double salario;

	printf("Digite o nome (até 15 caracteres sem espaços): "); scanf("%15s", nome);
	printf("Digite o telefone (6 dígitos): "); scanf("%d", &telefone);
	printf("Digite o salário: "); scanf("%lf", &salario);
	printf("Digite a idade (entre 10 e 100 anos, inclusive): "); scanf("%d", &idade);
	printf("Digite o departamento (até 15 caracteres sem espaços): "); scanf("%15s", departamento);

	char cadastro[61];
	sprintf(cadastro, "%d %s %d %0.2f %d %s #", matricula, nome, telefone, salario, idade, departamento);
	printf("\nCadastro inserido:\n%-59s\n", cadastro);
	fseek(*arquivo, sizeof(char) * 60 * pInfo->linha, SEEK_SET);
	fprintf(*arquivo, "%-59s\n", cadastro);

	// Insere na ABB índice.
	insereABB(pT, pInfo, comparaChaves);

	// Devolver o ponteiro de arquivo da forma que foi recebido.
	fclose(*arquivo);
	if (!(*arquivo = fopen("arq.txt", "r")))
	{
		puts("inserirMatricula: Erro ao reabrir \"arq.txt\" em modo leitura.");
		return FRACASSO;
	}

	return SUCESSO;
}

/////////////////////////////////////////////////////////
int constroiArvoreIndices(pABB pT, FILE ** arquivo)
{
	info * pInfo = malloc(sizeof(info));
	rewind(*arquivo);
	int i = 0, r;
	while (!feof(*arquivo)) 
	{
		pInfo->linha = i;
		fseek(*arquivo, sizeof(char) * 60 * i, SEEK_SET);
		r = fscanf(*arquivo, "%d", &pInfo->matricula);
		// Verificar se acabo de ler o final do arquivo e sair se for o caso.
		if (r == EOF)
			break;
		if (insereABB(pT, pInfo, comparaChaves) != SUCESSO)
		{
			puts("constroiArvoreIndices: Erro ao inserir na ABB.");
			return FRACASSO;
		}
		i++;
	} 

	return SUCESSO;
}

/////////////////////////////////////////////////////////
int removerMatricula(ppABB ppT, info * pInfo, FILE ** arquivo)
{
	int i = 0, j;
	FILE * tmp = NULL;
	if (!(tmp = fopen("tmp.dat", "w")))
	{
		puts("removerMatricula: Erro ao criar arquivo auxiliar.");
		return FRACASSO;
	}

	rewind(*arquivo);
	char c;
	// Fazer a cópia de todo o arquivo EXCETO a linha removida.
	while (1)
	{
		fseek(*arquivo, sizeof(char) * 60 * i, SEEK_SET);
		if (i != pInfo->linha)
		{
			for (j = 0; j < 60 && c != EOF; j++)
			{
				c = fgetc(*arquivo);
				if (c != EOF)
					fputc(c, tmp);
			}
		}
		if (c != EOF)
			i++;
		else
			break;
	}

	fclose(*arquivo);
	fclose(tmp);
	remove("arq.txt");
	rename("tmp.dat", "arq.txt");
	if (!(*arquivo = fopen("arq.txt", "r")))
	{
		puts("removerMatricula(ppABB ppT, info *pInfo, FILE **arquivo): Erro ao abrir arquivo resultado.");
		return FRACASSO;
	}

	destroiABB(ppT);
	if (criaABB(ppT, sizeof(info)) != SUCESSO)
	{
		puts("removerMatricula(ppABB ppT, info *pInfo, FILE **arquivo): Erro ao criar nova ABB.");
		return FRACASSO;
	}
	constroiArvoreIndices(*ppT, arquivo);

	return SUCESSO;
}