
#include <stdio.h>
#include <stdlib.h>
#define contSpace 8

typedef struct arvore
{
    int info;
    struct arvore* dir;
    struct arvore* esq;
}Arvore;

Arvore* cria()
{
    return NULL;
}

Arvore* insere(int valor, Arvore* dir, Arvore* esq)
{
    Arvore* node = (Arvore*) malloc(sizeof(Arvore));
    node->info = valor;
    node->dir = dir;
    node->esq = esq;
    return node;
}

int vazia(Arvore* arv)
{
    return arv == NULL;
}

void preOrdem(Arvore* arv)
{
    if (!vazia(arv))
    {
        printf("(%d) ", arv->info);
        preOrdem(arv->esq);
        preOrdem(arv->dir);
    }
    
}

void ordemSimetrica(Arvore* arv)
{
    if (!vazia(arv))
    {
        ordemSimetrica(arv->esq);
        printf("(%d) ", arv->info);
        ordemSimetrica(arv->dir);
    }
}

void posOrdem(Arvore* arv)
{
    if (!vazia(arv))
    {
        posOrdem(arv->esq);
        posOrdem(arv->dir);
        printf("(%d ", arv->info);
    }
    
}

void display_em_2D(Arvore* node, int espaco) 
{
	int i;
	if (node == NULL)
	{
		return;
	}
	espaco += contSpace;
	display_em_2D(node->dir, espaco);
	printf("\n");
	for (i = contSpace; i < espaco; i++)
	{
		printf(" ");
	}
	printf("%d\n", node->info); 
	display_em_2D(node->esq, espaco); 
}

void display_2D(Arvore* node) 
{
	display_em_2D(node, 0); 
}

int main(int argc, char const *argv[])
{
    Arvore* a1 = insere(2, cria(), cria());
    Arvore* a2 = insere(3, cria(), cria());
    Arvore* a3 = insere(4, a1, cria());
    Arvore* a4 = insere(5, a2, cria());
    Arvore* a5 = insere(6, a3, a4);
    display_2D(a5);
    preOrdem(a5);
    puts("");
    ordemSimetrica(a5);
    puts("");
    posOrdem(a5);

    return 0;
}

/*
Problema 1
Implemente versões diferentes da função imprime, percorrendo a
árvore em ordem simétrica e em pré/pósordem. Verifique o
resultado da aplicação das duas funções na árvore da Figura 13.5. 
*/
