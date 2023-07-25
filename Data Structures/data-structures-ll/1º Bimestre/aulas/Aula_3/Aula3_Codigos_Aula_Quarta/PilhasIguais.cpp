#include <stdlib.h> 
#include <stdio.h>

struct no {
	float info;
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

No* ins_ini (No* l, float v)
{
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

void push (Pilha* p, float v)
{
	p->prim = ins_ini(p->prim,v);
}

int sao_iguais(Pilha* np1, Pilha* np2) {
	No* q1;
	No* q2;
	
	q1=np1->prim;
	q2=np2->prim;
	do {
		if (q1 == NULL)	
			return 0;
		if (q2 == NULL)				
			return 0;
		printf("-> %.2f -> %.2f\n", q1->info, q2->info);			
		if (q1->info != q2->info) {
			puts("\nSAINDO...");
			return 0;
		}
		q1=q1->prox;	
		q2=q2->prox;	
	} while ((q1!=NULL) || (q2!=NULL));	   
	return 1;
}

main () {
	Pilha *p1;
	p1 = cria();
	push(p1, 4); push(p1, 6); push(p1, 8);
	
	Pilha *p2;
	p2 = cria();
	push(p2, 4); push(p2, 4); push(p2, 8);

	if (sao_iguais(p1, p2) == 1)
		puts("\nSAO IGUAIS!");
	else
		puts("\nNAO SAO IGUAIS!");
}

//Problema 3
//Escreva uma fun��o que receba como par�metro duas pilhas e verifique se elas s�o iguais. 
