#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temporadas.h"
#include "participante.h"

#define debug(x) printf("%s is %d\n", #x, x)
#define ALOCAR(y) (y*) malloc(sizeof(y))
//-------------------------------------------------------------------------
struct Temporada {
    int numero, qtd_episodios, ano;
    char titulo[50];
    Participantes* participantes;
    struct temp *l, *r;
};
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
    if (!(*r)) {
        aux = _Creater(number, eps, year, rating);
        (*r) = aux;
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
int main() {
    temp *lista =  NULL;
    insert_tree(&lista, 7, 5, 2001, "Luquinhas");
    insert_tree(&lista, 10, 4, 2003, "Liedson Gay");
    insert_tree(&lista, 9, 5, 2001, "Luquinhas");
    insert_tree(&lista, 15, 6, 2002, "Luquinhas");
    imprimir(lista);
    return 0;
}