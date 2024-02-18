#include <stdio.h>
#include <stdlib.h>

/*
 * Uma solução que leva a um aproveitamento
 * melhor do espaço utiliza uma “lista de filhos”: um nó
 * aponta apenas para seu primeiro (prim) filho, e cada
 * um de seus filhos, exceto o último, aponta para o
 * próximo (prox) irmão. 
 */
	// node->prox = node->prim;
	// node->prim = node->prox;

struct arvgen {
	char info;
	struct arvgen *prim;
	struct arvgen *prox;
};

typedef struct arvgen ArvGen;

ArvGen* cria (char c)
{
	// Cria nós folhas e inicializa os nós prim e prox
	ArvGen *a =(ArvGen *) malloc(sizeof(ArvGen));
	a->info = c;
	a->prim = NULL;
	a->prox = NULL;
	return a;
}

void insere (ArvGen* a, ArvGen* sa)
{
	// Insere uma sub-árvore no início
	sa->prox = a->prim;
	a->prim = sa;
}

void imprime (ArvGen* a)
{
	ArvGen* p;
	printf("%c ",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
	{
		imprime(p);
	}
}

void imprime_alt (ArvGen* a)
{
	ArvGen* p;
	printf("<%c", a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
	{
		imprime_alt(p);
	}
	printf(">");	
}


int busca (ArvGen* a, char c)
{
	// busca de informação
	ArvGen* p;
	if (a->info == c)
	{
		return 1;
	}
	else
	{
		for (p=a->prim; p!=NULL; p=p->prox)
		{
			if (busca(p,c))
			{
				return 1;
			}
		}
	}
	return 0;
}


void libera (ArvGen* a)
{
	// usar pós ordem para liberar as sub-árvores antes de liberar o espaço
	ArvGen* p = a->prim;
	while (p!=NULL)
	{
		ArvGen* t = p->prox;
		libera(p);
		p = t;
	}
	free(a);
}

ArvGen *copia(ArvGen *a)
{
	ArvGen *b = (ArvGen *)malloc(sizeof(ArvGen));
	b->info=a->info;
	b->prim = NULL;
	b->prox = NULL;

	if (a->prim != NULL)
	{
		b->prim = copia(a->prim);
	}
	if (a->prox != NULL)
	{
		b->prox = copia(a->prox);
	}
	printf("%c\n",b->info);
	return b;
}

int conta (ArvGen* a)
{
	if (a == NULL)
	{
		return 0;
	}
	else
	{

	}
	int conte = 0, contd = 0;
	if (a->prim != NULL)
	{
		conte = conta(a->prim);
	}
	if (a->prox != NULL)
	{
		contd = conta(a->prox);
	}
	printf("%c\n",a->info);
	return conte + contd + 1;
}

int main()
{
	/* cria nós como folhas */
	system("cls");
	printf("\n\n\nARVORE GENERICA\n");
	ArvGen* a = cria('a');
	ArvGen* b = cria('b');
	ArvGen* c = cria('c');
	ArvGen* d = cria('d');
	ArvGen* e = cria('e');
	ArvGen* f = cria('f');
	ArvGen* g = cria('g');
	ArvGen* h = cria('h');
	ArvGen* i = cria('i');
	ArvGen* j = cria('j');
	/* monta a hierarquia */
	insere(c,d);
	insere(b,e);
	insere(b,c);
	insere(i,j);
	insere(g,i);
	insere(g,h);
	insere(a,g);
	insere(a,f);
	insere(a,b);
	imprime(a);
	imprime_alt(a);
	copia(a);
	conta(a);
}
