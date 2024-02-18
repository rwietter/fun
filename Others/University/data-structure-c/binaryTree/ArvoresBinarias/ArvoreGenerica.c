
#include <stdio.h>
#include <stdlib.h>
#define contSpace 8

typedef struct Arvore
{
    int info;
    struct Arvore* prim;
    struct Arvore* prox;
}ArvGen;

int folhas (ArvGen* a);


ArvGen* insere(int valor)
{
    ArvGen *node = (ArvGen*) malloc(sizeof(ArvGen));
    node->info = valor;
    node->prim = NULL;
    node->prox = NULL;
    return node;
}

void organizaArvore(ArvGen* arv, ArvGen* subarv)
{
  	subarv->prox = arv->prim;
	arv->prim = subarv;
}

void display_em_2D(ArvGen* node, int espaco) 
{
	int i;
	if (node == NULL)
	{
		return;
	}
	espaco += contSpace;
	display_em_2D(node->prim, espaco);
	printf("\n");
	for (i = contSpace; i < espaco; i++)
	{
		printf(" ");
	}
	printf("%d\n", node->info); 
	display_em_2D(node->prox, espaco); 
}

void display_2D(ArvGen* node) 
{
	display_em_2D(node, 0); 
}

void imprime (ArvGen* a)
{
	ArvGen* p;
	printf("%d ",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
	{
		imprime(p);
	}
}

int main(int argc, char const *argv[])
{
    ArvGen* a = insere(6);
    ArvGen* b = insere(5);
    ArvGen* c = insere(4);
    ArvGen* d = insere(3);
    ArvGen* e = insere(2);
    ArvGen* f = insere(1);
    organizaArvore(a,b);
    organizaArvore(a,c);
    organizaArvore(a,d);
    organizaArvore(d,e);
    organizaArvore(b,f);
    display_2D(a);
    puts("");
    imprime(a);
    return 0;
}

/*
Problema 3

Implemente uma função que retorne a quantidade
de folhas de uma árvore com número variável
de filhos. Essa função deve obedecer ao protótipo: 
 
int folhas (ArvGen* a); 
*/
