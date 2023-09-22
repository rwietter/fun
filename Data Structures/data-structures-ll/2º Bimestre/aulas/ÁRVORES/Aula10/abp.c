#include <stdio.h>
#include <stdlib.h>

//O tipo da árvore binária pode então ser dado por:
struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};
typedef struct arv Arv;

//A árvore é representada pelo ponteiro para o nó raiz. A árvore vazia é inicializada
//atribuindo-se NULL a variável que representa a árvore. Uma função simples de
//inicialização é mostrada abaixo:
Arv* init (void)
{
	return NULL;
}

//Uma vez construída uma árvore de busca, podemos imprimir os valores da árvore em
//ordem crescente percorrendo os nós em ordem simétrica:
void imprime (Arv* a)
{
	if (a != NULL) {
		imprime(a->esq);
		printf("%d\n",a->info);
		imprime(a->dir);
	}
}

//Essas são funções análogas às vistas para árvores binárias comuns, pois não exploram a
//propriedade de ordenação das árvores de busca. No entanto, as operações que nos
//interessa analisar em detalhes são:
//• busca: função que busca um elemento na árvore;
//• insere: função que insere um novo elemento na árvore;
//• retira: função que retira um elemento da árvore.

//Operação de busca
//A operação para buscar um elemento na árvore explora a propriedade de ordenação da
//árvore, tendo um desempenho computacional proporcional a sua altura (O(log n) para o
//caso de árvore balanceada). Uma implementação da função de busca é dada por:
Arv* busca (Arv* r, int v)
{
	if (r == NULL) return NULL;
	else if (r->info > v) return busca (r->esq, v);
	else if (r->info < v) return busca (r->dir, v);
	else return r;
}

//Operação de inserção
//A operação de inserção adiciona um elemento na árvore na posição correta para que a
//propriedade fundamental seja mantida. Para inserir um valor v em uma árvore usamos
//sua estrutura recursiva, e a ordenação especificada na propriedade fundamental. Se a
//(sub-) árvore é vazia, deve ser substituída por uma árvore cujo único nó (o nó raiz)
//contém o valor v. Se a árvore não é vazia, comparamos v com o valor na raiz da árvore,
//e inserimos v na sae ou na sad, conforme o resultado da comparação. A função abaixo
//ilustra a implementação dessa operação. A função tem como valor de retorno o eventual
//novo nó raiz da (sub-) árvore.
Arv* insere (Arv* a, int v)
{
	if (a==NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if (v < a->info)
		a->esq = insere(a->esq,v);
	else /* v < a->info */
		a->dir = insere(a->dir,v);
	return a;
}

//O código abaixo ilustra a implementação da função para retirar um elemento da árvore
//binária de busca. A função tem como valor de retorno a eventual nova raiz da (sub-)
//árvore.
Arv* retira (Arv* r, int v)
{
	if (r == NULL)
		return NULL;
	else if (r->info > v)
		r->esq = retira(r->esq, v);
	else if (r->info < v)
		r->dir = retira(r->dir, v);
	else { /* achou o elemento */
		if (r->esq == NULL && r->dir == NULL) { /* elemento sem filhos */
			free (r);
			r = NULL;
		}		
		else if (r->esq == NULL) { /* só tem filho à direita */
			Arv* t = r;
			r = r->dir;
			free (t);
		}
		else if (r->dir == NULL) { /* só tem filho à esquerda */
			Arv* t = r;
			r = r->esq;
			free (t);
		}
		else { /* tem os dois filhos */
			Arv* pai = r;
			Arv* f = r->esq;
			while (f->dir != NULL) {
				pai = f;
				f = f->dir;
			}
			r->info = f->info; /* troca as informações */
			f->info = v;
			r->esq = retira(r->esq,v);
		}	
	}
	return r;
}
