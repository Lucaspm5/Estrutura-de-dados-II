#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "participante.h"
#include "temporadas.h"
#include "series.h"

#define debug(x) printf("%s is %d\n", #x, x)
#define ALOCAR(y) (y*) malloc(sizeof(y))
//-------------------------------------------------------------------------
bool dp2[10000], flag2 = true;
//--------------------------------------------------------------------
struct series {
    int codigo, num_temporadas;
    char titulo[50];
    temp* temporadas;
    struct series *esq, *dir;
};
//-------------------------------------------------------------------------
void vectormemo() { memset(dp2, false, sizeof(dp2)); }
//--------------------------------------------------------------------
Series* create_node(int codigo, char* titulo, int num_temporadas) {
	Series* node = ALOCAR(Series);
	node->codigo = codigo;
	node->num_temporadas = num_temporadas;
	strcpy(node->titulo, titulo);
	node->esq = node->dir = NULL;
	return node;
}
//--------------------------------------------------------------------
void inserir_serie(Series** no, int codigo, int num_temp, char *titulo) {
	if(!(*no)) {
		(*no) = create_node(codigo, titulo, num_temp);
		if (flag2) {
			vectormemo();
			flag2 = !flag2;
		}
		dp2[(*no)->codigo] = true;
	} else {
		if(codigo < (*no)->codigo) {
			inserir_serie(&(*no)->esq, codigo, num_temp, titulo);
		} else if(codigo > (*no)->codigo) {
			inserir_serie(&(*no)->dir, codigo, num_temp, titulo);
		}
	}
}
//--------------------------------------------------------------------
void imprimir_series(Series* no) {
	if(no) {
		imprimir_series(no->esq);
		printf("Codigo: %d\nTitulo: %s\nTemporadas: %d\n", no->codigo, no->titulo, no->num_temporadas);
		imprimir_series(no->dir);
	}
}
//-------------------------------------------------------------------------
int existe(int num) { return (dp2[num]) ? 1 : 0; }
//--------------------------------------------------------------------
void search_Tree(Series *no, int codigo, int num, int opc) {
	if (!no) return;
	if (!existe(codigo)) {
		printf("Codigo nao cadastrado, informe um codigo valido!\n");
	}
	if (no->codigo == codigo) {
		int numb, qntd_eps, ano;
		char tit[50], nick[50];
		switch(opc) {
			case 2:
				printf("Informe o numero da temporada, a quantidade de eps, o ano da temporada, e o titulo da temporada:\n");
				scanf("%d %d %d %s", &numb, &qntd_eps, &ano, tit);
				insert_tree(&no->temporadas, numb, qntd_eps, ano, tit);
				break;
			case 3:
				search_binary(no->temporadas, num, opc);
				break;
			case 4:
				imprimir_series(no);
				break;
			case 5:
				imprimir(no->temporadas);
				break;
			case 6:
				search_binary(no->temporadas, num, opc);
				break;
			case 7:
				printf("Informe o nome do personagem:\n");
				scanf("%s", nick);
				traversal(no->temporadas, nick);
		}
	} else {
		search_Tree(no->esq, codigo, num, opc);
		search_Tree(no->dir, codigo, num, opc);
	}
}