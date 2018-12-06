//Trabalho Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimarães.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de variaveis e estruturas.

//Declaração de procedimentos.

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

//Progrma principal
int main() {
  int opcao = -1;
  int n;

  do {
       menu();
       printf("Informe a Opcao: ");
       scanf("%d", &opcao);
       switch(opcao) {
         
		 case 1: 
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

