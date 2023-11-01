#ifndef _SERIES_H
#define _SERIES_H

#include "temporadas.h"

typedef struct series Series;
//-------------------------------------------------------------------------
struct series {
    int codigo, num_temporadas;
    char titulo[50];
    temp* temporadas;
    struct series *l, *r;
};
//-------------------------------------------------------------------------
void inserir_serie(Series** no, int codigo, int num_temp, char *titulo);
void imprimir_series(Series* no);
void search_Tree(Series *no, int codigo, int num, int opc);
void liberar_series(Series *no);
void vectormemo();
//-------------------------------------------------------------------------
extern int dp2[10000];
//-------------------------------------------------------------------------
#endif