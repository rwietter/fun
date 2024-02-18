
#include <stdlib.h> 
#include <stdio.h> 

struct lista {
		int info;
		struct lista* prox;
	};

typedef struct lista Lista;

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
	Lista* ant = NULL; 
	Lista* p = l; 
	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}
	if (p == NULL)
		return l;
	if (ant == NULL) {
		l = p->prox;
	}	
	else {
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

void libera (Lista* l)
{
	Lista* p = l;
	while (p != NULL) {
		Lista* t = p->prox; 
		free(p); 
		p = t; 
	}
}

Lista* cria (int v)
{
	Lista* p = (Lista*) malloc(sizeof(Lista));
	
	p->info = v;
	return p;
}

Lista* insere_ordenado (Lista* l, int v)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v; 
	Lista* ant = NULL; 
	Lista* p = l;
	while (p != NULL && p->info < v) {
		ant = p;
		p = p->prox;
	}if (ant == NULL) { 
		novo->prox = l;
		l = novo;
	}else{ 
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return l;
}

int main (void) {
	Lista* l; /* declara uma lista n�o iniciada */
	l = NULL; /* inicia lista vazia */
	l = insere_ordenado(l, 1); /* insere na lista o elemento 23 */
	l = insere_ordenado(l, 2); /* insere na lista o elemento 45 */
	l = insere_ordenado(l, 1); /* insere na lista o elemento 56 */
	l = insere_ordenado(l, 2); /* insere na lista o elemento 78 */
	imprime(l); /* imprimir�: 78 56 45 23 */
	l = retira(l, 78);
	imprime(l); /* imprimir�: 56 45 23 */
	l = retira(l, 45);
	imprime(l); /* imprimir�: 56 23 */
	libera(l);
	return 0;
}
