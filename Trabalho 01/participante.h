typedef struct Participante {
    char nome_artista[50], nome_personagem[50], descricao[100];
    struct Participante *next;
} Participante;

Participante* inserir_participante(Participante *no, char *nome_artista, char *nome_personagem, char *descricao);
void imprimir_participantes(Participante *no);
Participante* encontrar_participante(Participante *no, char *nome_artista);


