#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
}Node;

typedef struct stack {
  Node* top;
}Stack;

Stack* createStack(); // aloca memória
Node* insertInTop(Node* l, int v); // auxiliar para adicionar no topo
Stack* pushStack(Stack* p, int v); // chama a função InsereNoInicio e adiciona no topo
int pop(int v);
int stackNull();
void equalsStacks(newStack1, newStack2);

int main()
{
  Stack* newStack1;
  Stack* newStack2;
  newStack1 = createStack();
  newStack2 = createStack();
  newStack1 = pushStack(newStack1, 1); newStack1 = pushStack(newStack1, 2); newStack1 = pushStack(newStack1, 3);
  newStack2 = pushStack(newStack2, 1); newStack2 = pushStack(newStack2, 2); newStack2 = pushStack(newStack2, 3);
  equalsStacks(newStack1, newStack2);
  return 0;
}

Stack* createStack()
{
  Stack* createAllocStack = (Stack*) malloc(sizeof(Stack));
  createAllocStack->top = NULL;
  return createAllocStack;
}

Stack* pushStack(Stack* p, int v){
  p->top = insertInTop(p->top, v);
  return p;
}

Node* insertInTop(Node* l, int v){
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = v;
  newNode->next = l;
  return newNode;
}

void equalsStacks(Stack* stk1, Stack* stk2){
  Node* node1 = stk1->top;
  Node* node2 = stk2->top;
  while ((node1 != NULL) || (node2 != NULL))
  {
    if (node1->data == node2->data)
    {
      if ((node1->next == NULL) || (node2->next == NULL))
      {
        printf("As pilhas são iguais");
      }
    }
    else if (node1->data != node2->data)
      {
        printf("As pilhas são diferentes");
        exit(1);
      }
    node1 = node1->next;
    node2 = node2->next;
  }
}
