
/*
Trabalho de Estrutura 
Aluna: Kênia Guimaraes
*/

#include "definicoes.c"

int main(){
	

	int opcao = 0; //Opcão do menu
	int field_length = 0; //Armazena o tamanho do campo
	int campo = 0; //Contador de campos
	int contadorReg = 0; //Contador de registros
	short tamanhoRegistro = 0; //Armazena o tamanho do registro
	short rec_length; //Armazena o tamanho do registro
	char filename[20], strCampo[256], strBuffer[512]; // Strings
	char* token; //Armazena parte de string ao utilizar strtok
	char id[2];
	int id2;
	
	int searchKey;
	short offset;
	
	FILE* arqCat;
	FILE* arqReg;
	FILE* arqArvore;
	
	do{
	/*	printf("----------------MENU--------------\n");
	    printf("    1 -  Importar Agenda \n");
	    printf("    2 -  Inserir Novo Contato \n");
	    printf("    3 -  Buscar Contato por ID\n");
	    printf("    4 -  Listar Contatos\n");
	    printf("    5 -  Listar Estrutura Arvore-B\n");
	    printf("    6 - Terminar o programa\n");
	    printf("\nDigite o numero da sua escolha: ");
	    //printf("%i\n",(int)sizeof(pagina));*/
	    scanf("%d", &opcao);
	    fflush(stdin);
	    
	    switch(opcao){
	    	
	    	/*Importação de Registro */
	        case 1:
	        	strCampo[0] = '\0';
	        	strBuffer[0] = '\0';

	       		printf("\nDigite o nome da agenda a ser importada: ");
   				gets(filename);
    			if((arqCat = fopen(filename, "r")) == NULL){
        			printf("*ERRO!");
       				break;
    			}

	       		printf("Digite um nome para o Arquivo de Registros: ");
				gets(filename);
				if((arqReg = fopen(filename, "w+")) == NULL){
	    			printf("*ERRO!");
	    			break;
				}
								
    			/*Faz a importação dos dados do catalogo para o arquivo de registro com os devidos ajustes*/
				field_length = obterCampos(arqCat, strCampo, &contadorReg);
				strcat(strBuffer,strCampo);
    			strcat(strBuffer,"|");

    			while(field_length > 0){
			        campo ++;
			        //printf("\nCampo #%i = %s", campo, strCampo);
			        strCampo[0] = '\0';

			        if(!(campo % 5) ){
				        tamanhoRegistro = strlen(strBuffer);
				        fwrite(&tamanhoRegistro, sizeof(tamanhoRegistro), 1, arqReg);
				        fwrite(strBuffer, tamanhoRegistro, 1, arqReg);
				        strBuffer[0] = '\0';
			        }

			        field_length = obterCampos(arqCat, strCampo, &contadorReg);
			        strcat(strBuffer,strCampo);
			        strcat(strBuffer,"|");
				}	        			
				
				//Cria um novo Arquivo de índice de árvore-b
				if((arqArvore = fopen("ArvoreB", "w+")) == NULL){
				    printf("*ERRO!");
				    break;
				} 
				criaArvore(arqReg, arqArvore);
				printf("\nArquivos de Arvore e Registro Criados com Sucesso!");
					
			break;
			/*Fim Importação*/
			
			/*Inicio insere registro*/
			case 2:				
				strCampo[0] = '\0';
		        strBuffer[0] = '\0';
	
		        //Recebe o novo registro
		        receberDados(strBuffer);
	
		        
				//Escrevo o tamanho do registro e o registro no final do arquivo
		        fwrite(&tamanhoRegistro, sizeof(tamanhoRegistro), 1, arqReg);
	        	fwrite(strBuffer, tamanhoRegistro, 1, arqReg);	        		
	        		
	        	id[0] = strBuffer[0];
				id[1] = strBuffer[1]; 
				id2 = atoi(id);
			
				insereChave(arqArvore, id2, byte, rrnraiz);
				byte = byte + tamanhoRegistro +2;					        		
	    	break;
	    	/*Fim insere registro*/
			
			/*Busca de Registro*/
			case 3:
	        	printf("\n Informe o ID: ");
	        	scanf("%i", &searchKey);
				
				offset = buscaRegistroArvore(arqArvore, searchKey, rrnraiz);
				listaRegistro(arqReg, offset);
				
			break;
			/*Fim Busca Registro*/
			
			/*Listar Arvore B*/
			case 4:
				listaArvoreB(arqArvore);
			break;
			/*Fim Listar Arvore B*/
		}
						    
	}while(opcao < 5 && opcao > 0);
	
	//encerra os arquivos ao final
	fclose(arqCat);
	fclose(arqReg);
	fclose(arqArvore);
	
	return 0;
}


