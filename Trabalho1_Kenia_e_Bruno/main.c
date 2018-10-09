//Trabalho Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimarães.

#include <stdio.h>
#include <stdlib.h>

//declaracao de variaveis e estruturas.
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



//Declaração de procedimentos.

//Cria a lista duplamente encadeada
void criaLista() {
  listaAgenda = NULL;
  printf("Lista Criada! \n");
}
  
  
void destroiLista() {
  struct Agenda * aux;
  // percorre toda a lista e desaloca cada elemento,
  // comecando do primeiro para o ultimo
  // listaNumeros vai sempre apontar para o primeiro elemento
  while (listaAgenda != NULL) {  // enquanto lista nao estive vazia
    aux = listaAgenda;  // aux aponta para o 1o elemento da lista
    listaAgenda = listaAgenda->proximo;  // aponta para o proximo elemento
    free(aux);  // desaloca elemento - libera memoria
  }
  printf("Lista Removida!");
}

//Menu
void menu(){
   system("cls");	
   printf("1- Criar \n");	
   printf("2- Inserir \n");	
   printf("3- Consultar \n");	
   printf("4- Remover \n");
   printf("5- Encerrar \n");
   		
}

int main (){

 int opcao;
   
   menu();
   
   for ( ; ; ){
     printf("Informe a Opcao: ");
     scanf("%d", &opcao);
     
     switch (opcao){
		 case 1:{
		               criaLista();
					   getch();	
                       menu();
          }break;
          
          case 2:{
                       //inserir;
                        getch();	
                        menu();
          }break;
          
           case 3:{
                       //criarLista;
                        getch();	
                        menu();
          }break;
     
     
          case 4:{
                       //remover;
                        getch();	
                        menu();
          }break;
          case 5:{
                       //liberar;
                       //free()
                        menu();
          }break;
    
         default: 
         break;
       };
    
 }
  return 0;
};


