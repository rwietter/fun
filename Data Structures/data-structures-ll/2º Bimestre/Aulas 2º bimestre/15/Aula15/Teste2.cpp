
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct lista {
		int info;
		struct lista* ant;
		struct lista* prox;
	};

typedef struct lista Lista;

Lista* cria(int info) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = info;
	novo->ant = NULL;
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
	novo->ant = aux1;
}

void mostra(Lista* l) {
	Lista* aux;
	for(aux=l;aux!=NULL;aux=aux->prox)
		printf("\n%d",aux->info);
}

void mostra_inv(Lista* l) {
	Lista* aux;
	Lista* aux1;
	for(aux=l;aux!=NULL;aux=aux->prox)
		aux1 = aux;
	for(aux=aux1;aux!=NULL;aux=aux->ant)
		printf("\n%d",aux->info);
}

Lista* busca(int info) {
	Lista* aux;
	for(aux=l;aux!=NULL;aux=aux->prox)
		if(aux->info == info)
			return aux;
	return NULL;		
}

main() {
	Lista* l = cria(10);
	insere(l,20);
	mostra_inv(l);
	insere(l,30);
	mostra_inv(l);
	insere(l,40);
	mostra_inv(l);
	Lista* l1 = busca(30);
	Lista* l2 = cria(35);
	Lista* aux;
	for(aux=l;aux!=NULL;aux=aux->prox)
		if(aux->info == info) {  // 30
			l->prox->ant = l2; // 40
			l2->prox = l->prox;
			l->prox = l2; // 30
			l2->ant = l1;
		}
}


