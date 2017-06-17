#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//tamanho do registro, estimado anteriormente
#define L 60 // estimado anteriormente

// testando leituras no arquivo txt com fseek
int main()
{ char *str=NULL;
  long int tam=L, pos=-1;
  long int cont=0, numRegsArq=10000;
  char path_[]=".\\arq.txt";

  puts(path_);
  FILE *fp1=fopen(path_,"r");
  str=(char *) calloc(tam,sizeof(char));
  puts("Entre com a linha do arquivo txt:");
  scanf("%ld",&pos);
  if (pos < 1 || pos > numRegsArq)
    printf(">>> Posicao invalida: menor que 1 ou maior do que %ld", numRegsArq);
  /*(pos-1) pois o arquivo é zero-indexed*/
  else{
    fseek(fp1,(pos-1)*tam,SEEK_SET);
    fgets(str,tam,fp1);
    printf("fseek: posicao %ld eh igual a  %s \n",pos,str);
  }
  getchar();
  fclose(fp1);
  return 1;
}
