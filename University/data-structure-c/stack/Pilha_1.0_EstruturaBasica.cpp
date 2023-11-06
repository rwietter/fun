#include <iostream>
#include <stdlib.h>
using namespace std;

// +++++++++++++++++++++++++ DEFININDO STRUCTS ++++++++++++++++++++++++++ //
typedef struct no {
	int info;
  struct no* prox;
}No;

typedef struct pilha {
	No* prim;
}Pilha;

int PilhaContador;

// +++++++++++++++++++++++++++ ABSTRAÇÃO ++++++++++++++++++++++++++++++++ //
Pilha* criaPilha(); // aloca memória
No* InsereNoInicio(No* l, int v); // auxiliar para adicionar no topo
void push(Pilha* p, int v); // chama a função InsereNoInicio e adiciona no topo
bool pop(int v);
int pilha_vazia();


// ++++++++++++++++++++++++++ CRIA PILHA ++++++++++++++++++++++++++++++++ //
Pilha* criaPilha(void){
	Pilha* topo = (Pilha*) malloc(sizeof(Pilha));
	topo->prim = NULL;
	return topo;
}

// ++++++++++++++++++++++++ INSERE NO INÍCIO +++++++++++++++++++++++++++++ //
No* InsereNoInicio(No* l, int v)
{
	Pilha* top;
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;  /* função auxiliar: insere no início */
	return p;
}

// ++++++++++++++++++++++++ EMPILHA NO TOPO +++++++++++++++++++++++++++++ //
void push(Pilha* p, int v)
{
	p->prim = InsereNoInicio(p->prim, v); // As funções que manipulam a pilha fazem uso dessas funções de lista:
}

// ++++++++++++++++++++++++ DESEMPILHA A PILHA ++++++++++++++++++++++++++ //
int PilhaPop(int v)
{
	Pilha* top;
	Pilha* temp;
	if (top == NULL)
	{
		printf("Pilha vazia");
	}
	else
	{
		temp = top;
		printf("\nElemento deletado %d", temp->prim);
	}
	return 1;
}

// +++++++++++++++++++++++++ IMPRIME A PILHA ++++++++++++++++++++++++++++ //
int imprime() {
	No* node;
	Pilha* p1;
	node=p1->prim;
	do
	{
		printf("%d\n", node->info);
		node=node->prox;	
	} while (node != NULL);	   
	return 1;
}

bool PilhaGet() // OBTÉM O ELEMENTO DO TOPO DA PILHA
{
  int valor=0;
  No* node;
  Pilha* p;
	if (pilha_vazia())
	{
		return true;
	}
	else
	{
		node=p->prim;
		do
    		{
     		valor = node->info;
     		node=node->prox;
    		} while (node == NULL);
	}
	printf("Valor do topo da pilha: %d\n", valor);
	return true;
}

// ++++++++++++++++++++++ VERIFICA SE ESTÁ VÁZIA ++++++++++++++++++++++++++ //
int pilha_vazia(){
	No* i;
	Pilha* p;
	if (p->prim == NULL)
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
  No* node; Pilha* p1; Pilha* p2;

  p1 = criaPilha();

  if((pilha_vazia())==1){
    printf("Pilha vazia\n");
  }else{
    printf("Pilha não vazia\n");
  }
    
  push(p1, 12); push(p1, 13); push(p1, 14);

  imprime(); PilhaGet();
  imprime();

  pilha_vazia();
  return 0;
}

// retornar por referência usa-se &
