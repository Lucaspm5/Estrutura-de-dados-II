#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "participante.h"
#include "temporadas.h"

#define debug(x) printf("%s is %d\n", #x, x)
#define ALOCAR(y) (y*) malloc(sizeof(y))
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
//--------------------------------------------------------------------
void imprimir_personagens(Participantes* lista) {
	if (lista) {
		printf("%s\n", lista->nome_personagem);
		imprimir_personagens(lista->next);
	}
}
//--------------------------------------------------------------------
void imprimir_artista(Participantes *no, char *personagem) {
    if (no) {
        if (strcmp(no->nome_personagem, personagem) == 0) {
            printf("Artista: %s\n", no->nome_artista);
        }
        imprimir_artista(no->next, personagem);
    }
}
//--------------------------------------------------------------------
void liberar_participantes(Participantes *no) {
    if (no) {
        liberar_participantes(no->next);
        free(no);
    }
}