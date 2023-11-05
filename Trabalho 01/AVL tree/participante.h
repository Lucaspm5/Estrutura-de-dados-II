#ifndef _PERSONAGENS_H
#define _PERSONAGENS_H

typedef struct participantes Participantes;
//-------------------------------------------------------------------------
struct participantes {
	char nome_artista[50], nome_personagem[50], descricao[100];
	Participantes *next;
};
//-------------------------------------------------------------------------
void imprimir_participantes(Participantes* no);
int _Validparticipantes(Participantes *no);
void insertAndSort(Participantes **head, char *nome_artista, char *nome_personagem, char *descricao);
void imprimir_artista(Participantes *no, char *personagem);
void liberar_participantes(Participantes *no);
//-------------------------------------------------------------------------
#endif
