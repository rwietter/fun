// Problema 2
// Escreva uma função que receba duas Listas (L1 e L2), intercale-as 
// gerando uma terceira Lista, L3. Faça versões estáticas e dinâmicas 
// do código.

#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct lista {
		int info;
		struct lista* prox;
	};

typedef struct lista Lista;

/* função de inicialização: retorna uma lista vazia */
Lista* inicializa (void)
{
	return NULL;
}

/* inserção no início: retorna a lista atualizada */
Lista* insere (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->info = i;
	novo->prox = l;
	return novo;
}

Lista* intercala(Lista* l1, Lista* l2) {
	Lista* aux1 = l1;
	Lista* aux2 = l2;
	Lista* l3;
	
	do {
		if (aux1 != NULL) {	
			l3 = insere(l3, aux1->info);
			aux1 = aux1->prox;
		}
		
		if (aux2 != NULL) {
			l3 = insere(l3, aux2->info);
			aux2 = aux2->prox;
		}	
	} while ((aux1 != NULL) || (aux2 != NULL));
	
	return l3;
}

/* função imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
	Lista* p; /* variável auxiliar para percorrer a lista */
	
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
	
}

main() {
	Lista* l1;
	l1 = inicializa();
	l1 = insere(l1, 1);
	l1 = insere(l1, 2);
	l1 = insere(l1, 3);
	l1 = insere(l1, 4);
	l1 = insere(l1, 5);
	imprime(l1);
	Lista* l2;
	l2 = inicializa();
 	l2 = insere(l2, 6);
	l2 = insere(l2, 7);
	l2 = insere(l2, 8);
	l2 = insere(l2, 9);
	l2 = insere(l2, 10);
	imprime(l2);
	Lista* l3;
	l3 = inicializa();
	l3 = intercala(l1, l2);
	imprime(l3);
}
