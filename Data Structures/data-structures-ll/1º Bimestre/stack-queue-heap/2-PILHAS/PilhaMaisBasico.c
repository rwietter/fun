#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* prox;
}*top = NULL;

typedef struct node Node;

void push(int v){
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = v;
  if (top == NULL)
  {
    newNode->prox = NULL;
  }else{
    newNode->prox = top;
  }
  top = newNode;
  printf("\nInserção feita com sucesso");
}

int pop(){
  Node* temporario;
  if (top==NULL)
  {
    printf("Pilha vazia");
  }else{
    temporario = top;
    top = temporario->prox;
    printf("\nElemento %d removido com sucesso", temporario->data);
    free(temporario);
  }
}

void display(){
  Node* temporario;
  Node* newNode = top;
  if (top == NULL)
  {
    printf("\nPilha vazia\n");
  }else{
    temporario = top;
    printf("\n\n");
    while (temporario != NULL)
    {
      printf("---> %d", newNode->data);
      temporario = temporario->prox;
      newNode = newNode->prox;
    }
  }
}

void main(){
  push(22); push(23); push(24);
  push(25); push(26); display();
  pop(26); display(); pop(25);
  display();
}
