#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
}*Top = NULL;

typedef struct Node Node;

Node* insert(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (Top == NULL)
	{
		newNode->next = NULL;
	}
	else
	{
		newNode->next = Top;
	}
	Top = newNode;
	printf("Inserção feita com sucesso\n");
	return newNode;
}

void display(Node* p1, Node* p2)
{
	Node* newNode = Top;
	if (Top == NULL)
	{
		printf("\nPilha vazia\n");
	}
	else
	{
		printf("\n\n");
		while (newNode != NULL){
			printf("-> %d -> %d\n", p1->data, p2->data);
			newNode = newNode->next;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
}

int Equals(Node* p1, Node* p2) {
	Node* temp1 = p1;
	Node* temp2 = p2;
	while ((temp1 != NULL) || (temp2 != NULL))
	{
	if (temp1->data == temp2->data)
	{
		if ((temp1->next == NULL) || (temp2->next == NULL))
		{
			return 1;
		}
	}
	else if (temp1->data != temp2->data)
	{
		return 0;
	}
	temp1 = temp1->next;
	temp2 = temp2->next;
	}
}

int main()
{
	Node* newNode; Node* newNodeB;

	newNode = insert(1); newNode = insert(2); newNode = insert(3);
	newNodeB = insert(1); newNodeB = insert(2); newNodeB = insert(3);

	Equals(newNode, newNodeB);

	if(Equals(newNode, newNodeB)==1)
	{
		printf("\nAs pilhas são iguais");
		display(newNode, newNodeB);
	}
	else
	{
		printf("\nAs pilhas são diferentes");
		display(newNode, newNodeB);
	}
}

/*
Problema 3
Escreva uma função que receba como parâmetro duas pilhas e verifique se elas são iguais.
*/
