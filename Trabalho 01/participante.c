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
	Participantes* novo = ALOCAR(Participantes);
	strcpy(novo->nome_artista, nome_artista);
 	strcpy(novo->nome_personagem, nome_personagem);
 	strcpy(novo->descricao, descricao);
 	novo->next = NULL;
	return novo;
}
//--------------------------------------------------------------------
void insertparticipantes(Participantes** lista, char *nome_artista, char *nome_personagem, char *descricao) {
	if (*lista == NULL) {
		Participantes* novo = criar(nome_artista, nome_personagem, descricao);
		(*lista) = novo;
	} else {
		insertparticipantes(&(*lista)->next, nome_artista, nome_personagem, descricao);
	}
}
//--------------------------------------------------------------------
int _Validparticipantes(Participantes *no) { return (no) ? 1 : 0; }
//--------------------------------------------------------------------
void imprimir_participantes(Participantes* lista) {
	if (!_Validparticipantes(lista)) {
		printf("Ocorreu um erro, sem participantes cadastrados\n");
	} else {
		if (lista) {
			printf("Ator: %s\nPapel: %s\nDescricao: %s\n", lista->nome_artista, lista->nome_personagem, lista->descricao);
			imprimir_participantes(lista->next);
		}
	}
}
//--------------------------------------------------------------------
Participantes* sort(Participantes* head) {
	if (!head || !head->next) return head;

    head->next = sort(head->next);

    Participantes* next = head->next;
    if (strcmp(head->nome_artista, next->nome_artista) <= 0)
        return head;

    Participantes* node = next;
    while (node->next && strcmp(node->next->nome_artista, head->nome_artista) < 0)
        node = node->next;

    head->next = node->next;
    node->next = head;

    return next;
}