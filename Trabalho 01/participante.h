typedef struct participantes Participantes;

void insertparticipantes(Participantes** lista, char *nome_artista, char *nome_personagem, char *descricao);
void imprimir_participantes(Participantes* lista);
Participantes* encontrar_participante(Participantes *no, char *nome_artista);
Participantes* criar(char *nome_artista, char *nome_personagem, char *descricao);
Participantes* sort(Participantes* head);
int _Validparticipantes(Participantes *no);