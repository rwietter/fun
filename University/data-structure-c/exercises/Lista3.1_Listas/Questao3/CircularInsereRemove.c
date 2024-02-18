#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}*head = NULL;

struct Node* insert(struct Node* l, int d){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = d;
	newNode->next = l;
	if (head == NULL){
		head = newNode;
		newNode->next = head;
	}else{
		struct Node* temp = head;
		while (temp->next != head){
			temp = temp->next;
		}
		newNode->next = head;
		head = newNode;
		temp->next = head;
	}
	return newNode;
}

struct Node* removerInicio(struct Node* l){
	struct Node* newNode = l;
	if (newNode->prev == NULL){
		l = newNode->next; // salva a lista de 3 -> 2 -> 1
	}
	free(newNode); // deleta o nó 4
	printf("\nNode deletado no início\n");
	return l;
}

struct Node* removerFinal(struct Node* l){
	struct Node *temp1 = head, *temp2;
	if(head == NULL)
		printf("Lista vazia");
	else{
		while(temp1->next != head){
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = head;
		free(temp1);
		printf("\nNó eliminado no fim\n");
	}
	return l;
}

void displayEnd(struct Node* l){
	printf("NULL <-");
	while(l->next != head){
		printf(" %d ->", l->data);
		l = l->next;
	}
	printf(" NULL ");
}

void displayHead(struct Node* l){
	printf("NULL <-");
	while(l->next != head){
		printf(" %d ->", l->data);
		l = l->next;
	}
	printf(" NULL ");
}

int main() {
	struct Node* lista = NULL;
	lista = insert(lista, 1); lista = insert(lista, 2);
	lista = insert(lista, 3); lista = insert(lista, 4);
	lista = insert(lista, 5); lista = insert(lista, 6);
	lista = insert(lista, 7); lista = insert(lista, 8);

	displayEnd(lista);
	lista = removerFinal(lista);
	displayEnd(lista); printf(" <--- remove o primeiro elemento inserido");

	printf("\n\n");

	displayHead(lista);
	lista = removerInicio(lista);
	displayHead(lista);
	printf(" <-- remove o último elemento inserido\n");
	return 0;
}
