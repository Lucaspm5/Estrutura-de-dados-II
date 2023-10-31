#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "series.h"
#include "participante.h"
#include "temporadas.h"

//--------------------------------------------------------------------
void menu() {
    printf("(1) - Adicionar Serie\n");
    printf("(2) - Adicionar Temporada\n");
    printf("(3) - Adicionar Participantes\n");
    printf("(4) - Imprimir o titulo, o numero de temporadas\n");
    printf("(5) - Imprimir os dados de todas as temporadas de uma serie\n");
    printf("(6) - Imprimir todos os personagens de uma determinada temporada\n");
    printf("(7) - Imprimir o nome de todos os artistas que interpretaram um determinado personagem\n");
    printf("(-1) para sair\n\n");
}
//--------------------------------------------------------------------
int main() {
    Series *pointer = NULL;
    temp *no = NULL;
    char titulo[50], tit[50];
    int opc, numb, qntd_eps, ano, codigo, num_temp;
    do {
        menu();
        printf("Selecione a opc:\n");
        scanf("%d", &opc);
        switch(opc) {
            case 1:
                printf("Informe o codigo, num_temporadas, titulo:\n");
                scanf("%d %d %s", &codigo, &num_temp, titulo);
                inserir_serie(&pointer, codigo, num_temp, titulo);
                break;
            case 2:
                printf("Informe o codigo da serie a qual voce deseja inserir uma temporada:\n");
                scanf("%d", &codigo);
                search_Tree(pointer, codigo, numb, opc);
                break;
            case 3:
                printf("Informe o codigo da serie e o numero da temporada:\n");
                scanf("%d %d", &codigo, &numb);
                search_Tree(pointer, codigo, numb, opc);
                break;
            case 4:
                printf("Informe o codigo da serie:\n");
                scanf("%d", &codigo);
                search_Tree(pointer, codigo, numb, opc);
                break;
            case 5:
                search_Tree(pointer, codigo, numb, opc);
                break;
            case 6:
                printf("Informe o codigo da serie e o numero da temporada:\n");
                scanf("%d %d", &codigo, &numb);
                search_Tree(pointer, codigo, numb, opc);
                break;
            case 7:
                printf("Informe o codigo da serie:\n");
                scanf("%d %d", &codigo);
                search_Tree(pointer, codigo, numb, opc);
                break;
        }
    } while (opc != -1);
    return 0;
}