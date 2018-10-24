//Problema 1068 - Balanço de parênteses.
//Alunos:Bruno Vasconcelos e Kenia Guimarães.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct expressao 	{
  char par;
  struct expressao *prox;
};
typedef struct expressao TExpressao;


struct pilha { 	
    TExpressao *topo;
    int qtd;
};
typedef struct pilha ExpPilha;


//Programa Principal
int main(){

	char expressao[3000] = ""; //tamnho da expressao
	int c;
	int sair;//flag saida

	ExpPilha	pilhaExp;
	TExpressao *aux;
	
	while (scanf("%s", expressao) != EOF) //enquanto expressao for <> nulo
	{
		pilhaExp.topo = NULL;
		pilhaExp.qtd = 0; 
		c    =	0;
		sair = 0;

		do
		{
			if(expressao[c] == '(') //achou o (
			{
				aux = (TExpressao *) malloc(sizeof(TExpressao));

				if(aux == NULL){
					break;
				}
					
				aux->par = expressao[c]; //adiciona o (
				aux->prox = pilhaExp.topo;

				pilhaExp.topo = aux;
				pilhaExp.qtd++; //conta a qtd de (
			}

			if(expressao[c] == ')') //achou a )

			{
				if(pilhaExp.topo == NULL)
				{
					sair = 1;
					break;
				}

				else
				{
					aux = pilhaExp.topo;
					pilhaExp.topo = aux->prox;
					free(aux);
					pilhaExp.qtd--;
				}
			}
			c++;
		} while (c < strlen(expressao));

		if ((sair ==1) || pilhaExp.qtd != 0)
			printf("incorrect\n");

		else
			printf("correct\n");
	}

	return 0;
}
