//Trabalho Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimar�es.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//Declara��o de variaveis e estruturas.
#define tamanho  100

int  vetor[tamanho];

//Declara��o de procedimentos.

//Menu
void menu(){
  system("cls");	
  printf("1. Geracao do conjunto de dados\n");	
  printf("2. Pesquisa sequencial\n");	
  printf("3. Ordenacao\n");	
  printf("   a. Insercao direta\n");	
  printf("   b. Troca\n");	
  printf("   c. Selecao\n");	
  printf("4. Pesquisa binaria\n");	
  printf("5. Sair do programa\n");	   
}


void geraConjunto(){
int i;
for (i=0; i<tamanho; i++)
   vetor[i]	= rand() % tamanho;
}
void pesquisaSeq(){
  int i,numero, achou;
  achou = 0;
  printf("Informe um numero: ");
  scanf("%d",&numero);
  for (i=0; i<tamanho; i++) {
   if (vetor[i]==numero){
    printf("Valor encontrado na posi��o %d", i);
    achou=1;
    getch;
   }
 }
 if (achou != 0)
  printf("Valor n�o encontrado!");
}
//Progrma principal
int main() {
  int opcao = -1;
  int n;

  do {
       menu();
       printf("Informe a Opcao: ");
       scanf("%d", &opcao);
       switch(opcao) {
         
		 case 1: geraConjunto();
         		  break;
				 
         case 2: 
   		          break;
				 
         case 3: 
		         break;
				
         case 4:  break;
		        
         case 5:   return 0; 
		           break;
        }
  } while (opcao != 0);

}

