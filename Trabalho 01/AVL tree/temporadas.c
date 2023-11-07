#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "temporadas.h"
#include "participante.h"

#define debug(x) printf("%s is %d\n", #x, x)
#define ALOCAR(m) (m*) malloc(sizeof(m))
#define max(a, b) (a ^ ((a ^ b) & -(a < b)))
#define LEFT 1
#define RIGHT 0
//-------------------------------------------------------------------------
int dp1[10000];
//-------------------------------------------------------------------------
void _INIT() { memset(dp1, -1, sizeof(dp1)); }
//-------------------------------------------------------------------------
int valid(char *nome) {
    int ans = 1, i = 0;
    while (nome[i] != '\0' && ans) {
        if(((nome[i] & 0xF0) == 0x30) && (nome[i] & 0x0F) <= 0x09)
            ans = 0;
        ++i;
    }
    return ans > 0 ? 1 : 0;
}
//-------------------------------------------------------------------------
temp* _Creater(int number, int eps, int year, char *rating) {
    temp *no = ALOCAR(temp);
    no->numero = number;
    no->qtd_episodios = eps;
    no->ano = year;
    no->h = 0;
    strcpy(no->titulo, rating);
    no->l = no->r = NULL;
    return (no);
}
//-------------------------------------------------------------------------
int height2(temp *no) { return (!no) ? -1 : no->h; };
//-------------------------------------------------------------------------
void rotate2(temp **no, int dir) {
	temp *new = dir ? (*no)->r : (*no)->l;
	if (dir) {
		(*no)->r = new->l;
		new->l = *no;
	} else {
		(*no)->l = new->r;
		new->r = *no;
	}
	(*no)->h = 1 + max(height2((*no)->l), height2((*no)->r));
	new->h = 1 + max(height2(new->l), height2(new->r));
	*no = new;
}
//-------------------------------------------------------------------------
void insert_tree(temp **no, int number, int eps, int year, char *rating) {
    if(!(*no)) {
        *no = _Creater(number, eps, year, rating);
        dp1[(*no)->numero] = 1;
        //return;
    }
    if (number < (*no)->numero) {
        insert_tree(&(*no)->l, number, eps, year, rating);
        if (height2((*no)->l) - height2((*no)->r) == 2) {
            if (number < (*no)->l->numero) {
                rotate2(no, RIGHT);
            } else {
                rotate2(&(*no)->l, LEFT);
                rotate2(no, RIGHT);
            }
    }
    } else if (number > (*no)->numero) {
        insert_tree(&(*no)->r, number, eps, year, rating);
        if (height2((*no)->r) - height2((*no)->l) == 2) {
            if (number > (*no)->r->numero) {
                rotate2(no, LEFT);
            } else {
                rotate2(&(*no)->r, RIGHT);
                rotate2(no, LEFT);
            }
        }
    }
    (*no)->h = 1 + max(height2((*no)->l), height2((*no)->r));
}
//-------------------------------------------------------------------------
void imprimir(temp *no) {
    if (no) {
        imprimir(no->l);
        printf("%d - %d - %d %s\n", no->numero, no->qtd_episodios, no->ano, no->titulo);
        imprimir_participantes(no->participantes);
        imprimir(no->r);
    }
}
//-------------------------------------------------------------------------
int existe_temp(int num) { return (dp1[num] != -1) ? 1 : 0; }
//-------------------------------------------------------------------------
void search_binary(temp *no, int num, int opc) {
    if (!existe_temp(num) || !no) {
        printf("Informe uma temporada valida ou cadastre uma\n");
        return;
    }
    if (no->numero == num) {
        int error = 1, artista = 1, personagem = 1;
        char nomea[50], nomep[50], d[200];
        switch(opc) {
            case 3:
                while (error != 0) {
                    printf("Informe o nome do artista:\n"); scanf("%s", nomea);
                    if (!valid(nomea)) artista = 0;
                    fflush(stdin);
                    printf("Informe o nome do personagem:\n"); scanf("%s", nomep);
                    if (!valid(nomep)) personagem = 0;
                    printf("Informe a descricao:\n");
                    fflush(stdin);
                    scanf("%[^\n]s", d);
                    if (valid(nomea) && valid(nomep)) {
                        error = 0;
                        insertAndSort(&no->participantes, nomea, nomep, d);
                    } else {
                        printf("Ops algo deu errado!\n");
                        printf((!artista) ? "Insira apenas letras no campo artista!\n"
                            : ((!personagem) ? "Informe apenas letras no campo personagem!\n"
                            : "Informe letras no campos artistas e personagens!\n"));
                        artista = personagem = 1;
                    }
                }
                break;
            case 6:
                if (!(no->participantes)) {
                    printf("Acao nao concluida, eh nescessario adicionar participantes\n");
                } else {
                    printf("Personagens -\n");
                    imprimir_personagens(no->participantes);
                }
                break;
        }
    } else {
        if (num < no->numero) {
            search_binary(no->l, num, opc);
        } else if (num > no->numero) {
            search_binary(no->r, num, opc);
        }
    }
}
//-------------------------------------------------------------------------
void traversal(temp *no, char *nick) {
    if (no) {
        traversal(no->l, nick);
        imprimir_artista(no->participantes, nick);
        traversal(no->r, nick);
    }
}
//-------------------------------------------------------------------------
void liberar_temporada(temp *no) {
	if (no) {
		liberar_temporada(no->l);
        liberar_participantes(no->participantes);
		free(no);
		liberar_temporada(no->r);
	}
}
