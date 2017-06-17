#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//tamanho do registro, estimado anteriormente
#define L 60 // estimado em copiaArq.c

// testando leituras no arquivo txt com fseek
int main()
{ char *str=NULL, *strTemp=NULL, ch;
  long int tam=L;
  long int cont=0, temp=-1,mat;
  char path_[]=".\\arq.txt";

  FILE *fp1=fopen(path_,"r");
  str=(char *) calloc(tam,sizeof(char));
  strTemp=(char *) calloc(tam,sizeof(char));
  puts("Entre com a matricula a ser buscada no arquivo txt:");
  scanf("%ld",&mat);

  while(!feof(fp1) )
	{ fgets(str,tam+1,fp1);

	  cont=0;
	  while(cont<tam && (ch=str[cont])!=' ')
	     { strTemp[cont]=ch;
	       cont++;
	     }
	  strTemp[cont]='\0';
	  temp=atoi(strTemp);
      if (temp==mat)
        { printf("o registro com matricula %ld foi encontrado:\n\n [ %s ]",temp,str);
		  break;
		}
	  /*else
	  {
		printf(" %ld != %ld\n",temp,mat);
	  }*/

    }
  if (temp!=mat)
        printf(">>> o registro com matricula %ld NAO foi encontrado:\n\n",mat);

  getchar();
  free(str);
  free(strTemp);
  fclose(fp1);
  return 1;
}


