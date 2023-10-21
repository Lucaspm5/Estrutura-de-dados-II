typedef struct participantes Participantes;

void insert(Participantes** lista, char *nome_artista, char *nome_personagem, char *descricao);
Participantes* encontrar_participante(Participantes *no, char *nome_artista);
Participantes* criar(char *nome_artista, char *nome_personagem, char *descricao);
Participantes* sort(Participantes* head);