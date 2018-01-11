#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"



/*Retorna a altura da árvore*/
int altura(struct Node *N){
    if (N == NULL)
        return 0;
    return N->altura;
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
int fatorBalanceamento (struct Node *N){
    if (N == NULL)
        return 0;
    return altura(N->left) - altura(N->right);
}

/*Rotação para a esquerda*/
struct Node *rotacaoEsquerda(struct Node *n){
    struct Node *y = n->right;
    struct Node *T2 = y->left;

    y->left = n;
    n->right = T2;

    n->altura = max(altura(n->left), altura(n->right))+1;
    y->altura = max(altura(y->left), altura(y->right))+1;

    return y;
}

/*Rotação para a direita*/
struct Node *rotacaoDireita(struct Node *n){
    struct Node *x = n->left;
    struct Node *T2 = x->right;

    x->right = n;
    n->left = T2;

    n->altura = max(altura(n->left), altura(n->right)) +1;
    x->altura = max(altura(x->left), altura(x->right)) +1;

    return x;
}

//Inserção
struct Node* inserir(struct Node* node, Caixa novoconteudo){
    if(node == NULL)
        return (novoNode(novoconteudo));

    if (novoconteudo.cod_cliente < node->conteudo.cod_cliente) //conteudo que eu quero inserir menor que a raiz
        node->left = inserir(node->left, novoconteudo); //insere na esquerda

    else if (novoconteudo.cod_cliente > node->conteudo.cod_cliente) //conteudo que eu quero inserir maior que a raiz
        node->right = inserir(node->right, novoconteudo); //insere na direita
    else
        return node; //se for igual, nada acontece

    node->altura = 1 + max(altura(node->left), altura(node->right)); //atualiza a altura do nodo

    //obtemos o fator de balanceamento do nós para ver se a árvore se tornou desbalanceada
    int balance = fatorBalanceamento(node);

    //se a arvore ficou desbalanceada nós temos 4 casos

    //caso1 inserção esquerda esquerda, uma rotação para direita
    if (balance > 1 && novoconteudo.cod_cliente < node->left->conteudo.cod_cliente)
        return rotacaoDireita(node);

    //caso2 inserção direita direita, uma rotação para esquerda
    if (balance < -1 && novoconteudo.cod_cliente > node->right->conteudo.cod_cliente)
        return rotacaoEsquerda(node);

    //caso3 inserção esquerda direita, uma rotação para esquerda + uma rotação para direita.
    if (balance > 1 && novoconteudo.cod_cliente > node->left->conteudo.cod_cliente){
        node->left = rotacaoEsquerda(node->left);
        return rotacaoDireita(node);
    }

    //caso4 inserção direita esquerda, uma rotação para direita + uma rotação para esquerda.
    if (balance < -1 && novoconteudo.cod_cliente < node->right->conteudo.cod_cliente){
        node->right = rotacaoDireita(node->right);
        return rotacaoEsquerda(node);
    }

    return node;
}

//Valor mínimo encontrado nessa árvore.
struct Node *minValorNode(struct Node* node){
    struct Node* atual = node;
    while (atual->left != NULL)
        atual = atual->left;
    return atual;
}

//Deletar No 
struct Node* deletarNode(struct Node* arvore, Caixa contudo){
    if (arvore == NULL)
        return arvore;

    if (contudo.cod_cliente < arvore->conteudo.cod_cliente) //se o conteudo a ser removido for menor do que o conteudo corrente da arvore
        arvore->left = deletarNode(arvore->left, contudo); //então o conteudo a ser excluido fica na subárvore da esquerda

    else if (contudo.cod_cliente > arvore->conteudo.cod_cliente) //se o conteudo a ser removido for maior do que o conteudo corrente da arvore
        arvore->right = deletarNode(arvore->right, contudo); //então o conteudo a ser excluido fica na subarvore da direita

        //se o conteudo for igual raiz, então é a raiz a ser excluida
    else{
        //nó com apenas um filho.
        if ((arvore->left == NULL) || (arvore->right == NULL)){
            struct Node *temp = arvore->left ? arvore->left : arvore->right;

            //se não tiver filhos
            if (temp == NULL){
                temp = arvore;
                arvore = NULL;
                //caso com um filho, basta copiar os valores do filho.
            } else
                *arvore = *temp;
                free(temp);
        } else{
            // nó com dois filhos. Nesse caso, obtemos o sucessor menor na subárvore da direita
            struct Node* temp = minValorNode(arvore->right);
            //copiar os dados do sucessor para o nó
            arvore->conteudo.cod_cliente = temp->conteudo.cod_cliente;
            //excluir o nó
            arvore->right = deletarNode(arvore->right, temp->conteudo);
        }
    }
    //se a árvore tiver apenas um nó, retornar.
    if (arvore == NULL)
        return arvore;

    //ajustar a altura
    arvore->altura = 1 + max(altura(arvore->left), altura(arvore->right));

    int balance = fatorBalanceamento(arvore); //obter o fator de balanceamento, verificar se a árvore deslanaceou

    //se a árvore desbalanceou temos 4 casos:

    //caso1 esquerda esquerda
    if (balance > 1 && fatorBalanceamento(arvore->left) >= 0)
        return rotacaoDireita(arvore); //uma rotação para a direita

    //caso2 esquerda direita
    if (balance > 1 && fatorBalanceamento(arvore->left) < 0){
        arvore->left = rotacaoEsquerda(arvore->left); //uma rotação para esquerda + uma rotação para direita
        return rotacaoDireita(arvore);
    }

    //caso3 direita direita
    if (balance < -1 && fatorBalanceamento(arvore->right) <= 0)
        return rotacaoEsquerda(arvore); //rotacao para a esquerda

    //caso4 direita esquerda
    if (balance < -1 && fatorBalanceamento(arvore->right) > 0){
        arvore->right = rotacaoDireita(arvore->right); //uma rotação para direita + uma rotação para esquerda
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
void liberarNode(struct Node *t){
    if (t != NULL){
        liberarNode(t->left);
        liberarNode(t->right);
        free(t);
    }
}

//Consultar Chave na aávore
char consultaNode(struct Node *arvore, int elemento){
  char retorno;
  retorno ='n';
  if(arvore != NULL){
    if((arvore)->conteudo.cod_cliente > elemento)
    {
      consultaNode(arvore->left, elemento);
    }else
    {
      if(arvore->conteudo.cod_cliente < elemento)
      {
        consultaNode(arvore->right, elemento);
      }else 
      {
        if(arvore->conteudo.cod_cliente == elemento)
          retorno = 's';
      }
    }
  }else
   retorno = 'n'; 
   
  return retorno;
}

//Impressao em ordem
void emOrdem(struct Node *root){
    if (root != NULL){
        emOrdem(root->left);
        printf("%d\n", root->conteudo.cod_cliente);
       printf("%d, %d,%d \n", root->conteudo.cod_cliente,root->conteudo.operacao,root->conteudo.valor);
        emOrdem(root->right);
    }
}

//impressao pós ordem
void posOrdem(struct Node *root){
    if (root != NULL){
        emOrdem(root->right);
        printf("%d, %d,%d \n", root->conteudo.cod_cliente,root->conteudo.operacao,root->conteudo.valor);
        emOrdem(root->left);
   }
}

//Impressao Relatorio
void imprimeRelatorio(struct Node *arvore){
  printf("-+- Inicio relatorio -+-");	
  printf("-+- Fim relatorio -+-");	
}