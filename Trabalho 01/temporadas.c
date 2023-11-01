#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "temporadas.h"
#include "participante.h"

#define debug(x) printf("%s is %d\n", #x, x)
#define ALOCAR(m) (m*) malloc(sizeof(m))
//-------------------------------------------------------------------------
int dp1[10000], flag1 = 1;
//-------------------------------------------------------------------------
void _INIT() { memset(dp1, -1, sizeof(dp1)); }
//-------------------------------------------------------------------------
temp* _Creater(int number, int eps, int year, char *rating) {
    temp *no = ALOCAR(temp);
    no->numero = number;
    no->qtd_episodios = eps;
    no->ano = year;
    strcpy(no->titulo, rating);
    no->l = no->r = NULL;
    return (no);
}
//-------------------------------------------------------------------------
void insert_tree(temp **r, int number, int eps, int year, char *rating) {
    temp *aux = NULL;
    if (flag1) {
        _INIT();
        flag1 = !flag1;
    }
    if (*r == NULL) {
        aux = _Creater(number, eps, year, rating);
        (*r) = aux;
        dp1[(*r)->numero] = 1;
    } else {
        if ((*r)->numero > number) insert_tree(&((*r)->l), number, eps, year, rating);
        else if ((*r)->numero < number) insert_tree(&((*r)->r), number, eps, year, rating);
    }
}
//-------------------------------------------------------------------------
void imprimir(temp *no) {
    if (no) {
        imprimir(no->l);
        printf("%d - %d - %d %s\n", no->numero, no->qtd_episodios, no->ano, no->titulo);
        imprimir_participantes(no->participantes);
        imprimir(no->r);
    }
}
//-------------------------------------------------------------------------
int existe_temp(int num) { return (dp1[num] != -1) ? 1 : 0; }
//-------------------------------------------------------------------------
void search_binary(temp *no, int num, int opc) {
    if (!existe_temp(num) || !no) {
        printf("Informe uma temporada valida ou cadastre uma\n");
        return;
    }
    if (no->numero == num) {
        char nomea[50], nomep[50], d[200];
        switch(opc) {
            case 3:
                printf("Informe o nome do artista:\n"); scanf("%s", nomea);
                fflush(stdin);
                printf("Informe o nome do personagem:\n"); scanf("%s", nomep);
                printf("Informe a descricao:\n");
                fflush(stdin);
                scanf("%[^\n]s", d);
                insertAndSort(&no->participantes, nomea, nomep, d);
                break;
            case 6:
                if (!(no->participantes)) {
                    printf("Acao nao concluida, eh nescessario adicionar participantes\n");
                } else imprimir_participantes(no->participantes);
                break;
        }
    } else {
        if (num < no->numero) {
            search_binary(no->l, num, opc);
        } else if (num > no->numero) {
            search_binary(no->r, num, opc);
        }
    }
}
//-------------------------------------------------------------------------
void traversal(temp *no, char *nick) {
    if (no) {
        traversal(no->l, nick);
        imprimir_artista(no->participantes, nick);
        traversal(no->r, nick);
    }
}
//-------------------------------------------------------------------------
void liberar_temporada(temp *no) {
	if (no) {
		liberar_temporada(no->l);
        liberar_participantes(no->participantes);
		free(no);
		liberar_temporada(no->r);
	}
}