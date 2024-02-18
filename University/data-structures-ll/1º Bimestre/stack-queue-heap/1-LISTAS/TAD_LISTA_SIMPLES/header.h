typedef struct lista Lista;

Lista* inicializa (void);

Lista* insere (Lista* l, int i);

void imprime (Lista* l);

int vazia (Lista* l);

Lista* busca (Lista* l, int v);

Lista* retira (Lista* l, int v);

void libera (Lista* l);

int main (Lista* l);
