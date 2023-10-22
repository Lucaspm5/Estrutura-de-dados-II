#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "series.h"
#include "temporadas.h"

struct series {
    int codigo, num_temporadas;
    char titulo[50];
    // temp* temporadas;
    struct series *esq, *dir;
};

Series* create_node(int codigo, char* titulo, int num_temporadas){
	Series* node = (Series*) malloc(sizeof(Series));
	node->codigo = codigo;
	node->num_temporadas = num_temporadas;
	strcpy(node->titulo, titulo);
	node->esq = NULL;
	node->dir = NULL;

	return node;
}

void inserir_serie(Series** root, Series* node){
	if(!(*root)){
		(*root) = node;
	} else{
		if(node->codigo < (*root)->codigo){
			inserir_serie(&((*root)->esq), node);
		} else if(node->codigo > (*root)->codigo){
			inserir_serie(&((*root)->dir), node);
		}
	}
}

void imprimir_series(Series* root){
	if(root){
		imprimir_series(root->esq);
		printf("Codigo: %d\nTitulo: %s\nTemporadas: %d\n", root->codigo, root->titulo, root->num_temporadas);
		imprimir_series(root->dir);
	}
}

int main(){

	Series* root = NULL, *node;

	node = create_node(5, "gravity falls", 8);
	inserir_serie(&root, node);
	
	node = create_node(3, "vikings", 2);
	inserir_serie(&root, node);
	
	node = create_node(8, "menino ney", 3);
	inserir_serie(&root, node);
	
	node = create_node(1, "blue loock", 13);
	inserir_serie(&root, node);
	
	imprimir_series(root);



	return 0;
}
