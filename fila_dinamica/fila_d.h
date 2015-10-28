struct dados{
    int x;
};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int insere_Fila(Fila* fi, struct dados valor);
int remove_Fila(Fila* fi);
