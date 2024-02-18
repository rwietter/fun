#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

int quant;

Node* inicializa(void){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode = NULL;
	return newNode;
}

int isEmpity(Node* newNode){
	if (newNode == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Node* insertInLinkedList(Node* node, int data){
	quant += 1;
	Node* novoNode = (Node*) malloc(sizeof(Node));
	novoNode->data = data;
	novoNode->next = node;
	return novoNode;
}

void display(){
	Node* l;
	while (l != NULL)
	{
		printf("%d -> ", l->data);
		l = l->next;
	}
}

Node* Inverte(Node* sort, Node* newNode){
	int vet[quant];
	printf("%d", quant);
	int aux=0;
	int pos = -1;
	Node* nd = newNode;
	while (nd != NULL)
	{
		pos++;
		aux = vet[pos+1];
		vet[pos+1] = aux;
		printf("\n%d", vet[pos]);
		nd = nd->next;
	}
	return vet;
}

int main(int argc, char const *argv[])
{
	Node* newNode = (Node*) malloc(sizeof(Node));
	Node* sort = (Node*) malloc(sizeof(Node));
	sort = inicializa();
	newNode = inicializa();
	if (isEmpity(newNode) == 1)
		printf("Lista vazia\n");
	newNode = insertInLinkedList(newNode, 1);
	newNode = insertInLinkedList(newNode, 2);
	newNode = insertInLinkedList(newNode, 3);
	display();
	sort = Inverte(sort, newNode);
	return 0;
}


/*
Problema 3
Escreva uma função que inverte L1, colocando o resultado em L2. Faça versões estáticas e dinâmicas do
código.
*/
