#include <stdlib.h>
#include <stdio.h>

typedef struct no {
	int v;
	int bal; /* hdir - hesq */
	struct no *esq, *dir;
}No;

int altura(No* t)
{
	if (t == NULL)
	{
		return 0;
	}
		
	int hesq = altura(t->esq);
	int hdir = altura(t->dir);
	return hesq > hdir ? hesq + 1 : hdir + 1;
	/**
	 *  operador ternário;
	 * ele tem duas partes para separar: a condição, o valor para verdadeiro e o valor para falso;
	 * somado a isto tem o operador >; assim, ele vai retornar hesq + 1 OU hdir + 1 dependendo de hesq > hdir.
	 **/
}


No* cria(int v, No* esq, No* dir)
{
	No* node = (No*) malloc(sizeof(No));
	node->v = v;
	node->bal = altura(dir) - altura(esq);
	node->dir = dir;
	node->esq = esq;
	return node;
}

/* Verifica se está ou não balanceada */
int verifica_AVL(No* t)
{
	if (t == NULL)
	{
		return 1;
	}
	else if (altura(t->dir) - altura(t->esq) <= 1)
	{
		return tamanho((altura(t->dir) - altura(t->esq)));
	}
}
