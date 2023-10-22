#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "participante.h"
#include "temporadas.h"

#define debug(x) printf("%s is %d\n", #x, x)
#define ALOCAR(y) (y*) malloc(sizeof(y))
//--------------------------------------------------------------------
struct participantes {
	char nome_artista[50], nome_personagem[50], descricao[100];
	Participantes *next;
};
//--------------------------------------------------------------------
Participantes* criar(char *nome_artista, char *nome_personagem, char *descricao) {
	Participantes* no = ALOCAR(Participantes);
	strcpy(no->nome_artista, nome_artista);
 	strcpy(no->nome_personagem, nome_personagem);
 	strcpy(no->descricao, descricao);
 	no->next = NULL;
	return no;
}
//--------------------------------------------------------------------
void insertAndSort(Participantes **head, char *nome_artista, char *nome_personagem, char *descricao) {
    Participantes* novo = criar(nome_artista, nome_personagem, descricao);
    if (!(*head)) {
        *head = novo;
    } else {
        Participantes* copy = *head;
        Participantes* aux = NULL;
        while (copy && strcmp(copy->nome_artista, nome_artista) < 0) {
            aux = copy;
            copy = copy->next;
        }
        if (!aux) {
            novo->next = *head;
            *head = novo;
        } else {
            aux->next = novo;
            novo->next = copy;
        }
    }
}
//--------------------------------------------------------------------
void imprimir_participantes(Participantes* lista) {
	if (lista) {
		printf("Ator: %s\nPapel: %s\nDescricao: %s\n", lista->nome_artista, lista->nome_personagem, lista->descricao);
		imprimir_participantes(lista->next);
	}
}
