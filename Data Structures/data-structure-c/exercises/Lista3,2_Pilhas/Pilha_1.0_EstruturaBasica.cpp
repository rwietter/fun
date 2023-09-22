#include <stdlib.h>
#include <stdio.h>

// +++++++++++++++++++++++++ DEFININDO STRUCTS ++++++++++++++++++++++++++ //
typedef struct node {
	int data;
  struct node* next;
}Node;

typedef struct stack {
	Node* top;
}Stack;

int PilhaContador;

// +++++++++++++++++++++++++++ ABSTRAÇÃO ++++++++++++++++++++++++++++++++ //
Stack* createStack(); // aloca memória
Node* insertInTop(Node* l, int v); // auxiliar para adicionar no topo
void push(Node* p, int v); // chama a função insertInTop e adiciona no topo
Node* pop(int v);
int stackIsImpity();


// ++++++++++++++++++++++++++ CRIA PILHA ++++++++++++++++++++++++++++++++ //
Stack* createStack(void){
	Stack* newStack = (Stack*) malloc(sizeof(Stack));
	newStack->top = NULL;
	return newStack;
}

// ++++++++++++++++++++++++ INSERE NO INÍCIO +++++++++++++++++++++++++++++ //
Node* insertInTop(Node* l, int v)
{
	Node* p = (Node*) malloc(sizeof(Node));
	p->data = v;
	p->next = l;  /* função auxiliar: insere no início */
	return p;
}

// ++++++++++++++++++++++++ EMPILHA NO TOPO +++++++++++++++++++++++++++++ //
void push(Stack* p, int v)
{
	p->top = insertInTop(p->top, v); // As funções que manipulam a pilha fazem uso dessas funções de lista:
}

// ++++++++++++++++++++++++ DESEMPILHA A PILHA ++++++++++++++++++++++++++ //
Node* pop()
{
	Stack* p;
	Node* temp;
	if (p->top == NULL)
	{
		printf("Pilha vazia");
	}
	else
	{
		temp = p->top;
		p->top = temp->next;
		printf("\nElemento deletado %d\n", temp->data);
	}
	free(temp);
	return temp;
}

// +++++++++++++++++++++++++ IMPRIME A PILHA ++++++++++++++++++++++++++++ //
int imprime() {
	Node* node;
	Stack* p1;
	node = p1->top;
	do
	{
		printf("%d\n", node->data);
		node = node->next;
	} while (node != NULL);
	return 1;
}

bool PilhaGet() // OBTÉM O ELEMENTO DO TOPO DA PILHA
{
  int valor=0;
  Node* node;
  Stack* p;
	if (stackIsImpity())
	{
		return 1;
	}
	else
	{
		node = p->top;
		do
    		{
     		valor = node->data;
     		node = node->next;
    		} while (node == NULL);
	}
	printf("Valor do topo da pilha: %d\n", valor);
	return 1;
}

// ++++++++++++++++++++++ VERIFICA SE ESTÁ VÁZIA ++++++++++++++++++++++++++ //
int stackIsImpity(){
	Node* i;
	Stack* p;
	if (p->top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 1;
}

// ++++++++++++++++++++++++++++++ MAIN +++++++++++++++++++++++++++++++++ //
int main()
{
  int valor;
  Node* node;
  Stack* p1;
  Stack* p2;

  p1 = createStack();

  if((stackIsImpity())==1){
    printf("Pilha vazia\n");
  }else{
    printf("Pilha não vazia\n");
  }

  push(p1, 12); push(p1, 13); push(p1, 14);

  imprime();
  //PilhaGet();
  pop();
  imprime();
  return 0;
}

// retornar por referência usa-se &
