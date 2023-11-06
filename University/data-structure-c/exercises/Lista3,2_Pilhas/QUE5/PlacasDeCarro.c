#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct stack {
	Node* top;
}Stack;

Stack* createStack(void){
	Stack* newStack = (Stack*) malloc(sizeof(Stack));
	newStack->top = NULL;
	return newStack;
}

Node* insertInTop(Node* node, int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = node;
	return newNode;
}

void push(Stack* stk, int data){
	stk->top = insertInTop(stk->top, data);
}

void display(void){
	Node* p;
	Stack* topper;
	p = topper->top;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p -> next;
	}
}

Stack* hasStackSpace(Stack* stk, Stack* stk2){
	Node* p = stk->top;
	Node* st = (Node*)malloc(sizeof(Node));
	st = stk2->top;
	int placa;
	printf("\nQual a placa? "); scanf("%d", &placa);
	printf("\nA sequencia de carros que precisam sair, são, respectivamente:\n");
	while (p != NULL)
	{
		if (p->data == placa)
		{
			while (p != NULL)
			{
				Node* st = (Node*)malloc(sizeof(Node));
				st = p->next;
				p = p->next;
				printf("%d\n", st->data);
			}
		}
		p = p->next;
	}
	return st;
}

int main(int argc, char const *argv[])
{
	Stack* newStack = (Stack*) malloc(sizeof(Stack));
	Stack* newStack2 = (Stack*) malloc(sizeof(Stack));
	newStack = createStack();
	newStack2 = createStack();
	push(newStack, 1365);
	push(newStack, 2432);
	push(newStack, 3785);
	push(newStack, 4721);
	display();
	newStack2 = hasStackSpace(newStack, newStack2);
	Node* p = newStack2;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	return 0;
}



/*
Problema 5
Construa um programa utilizando uma pilha que resolva o seguinte problema: armazene as placas dos carros
(apenas os números) que estão estacionados numa estreita rua sem saída. Dado uma placa verifique se o carro
está estacionado na rua. Caso esteja, informe a sequência de carros que deverá ser retirada para que o carro
em questão consiga sair.
*/
