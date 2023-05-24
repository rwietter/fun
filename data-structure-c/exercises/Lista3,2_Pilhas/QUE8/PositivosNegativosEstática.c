#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct pilha {
	int top;
	int vet[TAM];
}Pilha;

Pilha* createStack(){
	Pilha* new = (Pilha*)malloc(sizeof(Pilha));
	new->top = 0;
	return new;
}

void TPilha2(Pilha* n, Pilha* p, int *vet){
	Pilha* k = (Pilha*)malloc(sizeof(Pilha));
	Pilha* z = (Pilha*)malloc(sizeof(Pilha));
	k = n;
	z = p;
	int i, j, aux=0;
	for ( i = 0; i < 5; i++)
	{
		if (vet[i] > 0)
		{
			z->top++;
			z->vet[z->top] = vet[i];
		}
		else if (vet[i] < 0)
		{
			k->top++;
			k->vet[k->top] = vet[i];
		}
		else if (vet[i] == 0)
		{
			aux = z->vet[z->top];
			z->top--;
			printf("\nRemovido de p: %d\n", aux);
			aux = k->vet[k->top];
			k->top--;
			printf("\nRemovido de n: %d\n", aux);
		}
	}
	printf("\nPilha N negativos: \n");
	for ( i = k->top; i != 0; i--)
	{
		printf("%d\n",k->vet[k->top]);
	}
	printf("\nPilha P positivos: \n");
	for ( i = z->top; i != 0; i--)
	{
		printf("%d\n",z->vet[z->top]);
	}
}

void display(Pilha* p1){
	int i;
	Pilha* p = p1;
	for ( i = p->top; i != 0; i--)
	{
		printf("%d\n", p->vet[i]);
	}
}

int main()
{
	int vet[5] = {-1,0,-2,4,6};
	Pilha* n;
	Pilha* p;
	Pilha* r;
	int i;
	n = createStack();
	p = createStack();
	TPilha2(n, p, vet);
	display(p);
	return 1;
}


/*
Problema 8
Escreva uma função chamada TPilha2 que recebe como parâmetro 2 pilhas (N e P) e um vetor de inteiros.
Para cada um deles, como segue, faça:
se positivo, inserir na pilha P;
se negativo, inserir na pilha N;
se zero, retirar um elemento de cada pilha.
*/
