#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
  struct Node* prev;
}*head = NULL;
typedef struct Node Lista;

Lista* ObterNovoNode(int x) {
	Lista* newNode = (Lista*)malloc(sizeof(Lista));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InserirNoInicio(int x) {
	Lista* newNode = ObterNovoNode(x); // Chama a função para inserir
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

Lista* cria(){
  Lista* newNode = (Lista*)malloc(sizeof(Lista));
  newNode = NULL;
  return newNode;
}

void display(){
  Lista* wh;
  while (wh != NULL)
  {
    printf("-> %d ->", wh->data);
    wh = wh->next;
  }
}

Lista* DoublyLinkedListOrder(Lista* l, int data){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->data = data; 
	Lista* ant = NULL; 
	Lista* p = l;
  while ( p != NULL && novo->data < data )
  {
    ant = p;
    p = p->next;
  }if (ant != NULL)
  {
    novo->next = l;
    l = novo;
  }else{
    novo->next = ant->next;
    ant->next = novo;
  }
  return l;
}

int main()
{
  Lista* Lista = NULL;
  Lista = cria();
  Lista = DoublyLinkedListOrder(Lista, 4);
  Lista = DoublyLinkedListOrder(Lista, 6);
  Lista = DoublyLinkedListOrder(Lista, 2);
  Lista = DoublyLinkedListOrder(Lista, 8);
  display();
  return 0;
}


/*
Problema 5
Escreva a função ”???? insere_ordenado (????)” para uma lista duplamente encadeada.
*/
