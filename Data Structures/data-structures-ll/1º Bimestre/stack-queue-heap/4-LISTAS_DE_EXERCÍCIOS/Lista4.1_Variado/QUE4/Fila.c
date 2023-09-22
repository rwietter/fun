#include <stdio.h>

typedef struct no {
	int info;
	struct no* prox;
}No;

typedef struct pilha {
	No* topo;
}Pilha;

typedef struct fila
{
	No* inicio;
	No* fim;
}Fila;

Pilha* createPilha(void);
Fila* criaFila(void);
No* enfileira(No* f, int data);
void display();

int main(int argc, char const *argv[])
{
	Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));

	No* no = (No*)malloc(sizeof(No)); novaPilha = createPilha();
	Fila* novaFila = (Fila*)malloc(sizeof(Fila)); novaFila = criaFila();
	novaFila = enfileira(novaFila, 22);
	novaFila = enfileira(novaFila, 23);
	novaFila = enfileira(novaFila, 24);
	display();
	return 0;
}

Pilha* createPilha(void)
{
	Pilha* newPilha = (Pilha*)malloc(sizeof(Pilha));
	newPilha->topo = NULL;
	return newPilha;
}

Fila* criaFila(void)
{
	Fila* novaFila = (Fila*)malloc(sizeof(Fila));
	novaFila->inicio = NULL;
	novaFila->fim = NULL;
	return novaFila;
}

No* enfileira(No* f, int data)
{
	No* novoNo = (No*) malloc(sizeof(No));
	Fila* f1;
	novoNo->info = data;
	novoNo->prox = NULL;
	if (f1->inicio == NULL)
	{
		f1->inicio = novoNo; // novo no será o primeiro elemento da lista
	}
	else
	{
		f1->fim->prox = novoNo; // ultimo nó aponta para novo nó
	}
	f1->fim = novoNo; // fim indica um novo nó
	return novoNo;
}

void display()
{
	Fila* f1;
	No* p = f1->inicio;
	while ( p != NULL)
	{
		printf("%d\n", p->info);
		p = p->prox;
	}
}

Fila* desinfileira()
{
	Fila* f1;
	No* node = f1->inicio;

}

/*
Problema 4
Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas os testes de fila e pilha vazias, as
operações Enfileira, Desenfileira, Empilha, Desempilha, e uma variável aux do TipoItem, escreva uma função
que inverta a ordem dos elementos da fila.
*/
