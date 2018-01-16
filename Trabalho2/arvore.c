#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
/*Retorna a altura da árvore*/
int altura(struct Node *arvore){
    if (arvore == NULL)
        return 0;
    return arvore->altura;
}

int max (int a, int b){
    return (a > b)? a : b;
}
/*Novo No*/
struct Node* novoNode(Caixa conteudo){

    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    node->conteudo.cod_cliente = conteudo.cod_cliente;
    node->conteudo.operacao = conteudo.operacao;
    node->conteudo.valor = conteudo.valor;
    node->left = NULL;
    node->right = NULL;
    node->altura = 1;
    return (node);
}

/*Fator do balanceamento*/
int fatorBalanceamento (struct Node *arvore){
    if (arvore == NULL)
        return 0;
    return altura(arvore->left) - altura(arvore->right);
}

/*Rotação para a esquerda*/
struct Node *rotacaoEsquerda(struct Node *arvore){
    struct Node *rotacao = arvore->right;
    struct Node *rotacao2 = rotacao->left;

    rotacao->left = arvore;
    arvore->right = rotacao2;

    arvore->altura = max(altura(arvore->left), altura(arvore->right))+1;
    rotacao->altura = max(altura(rotacao->left), altura(rotacao->right))+1;

    return rotacao;
}

/*Rotação para a direita*/
struct Node *rotacaoDireita(struct Node *arvore){
    struct Node *rotacao = arvore->left;
    struct Node *rotacao2 = rotacao->right;

    rotacao->right = arvore;
    arvore->left = rotacao2;

    arvore->altura = max(altura(arvore->left), altura(arvore->right)) +1;
    rotacao->altura = max(altura(rotacao->left), altura(rotacao->right)) +1;

    return rotacao;
}

//Inserção
struct Node* inserir(struct Node*node, Caixa novoconteudo){
	
    if(node == NULL)
        return (novoNode(novoconteudo));

    if (novoconteudo.cod_cliente < node->conteudo.cod_cliente) //  se o que for inserir é menor que a arvore
        node->left = inserir(node->left, novoconteudo); //inserir na esquerda

    else if (novoconteudo.cod_cliente > node->conteudo.cod_cliente) //se o que for inserir é maior que a arvore
        node->right = inserir(node->right, novoconteudo); //inserir na direita
    else
        return node; //quando é igual retorna arvore

    node->altura = 1 + max(altura(node->left), altura(node->right)); //atualizar a altura do nó

    //pega fator de balanceamento pra verificar se a arvore está desbalanceada
    int balanceada = fatorBalanceamento(node);

    //desbalancelou 
    //caso 1 inserir  esquerda dupla, rotação para direita
    if (balanceada > 1 && novoconteudo.cod_cliente < node->left->conteudo.cod_cliente)
        return rotacaoDireita(node);

    //caso 2 iserir direita dupla, uma rotação para esquerda
    if (balanceada < -1 && novoconteudo.cod_cliente > node->right->conteudo.cod_cliente)
        return rotacaoEsquerda(node);

    //caso 3 iserir esquerda direita, uma rotação para esquerda + uma rotação para direita.
    if (balanceada > 1 && novoconteudo.cod_cliente > node->left->conteudo.cod_cliente){
        node->left = rotacaoEsquerda(node->left);
        return rotacaoDireita(node);
    }

    //caso 4 iserir direita esquerda, uma rotação para direita + uma rotação para esquerda.
    if (balanceada < -1 && novoconteudo.cod_cliente < node->right->conteudo.cod_cliente){
        node->right = rotacaoDireita(node->right);
        return rotacaoEsquerda(node);
    }
    return node;
}

//Valor mínimo encontrado na árvore.
struct Node* minValorNode(struct Node *arvore){
    struct Node* atual = arvore;
    while (atual->left != NULL)
        atual = atual->left;
    return atual;
}

//Deletar No 
struct Node* deletarNode(struct Node* arvore, Caixa novoconteudo){
    if (arvore == NULL)
        return arvore;

    if (novoconteudo.cod_cliente < arvore->conteudo.cod_cliente) //se o conteudo a ser removida da arvore é menor do que o conteudo da arvoreo conteudo a ser excluido permanece na subárvore da esquerda
        arvore->left = deletarNode(arvore->left, novoconteudo); 

    else if (novoconteudo.cod_cliente > arvore->conteudo.cod_cliente) //se o conteudo a ser removida da arvore  maior do que o conteudo da arvore o conteudo a ser excluido permanece na subarvore da direita
        arvore->right = deletarNode(arvore->right, novoconteudo);
        //se o for igual raiz, a raiz é excluida
    else{
		//caso 1
        //nó com um filho.
        if ((arvore->left == NULL) || (arvore->right == NULL)){
            struct Node *temp = arvore->left ? arvore->left : arvore->right;
            //caso 2  
            //sem tiver filhos
            if (temp == NULL){
                temp = arvore;
                arvore = NULL;
                //caso 3  1 filho: copia os valores.
            } else
                *arvore = *temp;
                free(temp);
        } else{
            // casp 4 nó com dois filhos.
			//Qual sucessor menor na subárvore da direita?
            struct Node* temp = minValorNode(arvore->right);
            arvore->conteudo.cod_cliente = temp->conteudo.cod_cliente; //copei os dados do sucessor para o nó
            arvore->right = deletarNode(arvore->right, temp->conteudo); //excluir o nó
        }
    }
	// caso 5
    //se a árvore tiver apenas um nó.
    if (arvore == NULL)
        return arvore;

    //ajustar a altura
    arvore->altura = 1 + max(altura(arvore->left), altura(arvore->right));

    int balance = fatorBalanceamento(arvore); //Pegar fator de balanceamento

    //se desbalanceou:

    //caso 1 esquerdadupla
    if (balance > 1 && fatorBalanceamento(arvore->left) >= 0)
        return rotacaoDireita(arvore); 

    //caso 2 esquerda direita
    if (balance > 1 && fatorBalanceamento(arvore->left) < 0){
        arvore->left = rotacaoEsquerda(arvore->left);
        return rotacaoDireita(arvore);
    }
    //caso3 direitadupla
    if (balance < -1 && fatorBalanceamento(arvore->right) <= 0)
        return rotacaoEsquerda(arvore); 

    //caso 4 direita esquerda
    if (balance < -1 && fatorBalanceamento(arvore->right) > 0){
        arvore->right = rotacaoDireita(arvore->right); 
        return rotacaoEsquerda(arvore);
    }

    return arvore;
}

//método que imprime a árvore.
void printTree(struct Node *arvore, int h){
    int i;
    if (arvore != NULL){
        printTree(arvore->right, h+1);
        for (i = 0; i < h; i++)
            printf("   ");
        printf("%d\n", arvore->conteudo.cod_cliente);
        printTree(arvore->left, h+1);
    }
}

//Liberar no
void liberarNode(struct Node *arvore){
    if (arvore != NULL){
        liberarNode(arvore->left);
        liberarNode(arvore->right);
        free(arvore);
    }
}



//Impressao em ordem
void emOrdem(struct Node *arvore){
      if (arvore != NULL){
        emOrdem(arvore->left);
        printf("%d,%d,%d \n", arvore->conteudo.cod_cliente,arvore->conteudo.operacao,arvore->conteudo.valor);
        emOrdem(arvore->right);
    }
}

//Impressao pós ordem
void posOrdem(struct Node *arvore){
    if (arvore != NULL){
        posOrdem(arvore->right);
        printf("%d %d %d \n", arvore->conteudo.cod_cliente,arvore->conteudo.operacao,arvore->conteudo.valor);
        posOrdem(arvore->left);
   }
   
}

//Conta quantos nos tem a arvore
int contaNos(struct Node *arvore){
   if(arvore == NULL)
        return 0;
   else
        return 1 + contaNos(arvore->left) + contaNos(arvore->right);
}

//Impressao Relatorio
void imprimeRelatorio(struct Node *arvore ){
 if(!(arvore==NULL)){
    imprimeRelatorio (arvore->left);
    printf("%d %d %d\n",arvore->conteudo.cod_cliente, arvore->conteudo.operacao, arvore->conteudo.valor);
    imprimeRelatorio (arvore->right) ;
 }	
}


void exibeChavesPorNivel(struct Node *arvore, int niv ){
    if(!(arvore==NULL)){     
        if (niv==1){            
            printf("%d\n",arvore->conteudo.cod_cliente);
          
        }else{   
            exibeChavesPorNivel(arvore->left,niv-1); 
            exibeChavesPorNivel(arvore->right,niv-1);     
        }         
    }  
}

struct Node*  busca(struct Node *arvore, int x){
   if (arvore == NULL)
       return NULL;
   if (x == arvore->conteudo.cod_cliente)
       return arvore;
   if (x < arvore->conteudo.cod_cliente) 
       return busca(arvore->left, x);
   else 
       return busca(arvore->right, x);
}


void consultaNode(struct Node * arvore,int elemento){
    struct Node * aux;
    aux = busca(arvore, elemento);
    if (aux == NULL)
       printf("nao existe no com chave: %d\n",elemento);
    else{
       printf("existe no com chave: %d\n", elemento);
    }
}
