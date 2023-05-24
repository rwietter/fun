#include <stdio.h>
#include <string.h>

struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};
typedef struct arv Arv;


// Cria/instala um nodo em uma árvore binária
Arv* cria(char c, Arv* sae, Arv* sad)
{
	Arv* node = (Arv*)malloc(sizeof(Arv));
	node->info = c;
	node->dir = sad;
	node->esq = sae;
	return node;
}


// Cria/instala um nodo em uma árvore binária de pesquisa
Arv* cria_abp(char c)
{
	Arv* node = (Arv*)malloc(sizeof(Arv));
	if (node == NULL) // se árvore binária de busca estiver vazia
	{
		node->info = c;
		node->esq = node->dir; // o valor inserido vai para a memória da sub-árvore a esquerda
	}
	else if (c < node->info) // node->info == valor inserido | c valor entrando | se for menor vai a esquerda
	{
		node->info = c;
		node->esq = node->dir;
	}
	else if (c > node->info) // se for maior que o valor de entrada | vai para sub-árvore a direita
	{
		node->info = c;
		node->dir = node->esq;
	}

	return node;
}
