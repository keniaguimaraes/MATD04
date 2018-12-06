/*//Segundo Trabalho de Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimarães.*/

#include <stdio.h>
#include <stdlib.h>


//Estruturas e variaveis 
typedef struct Arvore  
{
  int dado;
  struct Arvore * arvore_dir;
  struct Arvore * arvore_esq;
} abb;



//Procedimentos e funções

//função  que cria a arvore
abb * criaArvore() {
  printf("\nArvore criada!");
  getch();
  return NULL;
}

//exibe menu
void menu(){
   system("cls");	
   printf("1. Criar arvore \n");
   printf("2. Destruir arvore \n");
   printf("3. Inserir na arvore \n");
   printf("4. Consultar arvore \n");
   printf("5. Remover da arvore \n");
   printf("0. Sair \n");
}


//função que insere na arvore
void insereArvore(abb ** arv, int num) {

    if (*arv == NULL) {
       *arv = (abb *) malloc(sizeof(abb));
       (*arv)->dado = num;
       (*arv)->arvore_esq = NULL;
       (*arv)->arvore_dir = NULL;
     } 
     else {
  
        if(num < (*arv)->dado)
          insereArvore(&(*arv)->arvore_esq, num);

        if(num > (*arv)->dado)
          insereArvore(&(*arv)->arvore_dir, num);
          
        if (num == (*arv)->dado){
	      printf("O numero ja foi inserido! ");	
	      getch();
		}  
         
     }
}

//função que exibe precurso pre ordem
void consultaPreOrdem(abb * arv) {
  if (arv != NULL) {
  	 printf("%d",arv->dado);
    consultaPreOrdem(arv->arvore_esq);   
	consultaPreOrdem(arv->arvore_dir); 
  }
}

//função que exibe percurso pos ordem
void consultaPosOrdem(abb * arv) {
  if (arv != NULL) {
    consultaPosOrdem(arv->arvore_dir);   
    printf("%d",arv->dado);
	consultaPosOrdem(arv->arvore_esq); 
  }
}

//função que exibe percurso em ordem
void consultaArvore(abb * arv) {
  if (arv != NULL) {
    consultaArvore(arv->arvore_esq);   
    printf("%d",arv->dado);
	consultaArvore(arv->arvore_dir); 
  }
}

//função que destroi arvore
void destroiArvore(abb *arv){
		free(arv);
		printf("Arvore Destruida!");
		getch();
}


abb * nodoMenorValor(abb * arv){
     abb * aux = arv;
    while (aux->arvore_esq != NULL)
        aux = aux->arvore_esq;
    return aux;
}

//função que remove numero da arvore
abb * removeArvore(abb * arv, int num) {

      if (arv == NULL) return arv;
      if (num < arv->dado)
          arv->arvore_esq = removeArvore(arv->arvore_esq, num);
  
      else if (num > arv->dado)
          arv->arvore_dir = removeArvore(arv->arvore_dir, num);
      else
      {   
          if (arv->arvore_esq == NULL)
          {
              abb * temp = arv->arvore_dir;
              free(arv);
              return temp;
          }
          else if (arv->arvore_dir == NULL)
          {
              abb * temp = arv->arvore_esq;
              free(arv);
              return temp;
          }
           abb * temp = nodoMenorValor(arv->arvore_dir);
           arv->dado = temp->dado;
         
          arv->arvore_dir = removeArvore(arv->arvore_dir, temp->dado);
      }
      return arv;
  }


//Programa Principal
int main() {
  int op, num;
  abb * p_arvore;  

  do {
    menu();
    printf("Informe a opcao: ");
    scanf("%d",&op);
    switch (op) {
      
      case 1: p_arvore = criaArvore();
	          break;
      case 2: destroiArvore(p_arvore);
	          break;
      case 3: {
		        printf("Informe o numero: ");
			    scanf("%d",&num);
		        insereArvore(&p_arvore,num);
               } break;
      case 4: {
      	        printf("Em Ordem\n");
      	        consultaArvore(p_arvore);
		       	printf("\nPre Ordem\n");
		      	consultaPreOrdem(p_arvore);
		      	printf("\nPos Ordem\n");
		      	consultaPosOrdem(p_arvore);
		      	getch();
				
	          }break;
      case 5: {
		      	 printf("Informe o numero: ");
			     scanf("%d",&num);
			     removeArvore(p_arvore,num);
              }break;
              
      case 0:return 0;
    } 
  } while (op!=0);


 }
