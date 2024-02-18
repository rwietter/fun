
// ###################### ÁRVORE GENÉRICA ################################
#include <stdio.h>
#include <stdlib.h>

struct arvgen {
	char info;
	struct arvgen *prim;
	struct arvgen *prox;
};

typedef struct arvgen ArvGen;

/* A estrutura arvgen, que representa o nó da árvore, é definida conforme
mostrado anteriormente. A função para criar uma folha deve alocar o nó e
inicializar seus campos, atribuindo NULL para os campos prim e prox, pois
trata-se de um nó folha. */
ArvGen* cria (char c)
{
	ArvGen* node = (ArvGen*) malloc(sizeof(ArvGen));
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
	a->prim == sa;
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
int busca (ArvGen* a, char c)
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











// 2------------------------------------------------------------------------
// ###################### ÁRVORE DE BALANCEAMENTO ################################
#include <stdlib.h>
#include <stdio.h>
typedef struct no {
	int v;
	int bal; /* hdir - hesq */
	struct no *esq, *dir;
} No;

int altura(No* t)
{
	if (t == NULL)
	return 0;
	int hesq = altura(t->esq);
	int hdir = altura(t->dir);
	return hesq > hdir ? hesq + 1 : hdir + 1;
}


No* cria(int v, No* esq, No* dir)
{
	No* node = (No*) malloc(sizeof(No));
	node->v = v;
	node->bal = (altura(esq)) - (altura(dir));
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
		return alturaAVL(altura(t->dir) - altura(t->esq));
	}
}












// 3--------------------------------------------------------------------------------
// ###################### ÁRVORE BINÁRIA DE BUSCA ################################
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
	Arv* node = (Arv*) malloc(sizeof(Arv));
	node->info = c;
	node->dir == sad;
	node->esq = sae;
	return node;
}

// Cria/instala um nodo em uma árvore binária de pesquisa
Arv* cria_abp(char c)
{
	Arv* node = (Arv*) malloc(sizeof(Arv));
	if (node == NULL)
	{
		node->info = c;
		node->esq = node->esq;
	}
	if (c < node->info)
	{
		node->info = c;
		node->esq = node->esq;
	}
	if (c > node->info)
	{
		node->info = c;
		node->dir = node->dir;
	}
	return node;
}












//  4 - O algoritmo de busca DFS
#include <stdio.h>
#include <stdlib.h>
#define vertex int

typedef struct node *link;
struct graph {
	int V;
	int A; 
	link *adj;
};

typedef struct graph *Graph;

struct node {
	vertex w;
	link next;
};

static link NEWnode( vertex w, link next) {
	link a = malloc( sizeof (struct node));
	a->w = w;
	a->next = next;
	return a;
}

Graph GRAPHinit( int V)
{
	vertex v;
	Graph G = malloc( sizeof *G);
	G->V = V;
	G->A = 0;
	G->adj = malloc( V * sizeof (link));
	for (v = 0; v < V; ++v)
	G->adj[v] = NULL;
	return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w)
{
	link a;
	for (a = G->adj[v]; a != NULL; a = a->next)
	if (a->w == w) return;
	G->adj[v] = NEWnode( w, G->adj[v]);
	G->A++;
}

/* Busca DFS
O algoritmo de busca DFS visita todos os vértices e todos os arcos do
grafo numa determinada ordem e atribui um número a cada vértice: o k-ésimo
vértice descoberto recebe o número k?.
A função GRAPHdfs() abaixo é uma implementação do algoritmo. A busca
poderia começar por qualquer vértice, mas é natural começá-la pelo vértice
0. A numeração dos vértices é registrada em um vetor pre[] indexado
pelos vértices.
Para simplificar o código, trataremos o vetor pre[] como variável global
e suporemos que o número de vértices não passa de 1000. (Veja abaixo o
exercício Alocação dinâmica.) Também trataremos como variável global o
contador cnt usada para a numeração: */
static int cont;
int pre[1000];
/* A função GRAPHdfs() faz uma busca em profundidade no grafo G. Ela
atribui um número de ordem pre[x] a cada vértice x de modo que o k-ésimo
vértice descoberto receba o número de ordem k. */
void GRAPHdfs( Graph G)
{
	cont = 0;
	vertex v;
	for (v = G->adj[v]; v < G->V; ++v)
	{
		pre[v] = -1;
	}
	for ( v = G->adj[v]; v < G->V; ++v)
	{
		if (pre[v] == -1)
		{
			dfsR(G, v);
		}
	}
}
/* A função GRAPHdfs() é apenas um invólucro; a busca propriamente dita é
realizada pela função recursiva dfsR(). Em geral, nem todos os vértices
estão ao alcance do primeiro vértice visitado em GRAPHdfs(), e portanto a
função dfsR() precisa ser invocada várias vezes por GRAPHdfs(). Cada uma
dessas invocações define uma [!] etapa da busca. A funçao dfsR() visita
todos os vértices de G que podem ser alcançados a partir do vértice v sem
passar por vértices já descobertos. A função atribui cnt+k a pre[x] se x
é o k-ésimo vértice descoberto. (O código supõe que G é
representado por listas de adjacência.) */
void dfsR( Graph G, vertex v)
{
	pre[v] = cont++;
	for (link a = G->adj[v]; a != NULL; a = a ->next)
	{
		vertex w = a->w;
	}
	if (pre[v] == -1)
	{
		dfsR(G, v);
	}
}







// 5 ------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define vertex int
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A estrutura graph representa
um grafo. O campo adj é um ponteiro para a matriz de adjacências do grafo.
O campo V contém o número de vértices e o campo A contém o número de arcos
do grafo. */
struct graph {
	int V; // Vertices
	int A; // Arestas
	int **adj;
};
/* Um Graph é um ponteiro para um graph, ou seja, um Graph contém o
endereço de um graph. */

typedef struct graph *Graph;

// Implementação dos TADs:
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinit() constrói
um grafo com vértices 0 1 .. V-1 e nenhum arco. */
static int **MATRIXint( int r, int c, int val);

Graph GRAPHinit( int V)
{
	Graph G = malloc( sizeof *G);
	G->V = V;
	G->A = 0;
	G->adj = MATRIXint(V,V,0);
	return G;
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função MATRIXint() aloca uma
matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe
valor val. */
static int **MATRIXint( int r, int c, int val)
{
	int **matriz = malloc(r * sizeof(int*));
	vertex i, j;
	for ( i = 0; i < r; ++i)
	{
		matriz[i] = malloc(c * sizeof(int));
	}
	for ( i = 0; i < r; ++i)
	{
		for ( j = 0; j < c; ++j)
		{
			matriz[i][j] = val;
		}
	}
	return matriz;
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinsertArc()
insere um arco v-w no grafo G. A função supõe que v e w são distintos,
positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não
faz nada. */
void GRAPHinsertArc( Graph G, vertex i, vertex j)
{
	if (G->adj[i][j] != 0)
	{
		G->adj[i][j] = 1;
		G->A++;
	}
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHremoveArc()
remove do grafo G o arco v-w. A função supõe que v e w são distintos,
positivos e menores que G->V. Se não existe arco v-w, a função não faz
nada. */
void GRAPHremoveArc( Graph G, vertex v, vertex w)
{
	if (G->adj[v][w] == 1)
	{
		G->adj[v][w] = 0;
		G->A--;
	}
}


// Pesquisa de largura pela primeira vez (BFS)
	// Problema: encontre o comprimento do caminho mais curto de s para cada nó;

// Pesquisa por profundidade (DFS)
