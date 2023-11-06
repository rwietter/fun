#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
}Node;

typedef struct stack {
  Node* top;
}Stack;

Stack* criaPilha(); // aloca memória
Node* insertInTop(Node* l, int v); // auxiliar para adicionar no topo
void pushStack(Stack* p, int v); // chama a função InsereNoInicio e adiciona no topo
int pop(int v);
int stackNull();

Stack* createStack()
{
  Stack* createAllocStack = (Stack*) malloc(sizeof(Stack));
  createAllocStack->top = NULL;
  return createAllocStack;
}

void pushStack(Stack* p, int v){
  p->top = insertInTop(p->top, v);
}

Node* insertInTop(Node* l, int v){
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = v;
  newNode->next = l;
  return newNode;
}

int stackNull(Stack* newStack){
  if (newStack->top == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void displayStack(){
  Node* p;
  Stack* stk;
  p = stk->top;
  while (p != NULL)
  {
    printf("%d -> ", p->data);
    p = p->next;
  } 
}

void MaiorStack(Stack* stack){
  Node* node = stack->top;
  Node* maior = (Node*) malloc(sizeof(Node));
  maior->data = node->data;
  while (node != NULL)
  {
    if (node->data > maior->data)
    {
      maior->data = node->data;
    }
    node = node->next;
  }
  printf("\nMaior da Stack: < %d > ", maior->data);
}

int main()
{
  Stack* newStack;
  Node* newNode;
  newStack = createStack();
  pushStack(newStack, 1); pushStack(newStack, 55); pushStack(newStack, 2); pushStack(newStack, 3);
  displayStack(newStack);
  MaiorStack(newStack);
  return 0;
}
