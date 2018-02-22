#ifndef DEFINICOES_H_
#define DEFINICOES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDEM_PAG 5
#define MAX_KEYS 4


enum boolean {
    true = 1, false = 0
};
typedef enum boolean bool;

//Interfaces das Funções
int obterCampos(FILE* arqCat, char* strCampo, int* reg);
short obterRegistro(FILE* arqReg, char* strBuffer);
void receberDados(char* strBuffer);


typedef struct {
	int key;
	short byteoffset;
	short esq;
	short dir;
}chave;


typedef struct {
	short rrn;
	chave keys[MAX_KEYS];
	int qtdKeys;
	short pai;
}pagina;

typedef struct {
	short rrn;
	chave keys[MAX_KEYS+1];
	int qtdKeys;
	short pai;
}paginaAuxiliar;


void criaArvore(FILE* arqReg, FILE* arqArvore);
void ordenaChaves(pagina *p);
void ordenaChavesAux(paginaAuxiliar *p);
short buscaRegistroArvore(FILE* arqArvore, int id, short filho);
void listaRegistro(FILE* arqReg, short offset);

short rrnCount = 1;
short rrnraiz = -2;
short byte = 0;
int promoteKey = 0;
short promoteByte = 0;


#endif /* DEFINICOES_H_*/


