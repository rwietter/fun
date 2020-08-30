/*
Problema 3
Escreva as funções para inserir e retirar um elemento de uma lista circular.
*/


#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct lista {
		int info;
		struct lista* prox;
	};

typedef struct lista Lista;

Lista* retiracircular(Lista* l1, int i) {
  
}

int igual (Lista *l1, Lista *l2) {
  Lista *p_11;
  Lista *p_12;
  int fim;
  p_11 = l1;
  p_12 = l2;
  do {
		if (p_11->info == p_12->info){
			printf("Está lista: %d, é igual está lista:\n%d", p_11->info, p_12->info);
			p_11 = p_11->prox;
			p_12 = p_12->prox;
		}else{
			printf("Está lista: %d, não é igual está lista: %d\n", p_11->info, p_12->info);
			return -1;
		}
		if (p_11 == NULL){
			fim = 1;
		}
		if (p_12 == NULL){
			fim = 1;
		}
	}while(fim != 1);
}

/* insere no inicio: retorna a lista atualizada */
Lista* insere (Lista* l, int i) 
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->info = i; 
	novo->prox = l; 
	return novo;
}

void imprime (Lista* l)
{
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
	puts("");
}

int vazia (Lista* l)
{
	if (l == NULL)
		return 1;
	else
		return 0;
}

Lista* busca (Lista* l, int v)
{
	Lista* p;
	
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL; 
}

Lista* retira (Lista* l, int v) {
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l; /* ponteiro para percorrer a lista*/

	while (p != NULL && p->info != v) /* procura elemento na lista, guardando anterior */ {
		ant = p;
		p = p->prox;
	}
	if (p == NULL) /* verifica se achou elemento */
		return l; /* não achou: retorna lista original */
	if (ant == NULL) /* retira elemento */ {
		l = p->prox; /* retira elemento do inicio */
	}	
	else {
		ant->prox = p->prox; /* retira elemento do meio da lista */
	}
	free(p);
	return l;
}

void libera (Lista* l)
{
	Lista* p = l;

	while (p != NULL) {
		Lista* t = p->prox; /* guarda referência para o próximo elemento */
	
		free(p); /* libera a memória apontada por p */ // deixar de apontar para tal memória  
		p = t; /* faz p apontar para o próximo */
	}
}

int main () {
	Lista* l1 = NULL;
  Lista* l2 = NULL;
	
  l1 = insere(l1, 23); l1 = insere(l1, 45); 
	l1 = insere(l1, 56); 

  l2 = insere(l2, 23); l2 = insere(l2, 45); 
	l2 = insere(l2, 56); 
	
  imprime(l1); imprime(l2);
	
	l1 = retira(l1, 78); l2 = retira(l2, 78);
	
	imprime(l1); imprime(l2);
	
	l1 = retira(l1, 45); l2 = retira(l2, 45);
	
	imprime(l1); imprime(l2);
	
	libera(l1); libera(l2);
  
	int x = igual (l1, l2);
  
	retiracircular(l1, 23);
	return 0;
}
