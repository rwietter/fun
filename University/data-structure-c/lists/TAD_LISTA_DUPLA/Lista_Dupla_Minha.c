/* Doubly Linked List implementation */
#include <stdio.h>
#include <stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
}*inicio = NULL; // global variable - pointer to inicio node.

//Creates a new Node and returns pointer to it. 
struct Node* ObterNovoNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InserirNoInicio(int x) {
	struct Node* newNode = ObterNovoNode(x); // Chama a função para inserir
	if(inicio == NULL) {
		inicio = newNode;
		return;
	}
	inicio->prev = newNode;
	newNode->next = inicio;
	inicio = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InserirNoFinal(int x) {
	struct Node* temp = inicio;
	struct Node* newNode = ObterNovoNode(x);
	if(inicio == NULL) {
		inicio = newNode;
		return;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void Print() {
	struct Node* temp = inicio;
	printf(" <- NULL - HEAD -> ");
	while(temp != NULL) {
		printf("| PREV <- %d -> NEXT ",temp->data);
		temp = temp->next;
	}
	printf("-> NULL --------> ");
}

int main() {
	inicio = NULL; // empty list. set inicio as NULL. 
	
	InserirNoFinal(2); Print(); printf("Elemento inserido no final\n\n");
	InserirNoFinal(4); Print(); printf("Elemento inserido no final\n\n");
	InserirNoInicio(6); Print(); printf("Elemento inserido no início\n\n");
	InserirNoInicio(7); Print(); printf("Elemento inserido no início\n\n");
	InserirNoInicio(8); Print(); printf("Elemento inserido no início\n\n");
	InserirNoFinal(9); Print(); printf("Elemento inserido no final\n\n");
}
