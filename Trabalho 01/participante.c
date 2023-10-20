#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "participantes.h"

typedef struct participantes{
	char nome_artista[50], nome_personagem[50], descricao[100];
	Participantes* next;
} Participantes;

#define cerr(x) printf("%d", x);

Participantes* criar(char *nome_artista, char *nome_personagem, char *descricao){
	Participantes* novo = (Participantes*) malloc(sizeof(Participantes));
	strcpy(novo->nome_artista, nome_artista);
 	strcpy(novo->nome_personagem, nome_personagem);     
 	strcpy(novo->descricao, descricao);
 	novo->next = NULL;

	return novo;
}

void insert(Participantes** lista, char *nome_artista, char *nome_personagem, char *descricao){
	if(!(*lista)){
		Participantes* novo = criar(nome_artista, nome_personagem, descricao);
		(*lista) = novo;
	} else{
		insert(&(*lista)->next, nome_artista, nome_personagem, descricao);
	}
}

void imprimir(Participantes* lista){
	if(lista){
		printf("Ator: %s\nPapel: %s\nDescricao: %s\n", lista->nome_artista, lista->nome_personagem, lista->descricao);
		imprimir(lista->next);
	}
}

Participantes* sort(Participantes* head){
	if (!head || !head->next)
        return head;
      
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

int main(){
	Participantes* lista = NULL;

	insert(&lista, "joao", "teste1", "teste1");
	insert(&lista, "pedro", "teste2", "teste2");
	insert(&lista, "zeca", "teste3", "teste3");
	insert(&lista, "nuke", "teste4", "teste4");
	insert(&lista, "antonio", "teste5", "teste5");
	insert(&lista, "ana", "teste6", "teste6");
	insert(&lista, "liedson", "teste7", "teste7");

	// imprimir(lista);
	lista = sort(lista);
	// printf("sort:\n");
	imprimir(lista);
	
	printf("\n");
	
	


	return 0;
}
