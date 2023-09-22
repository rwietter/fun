//Escrever uma função que receba como parâmetro uma pilha. 
//A função deve retornar o maior elemento da pilha. 
//A passagem deve ser por valor ou referência?

#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

// O nó da lista para armazenar valores reais pode ser dado por:
struct no {
	float info;
	struct no* prox;
};
typedef struct no No;

// A estrutura da pilha é então simplesmente:
struct pilha {
	No* prim;
};
typedef struct pilha Pilha;

// A função cria aloca a estrutura da pilha e inicializa a lista como sendo vazia.
Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

// O primeiro elemento da lista representa o topo da pilha. Cada novo elemento é inserido
// no início da lista e, conseqüentemente, sempre que solicitado, retiramos o elemento
// também do início da lista. Desta forma, precisamos de duas funções auxiliares da lista:
// para inserir no início e para remover do início. Ambas as funções retornam o novo
// primeiro nó da lista.

/* função auxiliar: insere no início */
No* ins_ini (No* l, float v)
{
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

// As funções que manipulam a pilha fazem uso dessas funções de lista:
void push (Pilha* p, float v)
{
	p->prim = ins_ini(p->prim,v);
}

//Escrever uma função que receba como parâmetro uma pilha. 
//A função deve retornar o maior elemento da pilha. 
//A passagem deve ser por valor ou referência?
float maior_da_pilha (Pilha* p) {
	No* q;
	printf("\nImprime:\n");
	float maior = p->prim->info;
	
	q=p->prim;
	do {
		//printf("%f\n",q->info);
		if (q->info > maior)
			maior = q->info;
		q=q->prox;
	} while (q!=NULL);	   
	return maior;
}

main () {
	Pilha *p;
	p = cria();
	push(p, 4);
	push(p, 6);
	push(p, 8);
	printf("\nO maior elemento da pilha eh %f", maior_da_pilha (p));
}

		//printf("%f\n",q->info);
	/*do {
		int aux = pop(p);
	} while (p != NULL);*/

