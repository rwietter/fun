#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
}*top = NULL;
typedef struct node Node;

Node* insert(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  if (top == NULL)
  {
    newNode->next = NULL;
  }
  else
  {
    newNode->next = top;
  }
  top = newNode;
  return newNode;
}

void display(Node* stack){
  Node* p = stack;
  while (p != NULL)
  {
    printf("%d -> ", p->data);
    p = p->next;
  }
}

int GrandTheAuto(Node* stack){
  Node* p = top;
  Node* maior = (Node*)malloc(sizeof(Node));
  maior->data = p->data;
  while ( p != NULL )
  {
    if (p->data > maior->data)
    {
      maior->data = p->data;
    }
    p = p->next;
  }
  printf("%d", maior->data);
  return maior;
}

int main(int argc, char const *argv[])
{
  Node* newNode;
  Node* maior;
  newNode = insert(6); newNode = insert(8); newNode = insert(4);
  //display(newNode);
  GrandTheAuto(newNode);
  return 0;
}


/*Problema 2
Escrever uma função que receba como parâmetro uma pilha. A função deve retornar o maior elemento da
pilha. A passagem deve ser por valor ou referência?*/
