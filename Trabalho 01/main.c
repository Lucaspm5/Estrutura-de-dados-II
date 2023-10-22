#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "participante.h"
#include "temporadas.h"

#define p printf
#define s scanf
#define q "\n"
//--------------------------------------------------------------------
void menu() {
    p("1 - Adicionar Temporadas\n");
    p("2 - Adicionar Participantes\n");
    p("3 - Imprimir todos os personagens de uma determinada temporada\n");
    p("(-1) para sair\n\n");
}
//--------------------------------------------------------------------
int main() {
    temp *no = NULL;
    int opc, numb, qntd_eps, ano;
    char tit[50];
    do {
        menu();
        p("Selecione a opc:\n");
        s("%d", &opc);
        switch(opc) {
            case 1:
                p("Informe o numero da temporada, ");
                p("a quantidade de episodios, o ano:\n");
                s("%d %d %d", &numb, &qntd_eps, &ano);
                p("Informe o titulo:\n");
                s(" %[^\n]", tit);
                insert_tree(&no, numb, qntd_eps, ano, tit);
                break;
            case 2:
                p("Informe a temporada:"); s("%d", &numb);
                p("\n");
                search_binary(no, numb, opc);
                break;
            case 3:
                p("Informe a temporada:"); s("%d", &numb);
                search_binary(no, numb, opc);
                break;
        }
    } while (opc != -1);
    return 0;
}
