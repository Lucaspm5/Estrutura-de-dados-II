typedef struct participantes Participantes;

typedef unsigned short int USI;

void imprimir_participantes(Participantes* no);
int _Validparticipantes(Participantes *no);
void insertAndSort(Participantes **head, char *nome_artista, char *nome_personagem, char *descricao);
void imprimir_artista(Participantes *no, char *personagem);