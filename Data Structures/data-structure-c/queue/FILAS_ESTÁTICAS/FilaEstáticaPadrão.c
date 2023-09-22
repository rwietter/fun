#include <stdio.h>
#include <stdlib.h>

// - Inserções ocorrem no final da fila;
// - Exclusões ocorrem no início da fila;

/*
Operação de enfileiramento:
O Enfileirar é usado para adicionar um elemento à fila.
O elemento sempre é adicionado ao final dos itens da fila atual.

Operação de desenfileiramento
A remoção da fila é usada para remover um elemento da fila.
O elemento sempre é removido da frente da fila.
*/

#define SIZE 10

typedef struct fila {
	int ini, fim;
	int vet[SIZE];
}Fila;

Fila* createQueue(){
	Fila* novaFila = (Fila*)malloc(sizeof(Fila));
	novaFila->ini = novaFila->fim = 0;
	return novaFila;
}

int incrementa(int i){
	if (i == SIZE-1)
	{
		return 0;
	}
	else
	{
		return i+1;
	}
}

void insertQueue(Fila* fila, int value){
	if (incrementa(fila->fim) == SIZE-1)
	{
		printf("\nStackoverflow");
		exit(1);
	}
	else
	{
		fila->vet[fila->fim] = value; // INSERE
		fila->fim = incrementa(fila->fim); // PRÓXIMA POSIÇÃO
	}
}

void display(Fila* f){
	int i;
	for ( i = f->ini; i != f->fim; i = incrementa(i))
	{
		printf("%d -> ", f->vet[i]);
	}
}

int filaVazia(Fila* f){
	if (f->fim == f->ini)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int remover(Fila* f){
	int aux;
	if (filaVazia(f)==1)
	{
		printf("Fila vazia\n");
		exit(1);
	}
	aux = f->vet[f->ini];
	f->ini = incrementa(f->ini);
	return aux;
}


int main()
{
	Fila* novaFila;
	novaFila = createQueue();
	insertQueue(novaFila, 1); insertQueue(novaFila, 2); insertQueue(novaFila, 3);
	display(novaFila);
	remover(novaFila);
	printf("\n");
	display(novaFila);
	return 0;
}
