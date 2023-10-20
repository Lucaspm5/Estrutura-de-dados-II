#include "participante.h"

typedef struct Temporada {
    int numero, qtd_episodios, ano;
    char titulo[50];
    Participante* participantes;
    struct Temporada *l, *r;
} Temporada;

Temporada* inserir_temporada(Temporada* raiz, int numero, char* titulo, int qtd_episodios, int ano);
void imprimir_temporadas(Temporada* raiz);
