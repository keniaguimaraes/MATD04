//Trabalho Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimarães.

#include <stdio.h>
#include <stdlib.h>


//Declaração de variaveis e estruturas.
struct Arvore {
  int    numero;
  int    contador;
  struct Arvore * esq;
  struct Arvore * dir;
  struct Arvore *pai;
};
struct Arvore *arvoreBinaria; 


//Declaração de procedimentos.

//Menu
void menu(){
   system("cls");	
   printf("1. Cria Arvore \n");	
   printf("2. Insere Registro \n");	
   printf("3. Consulta Registro \n");	
   printf("4. Remove Registro \n");
   printf("5. Encerrar \n");	
}

void criaArvore(){
	
	arvoreBinaria = NULL;
}

void insere(){
    struct Arvore *aux1, *aux2;
    int n;

    printf("Digite o numero a inserir: ");
    scanf("%d", &n);
  
    if(!arvoreBinaria){
        arvoreBinaria = (struct Arvore*) malloc(sizeof(struct Arvore));

        if(!arvoreBinaria){
            printf("Erro ao alocar =(\n");
            exit(1);
        }

        arvoreBinaria->numero = n;
        arvoreBinaria->esq = NULL;
        arvoreBinaria->dir = NULL;
        arvoreBinaria->pai = NULL;
    }

    else{
        aux1 = arvoreBinaria;
        aux2 = aux1;

        while(aux2){
            if(n < aux2->numero){
                aux2 = aux2->esq;

                if(!aux2){
                    aux1->esq = (struct Arvore*) malloc(sizeof(struct Arvore));

                    if(!aux1->esq){
                        printf("Erro ao alocar =(\n");
                        exit(1);
                    }

                    aux2 = aux1->esq;

                    aux2->esq = NULL;
                    aux2->dir = NULL;
                    aux2->pai = aux1;
                    aux2->numero = n;
                    aux2 = NULL;
                }
                else{
                    aux1 = aux2;
                }
            }

            else{
                aux2 = aux2->dir;

                if(!aux2){
                    aux1->dir = (struct Arvore*) malloc(sizeof(struct Arvore));

                    if(!aux1->dir){
                        printf("Erro ao alocar =(\n");
                        exit(1);
                    }

                    aux2 = aux1->dir;

                    aux2->esq = NULL;
                    aux2->dir = NULL;
                    aux2->pai = aux1;
                    aux2->numero = n;
                    aux2 = NULL;
                }

                else{
                    aux1 = aux2;
                }
            }
        }
    }

    printf("Elemento Inserido!\n");
    getch();
}

struct Arvore* buscar(int n){
    struct Arvore *aux;

    aux = arvoreBinaria;

    while(aux && aux->numero != n){
        if(n < aux->numero){
            aux = aux->esq;
        }

        else{
            aux = aux->dir;
        }
    }

    return aux;
}

struct Arvore* menor_dir(struct Arvore *aux){
    while(aux->esq){
        aux = aux->esq;
    }

    return aux;
}

void remover(struct Arvore *aux){
    struct Arvore *aux2;

    if(aux != arvoreBinaria){
        if(!aux->esq && !aux->dir){
            if(aux->numero < aux->pai->numero){
                aux->pai->esq = NULL;
            }
            else{
                aux->pai->dir = NULL;
            }

            free(aux);
        }

        else if(!aux->dir){
            if(aux->numero < aux->pai->numero){
                aux->pai->esq = aux->esq;
            }
            else{
                aux->pai->dir = aux->esq;
            }
            aux->esq->pai = aux->pai;
            free(aux);
        }

        else if(!aux->esq){
            if(aux->numero < aux->pai->numero){
                aux->pai->esq = aux->dir;
            }
            else{
                aux->pai->dir = aux->dir;
            }
            aux->dir->pai = aux->pai;
            free(aux);
        }

        else{
            aux2 = menor_direita(aux->dir);
            aux->numero = aux2->numero;

            remover(aux2);
        }
    }

    else{
        if(!aux->esq && !aux->dir){
            free(aux);
            arvoreBinaria = NULL;
        }

        else if(!aux->dir){
            aux->esq->pai = NULL;
            arvoreBinaria = aux->esq;
            free(aux);
        }

        else if(!aux->esq){
            aux->dir->pai = NULL;
            arvoreBinaria = aux->dir;
            free(aux);
        }

        else{
            aux2 = menor_direita(aux->dir);
            aux->numero = aux2->numero;

            remover(aux2);
        }
    }
}

void remove_p(){
    struct Arvore *aux;
    int n;

    printf("Informe o numero para remover: ");
    scanf("%d", &n);

    aux = buscar(n);

    if(aux){
        remover(aux);
    }

    else{
        printf("O numero nao consta na arvore!\n");
    }
}



//Progrma principal
int main() {
  int opcao = -1;
  int n;
struct Arvore *busca;
  do {
       menu();
       printf("Informe a Opcao: ");
       scanf("%d", &opcao);
       switch(opcao) {
         
		 case 1:  criaArvore();
         		  break;
				 
         case 2:  insere();
   		          break;
				 
         case 3:  printf("Informe o numero: ");
                  scanf("%d", &n);
      
                  busca = buscar(n);

                  if(busca){
                        printf("Numero encontrado: %d\n", busca->numero);
                  }else{
                        printf("Numero nao encontrado!\n");
                 }

                 getch();
		         break;
				
         case 4:  remove_p();
                  printf("Numero removido!\n");
                  getch();
		          break;
		        
         case 5:   return 0; 
		           break;
        }
  } while (opcao != 0);

}

