// LISTA DUPLAMENTE ENCADEADA
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct lista {
	int info;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* insere (Lista* l, int i) /* insersão no início: retorna a lista atualizada */{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void imprime(Lista* l){
	Lista* Node;
   if(l == NULL){
      printf("\nLista está vazia\n");
   }else{
      Lista* temp = l;
      printf("\n\nOs elementos da lista são: \n");
      while(temp->prox != NULL){
        printf("%d --> ",temp->info);
        temp = temp->prox;
      }
      printf("%d ---> NULL",temp->info);
   }
}

int vazia (Lista* l){
	if (l == NULL)
		return 1;
	else
		return 0;
}

Lista* busca (Lista* l, int v){
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
	if (ant == NULL) { /* retira elemento */
		l = p->prox; /* retira elemento do inicio */
	}else{
		ant->prox = p->prox; /* retira elemento do meio da lista */
	}
	free(p);
	return l;
}

void libera (Lista* l){
	Lista* p = l;
	while (p != NULL) {
		Lista* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento */
		free(p); /* libera a memória apontada por p */
		p = t; /* faz p apontar para o próximo */
	}
}

int main (void) {
	Lista* l; /* declara uma lista não iniciada */
	l = insere(l, 23); /* insere na lista o elemento 23 */
	l = insere(l, 45); /* insere na lista o elemento 45 */
	l = insere(l, 56); /* insere na lista o elemento 56 */
	l = insere(l, 78); /* insere na lista o elemento 78 */
	printf("\nLista completa\n");
	imprime(l); /* imprimir: 78 56 45 23 */
	l = retira(l, 78);
	printf("\nElemento 78 removido\n");
	imprime(l); /* imprimir: 56 45 23 */
	l = retira(l, 23);
	printf("\nElemento 23 removido\n");
	imprime(l); /* imprimir: 56 23 */
	libera(l);
	return 0;
}
