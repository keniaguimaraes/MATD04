//Trabalho Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimaraes.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

//Declaraco de variaveis e estruturas.
#define tamanho  100
#define valrand  10000

int vetor[tamanho];
int c;
char buffer[30];
struct timeval tv;
clock_t t; 
time_t curtime;


//Declaracao de procedimentos.

//Menu
void menu ()
{
  system ("cls");
  printf (" 1. Geracao do conjunto de dados\n");
  printf (" 2. Pesquisa sequencial\n");
  printf (" 3. Ordenacao\n");
  printf ("   a. Insercao direta\n");
  printf ("   b. Troca\n");
  printf ("   c. Selecao\n");
  printf (" 4. Pesquisa binaria\n");
  printf (" 5. Sair do programa\n");
}

double tempo ()
{
  struct timeval tv;
  gettimeofday (&tv, 0);
  return tv.tv_sec + tv.tv_usec / 1e6;
}


void geraConjunto (){
int i=0;
 srand((unsigned)time(NULL));
 for(i=0; i<tamanho; i++){
  vetor[i]	= rand()%valrand;
 }

 /*  //mostra vetor ordenado
  if (tamanho < 10000){
  for( i = 0; i < tamanho; i++ ){
    printf("%d | ",vetor[i]); 
  }
 }   */
 
 getch();
   
}
void pesquisaSeq (){
  int i, numero, achou;
  double t1, t2;
  achou = 0;
  printf ("Informe um numero: ");
  scanf ("%d", &numero);

  t1 = tempo ();

  for (i = 0; i < tamanho; i++)
    {
      if (vetor[i] == numero)
	{
	  printf ("Valor encontrado na posicao %d\n ", i);
	  achou = 1;
	}
    }

  if (achou != 1)
    {
      printf ("Valor nao encontrado!\n");
    }
  t2 = tempo ();
  printf ("O tempo gasto na busca foi de: %lf s\n", t2 - t1);

 getch();
}

void insertionSort ()
{
  int i, j, menor_i, aux,x;
  double t7, t8;
  t7 = tempo ();

  for (j = 0; j < tamanho - 1; j++)
    {
      menor_i = j;
      for (i = j + 1; i < tamanho; i++)
	if (vetor[i] < vetor[menor_i])
	  menor_i = i;
      aux = vetor[j];
      vetor[j] = vetor[menor_i];
      vetor[menor_i] = aux;
    }
    
  /*   if (tamanho < 10000)
    {
      for ( x = 0; x < tamanho; x++)
	{
	  printf ("%d | ", vetor[x]);
	}
    }*/
    
  t8 = tempo ();
  printf ("\nConjunto de dados ordenado!\n");
  printf ("O tempo gasto na ordenacao foi de: %lf s\n", t8 - t7);
  getch();
}

void bublleSort ()
{
  int x, y, aux;
  double t5, t6;
  
  t5 = tempo ();

  for (x = 0; x < tamanho; x++)
    {
      for (y = x + 1; y < tamanho; y++)	// sempre 1 elemento C  frente
	{
	  // se o (x > (x+1)) entC#o o x passa pra frente (ordem crescente)
	  if (vetor[x] > vetor[y])
	    {
	      aux = vetor[x];
	      vetor[x] = vetor[y];
	      vetor[y] = aux;
	    }
	}
    }


  //mostra vetor ordenado
 /* if (tamanho < 10000)
    {
      for (x = 0; x < tamanho; x++)
	{
	  printf ("%d | ", vetor[x]);
	}
    }*/
  t6 = tempo ();
  printf ("\nConjunto de dados ordenado!\n");
  printf ("O tempo gasto na ordenacao foi de: %lf s\n", t6 - t5);

 getch();
}


void selectionSort() 
{
  int i, j, min, x,aux;
  double t9, t10;
  t9 = tempo();
  for (i = 0; i < (tamanho - 1); i++) 
  {
     min = i;
     for (j = (i + 1); j < tamanho; j++) {
       if(vetor[j] < vetor[min]) 
         min = j;
     }
     if (vetor[i] != vetor[min]) {
       aux = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = aux;
     }
  }
  
 /* if (tamanho < 10000)
    {
      for ( x = 0; x < tamanho; x++)
	{
	  printf ("%d | ", vetor[x]);
	}
    } */
  
  t10 = tempo();
  printf ("\nConjunto de dados ordenado!\n");
  printf ("O tempo gasto na ordenacao foi de: %lf s\n", t10 - t9);
 getch();
}



void pesquisaBin ()
{
  int esq = 0, meio, dir = tamanho - 1, numero, achou;
  double t3, t4;
  achou = 0;
  printf ("Informe um numero: ");
  scanf ("%d", &numero);

  t3 = tempo ();
  //printf("O valor de t1 C): %lf\n", t1);
  while (esq <= dir)
    {
      meio = (esq + dir) / 2;
      if (numero == vetor[meio])
	{
	  achou = 1;
	  printf ("valor entontrado na posicao %d\n", meio);
	  break;
	}
      else if (numero < vetor[meio])
	dir = meio - 1;
      else if (numero > vetor[meio])
	esq = meio + 1;
    }

  if (achou != 1)
    {
      printf ("Valor nao encontrado!\n");
    }
  t4 = tempo ();

  printf ("O tempo gasto na busca foi de: %lf s\n", t4 - t3);
 getch();
}


//Progama principal
int main ()
{
  int opcao = -1;
  char op;


  do
    {
      menu ();
      printf ("Informe a Opcao: ");
      scanf ("%d", &opcao);
      switch (opcao)
	{

	case 1:
	  geraConjunto ();
	  break;

	case 2:
	  pesquisaSeq ();
	  break;

	case 3:
	  printf ("\n Informe a letra: ");
	  scanf (" %c", &op);

	  switch (op)
	    {
	    case 'a':
	      insertionSort ();
	      break;

	    case 'b':
	      bublleSort ();
	      break;

	    case 'c':
	      selectionSort();
	      break;
	    }
	  break;

	case 4:
	  pesquisaBin ();
	  break;

	case 5:
	  return 0;
	  break;
	}

    }
  while (opcao != 0);
}
