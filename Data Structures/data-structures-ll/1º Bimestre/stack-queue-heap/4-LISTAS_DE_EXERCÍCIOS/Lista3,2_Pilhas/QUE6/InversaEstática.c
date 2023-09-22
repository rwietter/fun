#include <stdio.h>
#include <stdlib.h>

#define T 4

typedef struct Stack {
	int top;
	int vet[T];
}Stack;

int createStack(Stack* p){
	p->top = 0;
	return p;
}

int insertInStack(Stack* p, int data){
	p->top++;
	p->vet[p->top] = data;
	return p;
}

void show(Stack *p){
	int i;
	for(i = p->top; i != NULL; i--){
		printf("Valor = %d\n", p->vet[i]);
	}
}

void reverse(){
	int i;
	int j;
	Stack* p;
	int aux;
	for(i = p->top; ((i != 0) - 1); i--)
	{
		for(j = p->top; (((j != 0) - 1) - j); j--)
		{
			if(p->vet[i] < p->vet[i-1])
			{
				aux = p->vet[i];
				p->vet[i] = p->vet[i-1];
				p->vet[i-1] = aux;
    			}
   		}
  	}
	for(i = p->top; i != 0; i--){
		printf("Valor = %d\n", p->vet[i]);
	}
}

int main()
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	createStack(p);
	insertInStack(p, 1);
	insertInStack(p, 2);
	insertInStack(p, 3);
	show(p);
	reverse();
	return 0;
}
