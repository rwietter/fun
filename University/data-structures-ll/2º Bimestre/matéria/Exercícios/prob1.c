#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvgen {
	int info;
	struct arvgen *prim;
	struct arvgen *prox;
};
typedef struct arvgen ArvGen;

/* A estrutura arvgen, que representa o nó da árvore, é definida conforme
mostrado anteriormente. A função para criar uma folha deve alocar o nó e
inicializar seus campos, atribuindo NULL para os campos prim e prox, pois
trata-se de um nó folha. */
ArvGen* cria (int c)
{
	ArvGen* node = (ArvGen*)malloc(sizeof(ArvGen));
	node->info = c;
	node->prim = NULL;
	node->prox = NULL;
	return node;
}
/* A função que insere uma nova sub-árvore como filha de um dado nó é
muito simples. Como não vamos atribuir nenhum significado especial para a
posição de um nó filho, a operação de inserção pode inserir a sub-árvore
em qualquer posição. Neste caso, vamos optar por inserir sempre no início
da lista que, como já vimos, é a maneira mais simples de inserir um novo
elemento numa lista encadeada.*/
void insere (ArvGen* a, ArvGen* sa)
{
	sa->prox = a->prim;
	a->prim = sa;
}

int vazia(ArvGen* a)
{
	if (a == NULL)
	{
		return 1;
	}
}
/* A operação para buscar a ocorrência de uma dada informação na árvore é
exemplificada abaixo: */
int busca (ArvGen* a, int c)
{
	ArvGen* rpt;
	if (!vazia(a))
	{
		if(a->info == c)
		{
			return 1;
		}
		busca(a,c);
	}
}

void imprime(ArvGen* a)
{
	ArvGen* node;
	printf("%d\n",a->info);
	for (node=a->prim; node!=NULL; node=node->prox)
	{
		imprime(node);
	}
}

int main(int argc, char const *argv[])
{
	
	ArvGen* x = cria(1);
	ArvGen* y = cria(2);
	ArvGen* z = cria(3);
	ArvGen* w = cria(4);
	ArvGen* m = cria(5);
	insere(w,m);
	insere(y,z);
	insere(x,w);
	insere(x,y);
	imprime(x);
	printf("\n\n\n%d", busca(x, 4));
	return 0;
}
