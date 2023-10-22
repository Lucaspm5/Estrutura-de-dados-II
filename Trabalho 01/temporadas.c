#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "temporadas.h"
#include "participante.h"

#define debug(x) printf("%s is %d\n", #x, x)
#define ALOCAR(y) (y*) malloc(sizeof(y))

bool dp[10000], flag = true;
//-------------------------------------------------------------------------
struct Temporada {
    int numero, qtd_episodios, ano;
    char titulo[50];
    Participantes* participantes;
    struct Temporada *l, *r;
};
//-------------------------------------------------------------------------
void _INIT() { memset(dp, false, sizeof(dp)); }
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
    if (flag) {
        _INIT();
        flag = !flag;
    }
    if (*r == NULL) {
        aux = _Creater(number, eps, year, rating);
        (*r) = aux;
        dp[(*r)->numero] = true;
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
        imprimir(no->r);
    }
}
//-------------------------------------------------------------------------
int _Validtemp(temp *no) { return (no) ? 1 : 0; }
//-------------------------------------------------------------------------
int existe_temp(int num) { return (dp[num]) ? 1 : 0; }
//-------------------------------------------------------------------------
void search_binary(temp *no, int num, int opc) {
    if (!existe_temp(num)) {
        printf("Informe uma temporada valida ou cadastre uma\n");
        return;
    }
    if (no->numero == num && opc == 3) {
        imprimir_participantes(no->participantes);
    } else if (no->numero == num && opc == 2) {
        char nomea[50], nomep[50], d[200];
        printf("Informe o nome do artista:\n"); scanf("%s", nomea);
        fflush(stdin);
        printf("Informe o nome do personagem:\n"); scanf("%s", nomep);
        printf("Informe a descricao:\n");
        fflush(stdin);
        scanf("%[^\n]s", d);
        insertparticipantes(&no->participantes, nomea, nomep, d);
        return;
    }
    if (no) {
        search_binary(no->l, num, opc);
        search_binary(no->r, num, opc);
    }
}