#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>

using namespace std;

#define MAX 100

int iniciar(void); /* inicia a pilha */
void push(int elem); /* empilha elem */
int pop(void); /* desempilha um elemento, que e' o resultado */
int vazia(void); /* testa se pilha esta' vazia */
void show(void); /* imprime os elementos da pilha, entre colchetes, em
uma única linha, em ordem, a partir do topo */

struct pilha{
	int TOPO; /* número de elementos na pilha */
	int vet[MAX]; /* vetor com os elementos da pilha */
};
typedef struct pilha Pilha;

int iniciar(){
	Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
	novo->TOPO = 0;
}

void push(int elem){
	int i;
	Pilha* p;
	p->TOPO++;
	p->vet[p->TOPO] = elem;

}

int vazia(){
	Pilha* p;
	if (p->TOPO == -1){
		return 1;
	}
}

int pop(){
	int aux;
	Pilha* p;
	if (vazia() == 1){
		return 1;
	}
	aux = p->vet[p->TOPO];
	p->TOPO--;
	return aux;
}

/*
void show(){
	Pilha* p;
	if (p->vet[p->TOPO] != )
	{
		printf("%d -> ", p->vet[p->TOPO]);
		p->TOPO++;
		show();
	}
}
*/

int main(void){
	int a,b;
	iniciar();
	push(3); push(4); push(5); push(6);
	printf("%d\n", a = pop());
	printf("%d\n", b = pop());
	push(a+b);
	printf("%d\n", a = pop());
	push(a*pop());
	printf("%d", pop());
	return 0;
}
