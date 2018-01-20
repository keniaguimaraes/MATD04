/*
Trabalho de Estrutura 
Aluna: Kênia Guimaraes
*/

#include "arvore.c"
int main() {
    Node *arvoreAVL = NULL;
    int x;
    Caixa reg;
    char op;
	char op2[1];
	
   for ( ; ; ){
        scanf("%c", &op);
        switch (op){
     
            case 'i':{
                        scanf("%d %d %d", &reg.cod_cliente,&reg.operacao, &reg.valor);     
                        arvoreAVL = inserir(arvoreAVL, reg);
            }break;
                
            case 'c': {
                        scanf("%d", &x);
			            consultaNode(arvoreAVL,x);
            }break;

            case 'r':{
                       scanf("%d", &reg.cod_cliente);
                       arvoreAVL = deletarNode(arvoreAVL, reg);
					   
            }break;
            
            case 'p':{
				        scanf("%s", &op2[1]);
				        if (op2[1] == 'c')
                          emOrdem(arvoreAVL);
                        else if  (op2[1] == 'd') 
                          posOrdem(arvoreAVL);
            }break;
                     
            case 'h':{
                		printf("%d\n",altura(arvoreAVL));        		
            }break;
				
			case 'n':{
               		    scanf("%d", &x);
                        exibeChavesPorNivel(arvoreAVL,x);
            }break;	

            case 'f':{
	                     printf("-+- Inicio relatorio -+-\n");
         	             printf("%d\n",contaNos(arvoreAVL));
         	             imprimeRelatorio(arvoreAVL);
         	             printf("-+- Fim relatorio -+-\n");
		 }break;  
	      
          default: 
          break;
       };
    };
    liberarNode(arvoreAVL);
    return 0;
}
