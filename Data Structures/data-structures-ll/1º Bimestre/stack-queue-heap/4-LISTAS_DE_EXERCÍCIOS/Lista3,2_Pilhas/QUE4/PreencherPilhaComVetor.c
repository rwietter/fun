#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct stack {
	int data[MAX];
	int top;
}Stack;

int createStack(Stack* p);
int stackNull(Stack* p);
int stackOverflow(Stack* p);
int insertInStack(Stack* p, int *vet[]);

int main()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	Stack* stk;
	int vet[MAX] = {1,2,3,4,5};
	createStack(stack);
	insertInStack(stack, vet);
	insertInStack(stack, vet);
	insertInStack(stack, vet);
	display(stack);
	return 0;
}

int createStack(Stack* stk){
	stk->top = -1;
	return stk;
}

int stackNull(Stack* stk){
	if (stk->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int stackOverflow(Stack* p){
	if (p->top == MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int insertInStack(Stack* p, int *vet[]){
	p->top++;
	p->data[p->top] = vet[p->top];
	printf("%d\n", p->data[p->top]);
}

void display(Stack* stk){
}




/*Problema 4
Escreva uma função que preencha uma pilha passada como parâmetro com os elementos de um vetor passado
como parâmetro.*/












/*
typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct stack {
	Node* top;
}Stack;

Stack* createStack(){
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->top = NULL;
	return newStack;
}

Node* insertInHead(Node* l, int *value[]){
	Node* newNode = (Node*)malloc(sizeof(Node));
	int i=0;
	newNode->data = value[i+3];
	printf("%d\n", value[i]);
	newNode->next = l;
	return newNode;
}

void pushStack(Stack* stk, int *value[]){
	stk->top = insertInHead(stk, value);
}

void display(Stack* stk){
	Node* p = stk;
	while (p != NULL)
	{
		printf("%d -> ", p->data);
		p = p->next;
	}
}

int main()
{
	Stack* newStack;
	newStack = createStack();
	int vet[3] = {1,2,4};
	pushStack(newStack, vet);
	pushStack(newStack, vet);
	pushStack(newStack, vet);
	display(newStack);
	return 0;
}
*/

/*
Problema 4
Escreva uma função que preencha uma pilha passada como parâmetro com os elementos de um vetor passado
como parâmetro.
*/
