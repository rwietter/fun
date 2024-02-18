
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct lista {
		int info;
		struct lista* prox;
	};

typedef struct lista Lista;

Lista* copia (Lista* l) {
	Lista* ant;
	Lista* prim;
	Lista* p;
	
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	prim = novo;
	novo->info = l->info;
	l->prox;
	ant = novo;
	do {
		Lista* novo = (Lista*) malloc(sizeof(Lista));
		novo->info = l->info;
		ant->prox = novo;
		l->prox;
	} while (l == NULL);
	novo->prox = NULL;
	for (p = prim; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);	
}

int igual (Lista* l1, Lista* l2) {
	Lista *p_l1;
	Lista *p_l2;
	int fim = 0;
	p_l1 = l1;
	p_l2 = l2;
	do {
		if (p_l1->info == p_l2->info) {
			printf("\n%d %d", p_l1->info, p_l2->info);
			p_l1 = p_l1->prox;
			p_l2 = p_l2->prox;
		}
		else {
			printf("\n%d %d", p_l1->info, p_l2->info);
			return -1;
		}
		if (p_l1 == NULL)
			fim = 1;
		if (p_l2 == NULL)
			fim = 1;	
	} while (fim != 1);
}


/* função de inicialização: retorna uma lista vazia */
Lista* inicializa (void)
{
	return NULL;
}

// l = inicializa(); /* inicia lista vazia */


/* inserção no início: retorna a lista atualizada */
Lista* insere (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->info = i;
	novo->prox = l;
	return novo;
}

/* função imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
	Lista* p; /* variável auxiliar para percorrer a lista */
	
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
	puts("");
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int vazia (Lista* l)
{
	if (l == NULL)
		return 1;
	else
		return 0;
}

/* função busca: busca um elemento na lista */
Lista* busca (Lista* l, int v)
{
	Lista* p;
	
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL; /* não achou o elemento */
}

/* função retira: retira elemento da lista */
Lista* retira (Lista* l, int v) {
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l; /* ponteiro para percorrer a lista*/

	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}
	
	/* verifica se achou elemento */
	if (p == NULL)
		return l; /* não achou: retorna lista original */
	/* retira elemento */
	if (ant == NULL) {
		/* retira elemento do inicio */
		l = p->prox;
	}	
	else {
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

void libera (Lista* l)
{
	Lista* p = l;

	while (p != NULL) {
		Lista* t = p->prox; /* guarda referência para o próximo elemento */
	
		free(p); /* libera a memória apontada por p */
		p = t; /* faz p apontar para o próximo */
	}
}

int main (void) {
	Lista* l1;
	Lista* l2; /* declara uma lista não iniciada */
	l1 = inicializa(); /* inicia lista vazia */
	l2 = inicializa(); /* inicia lista vazia */

	//l1 = insere(l1, 23); /* insere na lista o elemento 23 */
	l1 = insere(l1, 45); /* insere na lista o elemento 45 */
	l1 = insere(l1, 56); /* insere na lista o elemento 56 */
	l1 = insere(l1, 87); /* insere na lista o elemento 78 */
	
	l2 = insere(l2, 23); /* insere na lista o elemento 23 */
	l2 = insere(l2, 45); /* insere na lista o elemento 45 */
	l2 = insere(l2, 56); /* insere na lista o elemento 56 */
	l2 = insere(l2, 78); /* insere na lista o elemento 78 */


	imprime(l1); /* imprimirá: 78 56 45 23 */
	imprime(l2); /* imprimirá: 78 56 45 23 */
	
	/*int x = igual (l1, l2); 
	if (x == -1)
		puts("PROBLEMAS!");		*/

	copia(l1);
	
	libera(l1);
	libera(l2);
	return 0;
}
