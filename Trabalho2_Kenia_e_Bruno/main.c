//Trabalho Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimar�es.

#include <stdio.h>
#include <stdlib.h>


struct DadosLeitura {
  int   codigo;
  char  nome[30];
  int   idade;
  float peso;
  float altura;	
};

//Declara��o de variaveis e estruturas.
struct Agenda {
  int   codigo;
  char  nome[30];
  int   idade;
  float peso;
  float altura;
  struct Agenda * anterior;
  struct Agenda * proximo;
};
struct Agenda * listaAgenda; 



//Declara��o de procedimentos.

  
//Menu
void menu(){
   system("cls");	
   printf("1. Cria Arvore \n");	
   printf("2. Insere Registro \n");	
   printf("3. Consulta Registro \n");	
   printf("4. Remove Registro \n");
   printf("5. Encerrar \n");	
}



//Progrma principal
int main() {
  int opcao = -1;
  do {
       menu();
       printf("Informe a Opcao: ");
       scanf("%d", &opcao);
       switch(opcao) {
         case 1:  break;
         case 2:  break;
         case 3:  break;
         case 4:  break;
         case 5:  break;
        }
  } while (opcao != 0);
  return 0;
}




