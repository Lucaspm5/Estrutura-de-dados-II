typedef struct participantes Participantes;

void insert(Participantes** lista, char *nome_artista, char *nome_personagem, char *descricao);
void imprimir(Participantes* lista);
Participantes* encontrar_participante(Participante *no, char *nome_artista);
Participantes* criar(char *nome_artista, char *nome_personagem, char *descricao);
Participantes* sort(Participantes* head);
Participantes* _Creater();
Participantes* _Init();
