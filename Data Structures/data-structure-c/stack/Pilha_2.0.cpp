#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct no {
  int info;
  struct no* prox;
}No;

typedef struct pilha {
  No* topo;
}Pilha;

Pilha* criaPilha(){
  Pilha* top = (Pilha*) malloc(sizeof(Pilha));
  top->topo = NULL;
  return top;
}

No* empilha(No* l, int y) {
  No* p = (No*) malloc(sizeof(No));
  p->info = y;
  p->prox = l;
  return p;
}

// As fun��es que manipulam a pilha fazem uso dessas fun��es de lista:
void push (Pilha* p, float v)
{
	p->topo = empilha(p->topo, v);
}

void imprime(void) {
  No* p;
  Pilha* ob;
}

// ------------------------------------------------------------------------------------------------------- //
//                                                        COMPARAÇÃO
// ------------------------------------------------------------------------------------------------------- //
int sao_iguais(Pilha* pl1, Pilha* pl2) {
	No* PrimeiroNo;
	No* SegundoNo;
	PrimeiroNo=pl1->topo;
	SegundoNo=pl2->topo;
	do {
		if (PrimeiroNo == NULL)
    {
			return 0;
    }
		if (SegundoNo == NULL)
    {
			return 0;
    }			
		printf("%d\n%d\n", PrimeiroNo->info, SegundoNo->info);			
    if (PrimeiroNo->info != SegundoNo->info) {
			puts("SAINDO...");
			return 0;
		}
		PrimeiroNo=PrimeiroNo->prox;	
		SegundoNo=SegundoNo->prox;	
	} while ((PrimeiroNo!=NULL) || (SegundoNo!=NULL));
	return 1;
}

int main()
{
  Pilha* p1;
  p1 = criaPilha();
  push(p1, 12);
  push(p1, 13);
  push(p1, 14);

  Pilha* p2;
  p2 = criaPilha();
  push(p2, 12);
  push(p2, 13);
  push(p2, 14);
  //imprime();

  	if (sao_iguais(p1, p2) == 1)
		puts("\nSAO IGUAIS!");
	else
		puts("\nNAO SAO IGUAIS!");
  return 0;
}
