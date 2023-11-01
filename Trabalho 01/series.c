#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "participante.h"
#include "temporadas.h"
#include "series.h"

#define debug(x) printf("%s is %d\n", #x, x)
#define ALOCAR(y) (y*) malloc(sizeof(y))
//-------------------------------------------------------------------------
int dp2[10000], flag2 = 1;
//-------------------------------------------------------------------------
void vectormemo() { memset(dp2, -1, sizeof(dp2)); }
//-------------------------------------------------------------------------
Series* create_node(int codigo, char* titulo, int num_temporadas) {
	Series* node = ALOCAR(Series);
	node->codigo = codigo;
	node->num_temporadas = num_temporadas;
	strcpy(node->titulo, titulo);
	node->l = node->r = NULL;
	return node;
}
//-------------------------------------------------------------------------
void inserir_serie(Series** no, int codigo, int num_temp, char *titulo) {
	if(!(*no)) {
		(*no) = create_node(codigo, titulo, num_temp);
		if (flag2) {
			vectormemo();
			flag2 = !flag2;
		}
		dp2[(*no)->codigo] = 1;
	} else {
		if(codigo < (*no)->codigo) {
			inserir_serie(&(*no)->l, codigo, num_temp, titulo);
		} else if(codigo > (*no)->codigo) {
			inserir_serie(&(*no)->r, codigo, num_temp, titulo);
		}
	}
}
//-------------------------------------------------------------------------
void imprimir_series(Series* no) {
	if(no) {
		imprimir_series(no->l);
		printf("Codigo: %d\nTitulo: %s\nTemporadas: %d\n", no->codigo, no->titulo, no->num_temporadas);
		imprimir_series(no->r);
	}
}
//-------------------------------------------------------------------------
int existe(int num) { return (dp2[num] != -1) ? 1 : 0; }
//-------------------------------------------------------------------------
void search_Tree(Series *no, int codigo, int num, int opc) {
	if (!existe(codigo) || !no) {
		printf("Codigo nao cadastrado, informe um codigo valido!\n");
		return;
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
			case 4: imprimir_series(no);
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
				break;
		}
	} else {
		if (codigo < no->codigo) {
			search_Tree(no->l, codigo, num, opc);
		} else if (codigo > no->codigo) {
			search_Tree(no->r, codigo, num, opc);
		}
	}
}
//-------------------------------------------------------------------------
void liberar_series(Series *no) {
	if (no) {
		liberar_series(no->l);
		liberar_temporada(no->temporadas);
		free(no);
		liberar_series(no->r);
	}
}