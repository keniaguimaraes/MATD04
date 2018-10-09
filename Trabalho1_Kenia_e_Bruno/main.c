//Trabalho Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimarães.

#include <stdio.h>
#include <stdlib.h>


struct DadosLeitura {
  int   codigo;
  char  nome[30];
  int   idade;
  float peso;
  float altura;	
};

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


void insereNaLista() {
  struct Agenda * novo, * aux;
  struct DadosLeitura leitura;
  
  novo = (struct Agenda *) malloc(sizeof(struct Agenda));
  
  if (novo != NULL) {
  	
    printf("\n Informe o codigo: ");
    scanf("%d",&leitura.codigo);
    //printf("\n Informe o nome: ");
   // scanf("%C",&leitura.nome); 
    printf("\n Informe o Idade: ");
    scanf("%d",&leitura.idade); 
    printf("\n Informe o peso: ");
    scanf("%f",&leitura.peso); 
    printf("\n Informe a altura: ");
    scanf("%f",&leitura.altura); 
   
    novo->codigo = leitura.codigo;
    //novo->nome   = leitura.nome;
    novo->peso   = leitura.peso;
    novo->altura = leitura.altura;
    
	novo->anterior = NULL;
    novo->proximo = NULL;

    if (listaAgenda == NULL)
       listaAgenda = novo;
    else {
      aux = listaAgenda;
      while (aux->proximo != NULL) aux = aux->proximo;
      aux->proximo = novo;
      novo->anterior = aux;
    }
  }
  else printf("ERRO de alocacao de memoria!");
}


void imprimeLista() {
  struct Agenda * aux;

  if (listaAgenda != NULL) {
    aux = listaAgenda;
    
    while (aux != NULL) {
      printf ("\n Codigo: %d", aux->codigo);
      //printf ("\n Nome: %c", aux->nome);
      printf ("\n Idade: %d", aux->idade);
      printf ("\n Peso: %f",  aux->peso);
      printf ("\n Altura: %f", aux->peso);
      aux = aux->proximo;
    }
  }
  else printf("Lista esta vazia!");
}



//progoram principal
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
                       insereNaLista();	
                       menu();
          }break;
          
           case 3:{
                       imprimeLista();
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


