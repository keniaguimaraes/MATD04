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

//Declaração de variaveis e estruturas.
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

//Cria a lista
void criaLista() {
  listaAgenda = NULL;
  printf("Lista Criada! \n");
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

//Insere na lista
void insereLista() {
  struct Agenda * novo, * aux;
  struct DadosLeitura leitura;
  
  novo = (struct Agenda *) malloc(sizeof(struct Agenda));
  
  if (novo != NULL) {
  	
    printf("\n Informe o codigo: ");
    scanf("%d",&leitura.codigo);
    printf("\n Informe o nome: ");
    fflush(stdin);							
	fgets(novo->nome, 30, stdin);	

    printf("\n Informe o Idade: ");
    scanf("%d", &leitura.idade); 
    printf("\n Informe o peso: ");
    scanf("%f",&leitura.peso); 
    printf("\n Informe a altura: ");
    scanf("%f",&leitura.altura); 
   
    novo->codigo = leitura.codigo;
    novo->idade  = leitura.idade;
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

//Busca e imprime pessoa
void imprimeLista(int valor) {
  struct Agenda * busca;
  bool achou;

  if (listaAgenda != NULL) {
    busca = listaAgenda;
	     if (busca->codigo == valor){	
	      printf ("\n Codigo: %d", busca->codigo);
	      printf ("\n Nome: %s",  busca->nome);
	      printf ("\n Idade: %d", busca->idade);
	      printf ("\n Peso: %f",  busca->peso);
	      printf ("\n Altura: %f", busca->altura);
	      achou = true;
	     }else {
	     	busca = busca->proximo;
	     	achou = false
		 }
  }
  else printf("Lista esta vazia!");
  if (achou == false) {
  	  printf("Pessoa nao cadastrada");
  }
}

//Remove pessoa da lista
void removeLista(int valor) {
   struct Agenda * aux1, * aux2;


   if (listaAgenda != NULL) {  
 
     aux1 = listaAgenda;          
     aux2 = listaAgenda->proximo; 

     if (aux1->codigo == valor) {
       if (aux1->proximo != NULL) {
         aux2->anterior = NULL;  
         listaAgenda = aux2;  
       }
      free(aux1);
     }
     
     else while (aux2 != NULL && aux2->codigo != valor)
     {
       aux1 = aux2;
       aux2 = aux2->proximo;
       if (aux2 != NULL) {
         aux1->proximo = aux2->proximo;
        if (aux2->proximo != NULL) 
          aux2->proximo->anterior = aux1;
        free (aux2);
       }
    } 
  }
}

//Detroi Lista
void destroiLista() {
  struct Agenda * aux;

  while (listaAgenda != NULL) { 
    aux = listaAgenda;  
    listaAgenda = listaAgenda->proximo; 
    free(aux); 
  }
}


//Progrma principal
int main (){

 int opcao, codigo;
 char ok;
   
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
                       insereLista();	
                       menu();
          }break;
          
           case 3:{    printf("Informe o codigo da Pessoa: ");
                       scanf ("%d", &codigo);
                       if ((codigo < 0) || (codigo > 50)){
                       	printf("Codigo entre 1 e 50!");
					   }else{
					         imprimeLista(codigo);
                            
					   }
		              getch();
                      menu();
          }break;
     
     
          case 4:{
		              printf("Informe o codigo que sera removido: ");
                      scanf ("%d", &codigo);
                       if ((codigo < 0) || (codigo > 50)){
                       	printf("Codigo entre entre 1 e 50!");
					   }else{ 
					      removeLista(codigo);
					    }
                      menu();
          }break;
          case 5:{
                        destroiLista;
                        return 0;
          }break;
    
         default: 
         break;
       }
    
 }
}

