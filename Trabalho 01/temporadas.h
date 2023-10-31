#ifndef _TEMPORADAS_H
#define _TEMPORADAS_H

#include "participante.h"

typedef struct Temporada temp;
//-------------------------------------------------------------------------
struct Temporada {
    int numero, qtd_episodios, ano;
    char titulo[50];
    Participantes* participantes;
    struct Temporada *l, *r;
};
//-------------------------------------------------------------------------
void insert_tree(temp **r, int number, int eps, int year, char *rating);
temp* _Creater(int number, int eps, int year, char *rating);
void search_binary(temp *no, int num, int opc);
int existe_temp(int num);
int _Validtemp(temp *no);
void imprimir(temp *no);
void traversal(temp *no, char *nick);
//-------------------------------------------------------------------------
extern int dp1[10000];
extern int flag1;
//-------------------------------------------------------------------------
#endif