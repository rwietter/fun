#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* lista;
};

struct Node* copia(struct Node* l, struct Node* listaCP);
struct Node* insert(struct Node* lista, int v);
void display(struct Node* lista, struct Node* listaCP);

int main(int argc, char const *argv[])
{
	struct Node* lista = (struct Node*)malloc(sizeof(struct Node));
	struct Node* listaCP = (struct Node*)malloc(sizeof(struct Node));
	lista = NULL;
	lista = insert(lista, 1);
	lista = insert(lista, 9);
	lista = insert(lista, 2);
	lista = insert(lista, 3);
	listaCP = copia(lista, listaCP);
	//display(lista, listaCP);
	return 0;
}

struct Node* insert(struct Node* lista, int v){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = v;
	newNode->next = lista;
	return newNode;
}

struct Node* copia(struct Node* l, struct Node* listaCP){
	while (l != NULL)
	{
		listaCP->data = l->data;
		printf("--> %d ", l->data);
		l = l->next;
		printf("--> %d \n", listaCP->data);
	}
	return listaCP;
}

void display(struct Node* lista, struct Node* listaCP){
	struct Node* newNode = lista;
	while (newNode != NULL)
	{
		printf("--> %d lista original \n", lista->data);
		printf("--> %d lista copia \n", listaCP->data);
		newNode = newNode->next;
	}
}

/*Problema 2
Exercício: Implemente uma função que crie uma cópia de uma lista encadeada. O protótipo da função deve
ser dado por:*/
