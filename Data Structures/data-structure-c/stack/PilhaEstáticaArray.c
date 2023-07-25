#include <stdio.h>
#include <stdlib.h>
#define TAM 100

struct pilha{
	int info[TAM];
	int TOPO;
};
typedef struct pilha Stack;

int PILHA_INICIA(Stack* p);
int PILHA_VAZIA(Stack* p);
int STACK_OVERFLOW(Stack* p);
int PILHA_REMOVE(Stack* p, int y);
void PILHA_INSERE(Stack* p, int y);
int PILHA_SAIDA(Stack* p);


int main() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	PILHA_INICIA(stack);

	PILHA_INSERE(stack, 22);
	PILHA_INSERE(stack, 23);
	PILHA_INSERE(stack, 24);
	PILHA_INSERE(stack, 25);

	printf("\nElemento do topo %d\n", stack->info[stack->TOPO]);
	PILHA_REMOVE(stack, 25);
	printf("Elemento do topo %d\n", stack->info[stack->TOPO]);

	if (PILHA_VAZIA(stack) == 1)
	{
		printf("\nPilha está vazia\n");
	}
	if(STACK_OVERFLOW(stack) == 1){
		printf("\nPilha está cheia\n");
	}
	return 0;
}

int PILHA_INICIA(Stack* p){
	p->TOPO = -1; // indica que a pilha está vazia
	return p;
}

int PILHA_VAZIA(Stack* p){
	if (p->TOPO == -1)
	{
		return 1;
	}
}

int STACK_OVERFLOW(Stack* p){
	if (p->TOPO == TAM-1)
	{
		return 1;
	}
}

void PILHA_INSERE(Stack* p, int y){
	if (STACK_OVERFLOW(p)==1)
	{
		printf("Pilha está cheia");
	}
	p->TOPO++;
	p->info[p->TOPO] = y;
}

int PILHA_REMOVE(Stack* p, int y){
	int aux;
	if (PILHA_VAZIA(p) == 1)
	{
		return 1;
	}
	aux = p->info[p->TOPO];
	p->TOPO--;
	return aux;
}

int PILHA_SAIDA(Stack* p){
	return p->info[p->TOPO];
}
