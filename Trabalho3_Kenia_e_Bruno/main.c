//Trabalho Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimaraes.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

//Declaraco de variaveis e estruturas.
#define tamanho  100
#define valrand  10000

int  vetor[tamanho];
int c;
  char buffer[30];
  struct timeval tv;

  time_t curtime;



//Declaracao de procedimentos.

//Menu
void menu(){
  system("cls");
  printf(" 1. Geracao do conjunto de dados\n");
  printf(" 2. Pesquisa sequencial\n");
  printf(" 3. Ordenacao\n");
  printf("   a. Insercao direta\n");
  printf("   b. Troca\n");
  printf("   c. Selecao\n");
  printf(" 4. Pesquisa binaria\n");
  printf(" 5. Sair do programa\n");
}


void geraConjunto(){
 int i=0;
 srand(tamanho);
 for(i=0; i<tamanho; i++)
   vetor[i]	= rand() % valrand;
}

void pesquisaSeq(){
  int i,numero, achou;
  achou = 0;
  printf("Informe um numero: ");
  scanf("%d",&numero);
  
  
   
 gettimeofday(&tv, NULL); 
  curtime=tv.tv_sec;

  
  for (i=0; i< tamanho; i++) {
   if (vetor[i]== numero){
    printf("Valor encontrado na posicao %d\n ", i);
    achou=1;
   }
  }
 
 if (achou !=1){
  printf("Valor nao encontrado!\n");
 } 
  
  strftime(buffer,30,"%m-%d-%Y  %T.",localtime(&curtime));
  //printf("%s%ld\n",buffer,tv.tv_usec);

  
  scanf("%d", &c);
}


void bublleshort(){
  int x, y, aux;
      
  for( x = 0; x < tamanho; x++ )
  {
    for( y = x + 1; y < tamanho; y++ ) // sempre 1 elemento à frente
    {
      // se o (x > (x+1)) então o x passa pra frente (ordem crescente)
      if ( vetor[x] > vetor[y] )
      {
         aux = vetor[x];
         vetor[x] = vetor[y];
         vetor[y] = aux;
      }
    }
  } 
  
  
  //mostra vetor ordenado
  if (tamanho < 10000){
  for( x = 0; x < tamanho; x++ ){
    printf("%d | ",vetor[x]); 
  }
 }
  printf("\nVetor Ordenado!\n");
  scanf("%d", &c);
  
}

void pesquisaBin(){
  int esq = 0, meio, dir = tamanho-1, numero, achou;
  achou = 0;
  printf("Informe um numeroo: ");
  scanf("%d",&numero);

  
  while(esq <= dir){
  	meio = (esq+dir)/2;
  	if(numero == vetor[meio]) {
	  achou = 1;
	  printf("valor entontrado na posicao %d\n", meio);
	  break;
	  }
  	else if(numero < vetor[meio]) dir = meio-1;
  	else if(numero > vetor[meio]) esq = meio+1;
  }
 
 if (achou !=1){
  printf("Valor nao encontrado!\n");
 }
 scanf("%d", &c);
}

//Progama principal
int main() {
  int opcao = -1;
  char op;
  
 
  do {
       menu();
       printf("Informe a Opcao: ");
       scanf("%d", &opcao);
       switch(opcao) {
         
		 case 1: geraConjunto();
         		  break;
				 
         case 2: pesquisaSeq();
   		          break;
				 
         case 3: 
			    printf("\n Informe a letra: ");
                scanf(" %c", &op);
			    
                switch(op){ 
                case 'a': printf("Nao implementado!\n");
                          break;
                          
                case 'b': bublleshort();
                          break;
				   
                case 'c': printf("\n Nao implementado\n");
                          break;
			}
			break;
          				
         case 4:  pesquisaBin();
                  break;  
		        
         case 5:   return 0; 
		           break;
        }
    
  } while (opcao != 0);

}
