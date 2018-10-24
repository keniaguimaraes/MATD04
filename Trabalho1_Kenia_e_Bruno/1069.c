//Problema 1069 - Diamantes e Areia
//Alunos:Bruno Vasconcelos e Kenia Guimarães.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Diamante	{
  char desc_diam;
  struct Diamante *prox;
};
typedef struct Diamante TDiamante;

struct Pilha { 
   TDiamante *topo;
};
typedef struct Pilha Pilha_Diamante;


//Programa Principal
int main(){

	  
  int n = 0;
  int c = 0;
  int i = 0;
  int qtd_diamt;
  
  Pilha_Diamante pilha_diamt;
  TDiamante *aux, *aux2;
  
  char linha[1010] = "";
 
  scanf("%d", &n); //qtd de diamentes

while(c < n)
{
		scanf("%s", linha);

		pilha_diamt.topo = NULL;
		i = 0;
		qtd_diamt = 0;

		while(i < strlen(linha))
		{
			if(linha[i] == '<')
			{
				aux = (TDiamante *) malloc(sizeof(TDiamante));

				if(aux == NULL)
					break;

				aux->desc_diam = linha[i];
				aux->prox = pilha_diamt.topo;

				pilha_diamt.topo = aux;
			}

			else if(linha[i] == '>') //se for igual a >
			{
				if(pilha_diamt.topo != NULL)
				{
					aux2 = pilha_diamt.topo;
					pilha_diamt.topo = aux2->prox;
					free(aux2);
					qtd_diamt++;
				}
			}
			i++;
		}
		printf("%d\n", qtd_diamt);
		c++;
}

  return 0;
}
