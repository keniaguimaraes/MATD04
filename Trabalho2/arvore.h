
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

int max (int a, int b);
int altura(struct Node *N);
struct Node* novoNode(Caixa key);
struct Node *rotacaoDireita(struct Node *n);
struct Node *rotacaoEsquerda(struct Node *n);
int fatorBalanceamento (struct Node *N);
struct Node* inserir(struct Node* node, Caixa novoconteudo);
struct Node *minValorNode(struct Node* node);
struct Node* deletarNode(struct Node* arvores, Caixa novoconteudo);
void liberarNode(struct Node *t);
void printTree(struct Node *arvore, int h);
char consultaNode(struct Node *arvore, int elemento);
void emOrdem(struct Node *arvore);
void posOrdem(struct Node *arvore);
void imprimeRelatorio(struct Node *arvore);

#endif //TREE_AVL_BITREE_H
