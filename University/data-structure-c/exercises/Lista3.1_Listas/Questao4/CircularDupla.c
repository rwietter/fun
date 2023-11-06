#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
}*head;

struct Node* insert(struct Node* l, int data){
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = l;
  if (head == NULL){
    head = newNode;
    newNode->next = head;
  }else{
    struct Node* temp = head;
    while (temp->next != head)
    {
      temp = temp->next;
    }
    newNode->next = head;
    head = newNode;
    temp->next = head;
  }
  return newNode;
}

struct Node* remover(struct Node* l){
  struct Node* p;
  if (head == NULL){
    printf("Lista vazia");
  }else{
    struct Node* temp1 = head, *temp2;
    while (temp1->next != head)
    {
      temp2 = temp1;
      temp1 = temp1->next;
    }
    temp2->next = head;
    free(temp1);
  }
  return l;
}

void display(struct Node* l){
  while(l->next != head){
    printf("%d -> ", l->data);
    l = l->next;
  }
}

void imprime_circular_rev (struct Node* l)
{
  struct Node* p = l; 
  do {
  printf("%d\n", p->data); 
  p = p->prev;
  } while (p != l);
}

int main(){
  struct Node* lista = NULL;
  lista = insert(lista, 1); lista = insert(lista, 2);
  lista = insert(lista, 3); lista = insert(lista, 4);
  display(lista);
  remover(lista); printf("\n");
  display(lista);

  printf("\n");
  imprime_circular_rev(lista);
}

/*Problema 4
Escreva as funções para inserir e retirar um elemento de
uma lista circular duplamente encadeada.*/
