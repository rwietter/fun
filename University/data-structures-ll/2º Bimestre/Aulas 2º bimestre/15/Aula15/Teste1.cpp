
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct lista {
		int info;
		struct lista* prox;
	};

typedef struct lista Lista;

Lista* cria(int info) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = info;
	novo->prox = NULL;
	return novo;
}

void insere(Lista* l, int info) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = info;
	novo->prox = NULL;
	Lista* aux;
	Lista* aux1;
	for(aux=l;aux!=NULL;aux=aux->prox)
		aux1 = aux;
	aux1->prox = novo;
}

void mostra(Lista* l) {
	Lista* aux;
	for(aux=l;aux!=NULL;aux=aux->prox)
		printf("\n%d",aux->info);
}
main() {
	Lista* l = cria(10);
	insere(l,20);
	mostra(l);
	insere(l,30);
	mostra(l);
	insere(l,40);
	mostra(l);
}


