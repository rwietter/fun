#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};
typedef struct Node node;

node* insert(node* l, int v){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = v;
  newNode->next = l;
  return newNode;
}

node* LinkedListCopy(node* Lista1, node* Lista2, node* Lista3){
	node* l1 = Lista1;
	node* l2 = Lista2;
	node* l3 = (node*) malloc(sizeof(node));
	do
	{
		node* l3 = (node*) malloc(sizeof(node));
		l3->data = l1->data;
		l1 = l1->next;
		l3 = l3->next;
	}while ((l1 != NULL));

	while (l3 != NULL)
	{
		printf("%d", l3->data);
		l3 = l3->next;
	}
	return l3;
}

void display(node* l){
	node* p = l;
	while (p != NULL)
	{
		printf("%d -> ", p->data);
		p = p->next;
	}
}

int main()
{
	node* Lista1 = (node*)malloc(sizeof(node));
	node* Lista2 = (node*)malloc(sizeof(node));
	node* Lista3 = (node*)malloc(sizeof(node));

	Lista1 =  insert(Lista1, 1); Lista1 =  insert(Lista1, 2); Lista1 =  insert(Lista1, 3);
	Lista2 =  insert(Lista2, 4); Lista2 =  insert(Lista2, 5); Lista2 =  insert(Lista2, 6);

	Lista3 = LinkedListCopy(Lista1, Lista2, Lista3);
	display(Lista3);
	return 0;
}



/*Problema 2
Escreva uma função que receba duas Listas (L1 e L2), intercale-as gerando uma terceira Lista, L3. Faça
versões estáticas e dinâmicas do código.*/
