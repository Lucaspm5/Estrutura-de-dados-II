typedef struct participantes Participantes;

void insert(Participantes** lista, char *nome_artista, char *nome_personagem, char *descricao);
void imprimir(Participantes* lista);
Participante* encontrar_participante(Participante *no, char *nome_artista);
