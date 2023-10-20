#include "temporadas.h"

typedef struct Serie {
    int codigo, num_temporadas;
    char titulo[50];
    Temporada* temporadas;
    struct Serie *esq, *dir;
} Serie;

Serie* inserir_serie(Serie* raiz, int codigo, char* titulo, int num_temporadas);
void imprimir_series(Serie* raiz);
