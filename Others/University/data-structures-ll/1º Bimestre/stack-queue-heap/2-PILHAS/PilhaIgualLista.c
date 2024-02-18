#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
}*Top = NULL;

typedef struct Node Node;

struct pilha{
  Node* prim;
};
typedef struct pilha Pilha;

Node* inserte(Pilha* p, int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = p;
  printf("Inserção feita com sucesso\n");
  return newNode;
}

void display(){
  Node* temporario;
  Node* newNode = Top;
  if (Top == NULL)
  {
    printf("\nPilha vazia\n");
  }else{
    printf("\n\n");
    while (newNode != NULL)
    {
      printf("---> %d", newNode->data);
      newNode = newNode->next;
    }
  }
}

int Iguais(Pilha* np1, Pilha* np2) {
	Node* q1;
	Node* q2;
	
	q1 = np1->prim;
	q2 = np2->prim;
	do {
		if (q1 == NULL)	
			return 0;
		if (q2 == NULL)				
			return 0;
		printf("Lista 1: %d\nLista 2: %d\n", q1->data, q2->data);			
		if (q1->data != q2->data) {
			puts("\nSAINDO...");
			return 0;
		}
		q1=q1->next;	
		q2=q2->next;	
	} while ((q1!=NULL) || (q2!=NULL));	   
	return 1;
}

Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

void insert(Pilha* p, int v)
{
	p->prim = inserte(p->prim, v);
}

int main()
{
  Pilha* newNode;
  Pilha* newNodeB;
  newNode = cria();
  newNodeB = cria();
  insert(newNode, 4);
  insert(newNode, 6);
  insert(newNode, 7);
  insert(newNodeB, 4);
  insert(newNodeB, 6);
  insert(newNodeB, 7);
	if (Iguais(newNode, newNodeB) == 1)
		puts("\nSAO IGUAIS!");
	else
		puts("\nNÂO SAO IGUAIS!");
  display();
  return 0;
}
