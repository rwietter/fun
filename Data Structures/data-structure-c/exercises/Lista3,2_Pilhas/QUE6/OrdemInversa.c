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
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->top = NULL;
	return newStack;
}

Node* insertInTop(Node* top, int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = top;
	return newNode;
}

void push(Stack* p, int data){
	p->top = insertInTop(p->top, data);
}

Node* pop()
{
	Stack* p;
	Node* temp;
	Node* corre = p->top;
	if (p->top == NULL)
	{
		printf("Pilha vazia");
	}
	else
	{
		while (corre != NULL)
		{
			if (corre->next == NULL)
			{
				temp = p->top;
				p->top = temp->next;
				printf("Elemento deletado %d\n", temp->data);
				free(temp);
			}
			temp = p->top;
			p->top = temp->next;
			printf("Elemento deletado %d\n", temp->data);
			free(temp);
			corre = corre->next;
		}
	}
	return temp;
}

void displayStack(){
	Node* l;
	Stack* p;
	l = p->top;
	while ( l != NULL)
	{
		printf("%d\n", l->data);
		l = l->next;
	}
	printf("\n");
}

int main()
{
	Stack* p1;
	p1 = createStack();
	push(p1, 12); push(p1, 13); push(p1, 14);
	displayStack();
	pop();
	displayStack();
	return 0;
}


/*
Problema 6
Utilizando uma pilha resolver o exercício a seguir: dada uma sequência contendo N (N >0) números reais,
imprimi-la na ordem inversa.
*/
