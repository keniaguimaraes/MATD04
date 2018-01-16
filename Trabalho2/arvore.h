
#ifndef TREE_AVL_BITREE_H

#define TREE_AVL_BITREE_H

#include <stdlib.h>
/*Tipo do resgistro de banco*/
typedef struct Caixa {
    int cod_cliente;
    int operacao;
    int valor;
} Caixa;

/* Estrutura da arvore*/
typedef struct Node {
   // int conteudo;
    Caixa conteudo; 
    struct Node *left;
    struct Node *right;
    int altura;
} Node;

//Funções
int altura(struct Node *arvore);
int max (int a, int b);
struct Node* novoNode(Caixa conteudo);
struct Node *rotacaoEsquerda(struct Node *arvore);
struct Node *rotacaoDireita(struct Node *arvore);
struct Node* inserir(struct Node* node, Caixa novoconteudo);
struct Node *minValorNode(struct Node *arvore);
struct Node* deletarNode(struct Node* arvore, Caixa novoconteudo);
void printTree(struct Node *arvore, int h);
void liberarNode(struct Node *arvore);
void emOrdem(struct Node *arvore);
void posOrdem(struct Node *arvore);
int contaNos(struct Node *arvore);
void imprimeRelatorio(struct Node *arvore );
void exibeChavesPorNivel(struct Node *arvore, int niv );
struct Node* busca(struct Node * arvore, int x);
void consultaNode(struct Node * arvore, int elemento);

#endif //TREE_AVL_BITREE_H
