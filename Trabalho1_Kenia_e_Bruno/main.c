//Trabalho Estrutura de Dados .
//Alunos:Bruno Vasconcelos e Kenia Guimarães.

#include <stdio.h>
#include <stdlib.h>


//declaracao de variaveis e estruturas.
 int opcao;
  
//declaracao de procedimentos.
void menu(){
	
   printf("1- criar \n");	
   printf("2- inserir \n");	
   printf("3- consultar \n");	
   printf("4- remover \n");
   printf("5- encerrar \n");
		
};


int main(
   
   menu();
   
   for ( ; ; ){
     printf("Informe a Opção: ");
     scanf("%c", &opcao);
     
     switch (opcao){
		 case 1:{
			           //criarLista;
                        menu();
          }break;
          
          case 2:{
                       //inserir;
                        menu();
          }break;
          
           case 3:{
                       //criarLista;
                        menu();
          }break;
     
     
          case 4:{
                       //remover;
                        menu();
          }break;
          case 5:{
                       //liberar;
                        menu();
          }break;
     
     
     
     
         default: 
         break;
       };
    
 }
  return 0;
);

