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
      }
      else
      {
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

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista* inicializa (void)
{
	return NULL;
}

/* inser��o no in�cio: retorna a lista atualizada */
Lista* insere (Lista* l, int i) 
{
	// guarda o valor de memória antiga, e aloca uma nova memória trocando o valor por referência
	Lista* novo = (Lista*) malloc(sizeof(Lista)); // cria valor a memória para novo
	
	novo->info = i; // 23
	novo->prox = l; // vale null; novo aponta pra l e l aponta pra próxima
	return novo; // retorna o a memória e o 23, l retorna para o novo
}

/* fun��o imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
	Lista* p; /* vari�vel auxiliar para percorrer a lista */
	
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
	puts("");
}

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int vazia (Lista* l)
{
	if (l == NULL)
		return 1;
	else
		return 0;
}

/* fun��o busca: busca um elemento na lista */
Lista* busca (Lista* l, int v)
{
	Lista* p;
	
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL; /* n�o achou o elemento */
}

/* fun��o retira: retira elemento da lista */
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
		return l; /* n�o achou: retorna lista original */
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
		Lista* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento */
	
		free(p); /* libera a mem�ria apontada por p */ // deixar de apontar para tal memória  
		p = t; /* faz p apontar para o pr�ximo */
	}
}

int main () {
	Lista* l1;
  Lista* l2; /* declara uma lista n�o iniciada */
  l1 = inicializa(); /* inicia lista vazia */
  l2 = inicializa(); /* inicia lista vazia */
	
  l1 = insere(l1, 23); /* insere na lista o elemento 23 */
	l1 = insere(l1, 45); /* insere na lista o elemento 45 */
	l1 = insere(l1, 56); /* insere na lista o elemento 56 */
	l1 = insere(l1, 78); /* insere na lista o elemento 78 */

  l2 = insere(l2, 23); /* insere na lista o elemento 23 */
	l2 = insere(l2, 45); /* insere na lista o elemento 45 */
	l2 = insere(l2, 56); /* insere na lista o elemento 56 */
	l2 = insere(l2, 78); /* insere na lista o elemento 78 */
	
  imprime(l1); /* imprimir�: 78 56 45 23 */
  imprime(l2); /* imprimir�: 78 56 45 23 */
	l1 = retira(l1, 78);
  l2 = retira(l2, 78);
	imprime(l1); /* imprimir�: 56 45 23 */
  imprime(l2); /* imprimir�: 56 45 23 */
	l1 = retira(l1, 45);
  l2 = retira(l2, 45);
	imprime(l1); /* imprimir�: 56 23 */
  imprime(l2); /* imprimir�: 56 23 */
	libera(l1);
  libera(l2);
  int x = igual (l1, l2);
  retiracircular(l1, 23);
	return 0;
}
