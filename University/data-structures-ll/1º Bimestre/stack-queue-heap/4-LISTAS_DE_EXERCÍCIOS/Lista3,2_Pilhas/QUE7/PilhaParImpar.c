/*Implemente uma função chamada TPilha, que receba um vetor de inteiros com 15 elementos. Para cada um deles, como segue, faça:
se o número for par, insira-o na pilha;
se o número lido for ímpar, retire um número da pilha;
Ao final, esvazie a pilha imprimindo os elementos.*/

#include <stdlib.h>
#include <stdio.h>

struct no {
	int info;
	struct no* prox;
};
typedef struct no No;

struct pilha {
	No* prim;
};
typedef struct pilha Pilha;

Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

No* ins_ini (No* l, int v)
{
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

No* ret_ini (No* l)
{
	No* p = l->prox;
	free(l);
	return p;
}

void push (Pilha* p, int v)
{
	p->prim = ins_ini(p->prim,v);
}

int pop (Pilha* p)
{
	int v;
	v = p->prim->info;
	p->prim = ret_ini(p->prim);
	return v;
}

void TPilha (Pilha *p, int *v)
{
	int i;
		for(i=0;i<15;i++)
		{
			if(v[i]%2==0)
			{
				push(p,v[i]);
			}
				if(v[i]%2!=0)
				{
					pop(p);
				}
		}
}

void imprime (Pilha* p)
{
	No* q;
	printf("\nImprime:\n");
	for (q=p->prim; q!=NULL; q=q->prox)
		printf("%d\n",q->info);
}

int main(){
	Pilha *p;
	int v[15]={2,4,5,6,8,6,4,2,5,3,1,4,8,4,5};

	p = cria();
	TPilha(p,v);
	imprime(p);
}
