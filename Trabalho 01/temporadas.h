typedef struct Temporada temp;

void insert_tree(temp **r, int number, int eps, int year, char *rating);
temp* _Creater(int number, int eps, int year, char *rating);
void search_binary(temp *no, int num, int opc);
int existe_temp(int num);
int _Validtemp(temp *no);
void imprimir(temp *no);
void traversal(temp *no, char *nick);