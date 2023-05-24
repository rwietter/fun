#include <stdio.h>
#include <stdlib.h>

#define vertex int
typedef struct node *link;

struct graph
{
	int V;
	int A; 
	link *adj;
};
typedef struct graph *Graph;

struct node
{
	vertex w;
	link next;
};

static link NEWnode( vertex w, link next) {
	link a = malloc( sizeof (struct node));
	a->w = w;
	a->next = next;
	return a;
}
Graph GRAPHinit( int V) {
	vertex v;
	Graph G = malloc( sizeof *G);
	G->V = V;
	G->A = 0;
	G->adj = malloc( V * sizeof (link));
	for (v = 0; v < V; ++v)
	{
		G->adj[v] = NULL;
	}
	return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) 
{
	link a;
	for (a = G->adj[v]; a != NULL; a = a->next)
	{
		if (a->w == w)
		{
			return;
		}
		G->adj[v] = NEWnode( w, G->adj[v]);
		G->A++;
	}
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
static int cnt;
int pre[1000];
/* A função GRAPHdfs() faz uma busca em profundidade no grafo G. Ela
atribui um número de ordem pre[x] a cada vértice x de modo que o k-ésimo
vértice descoberto receba o número de ordem k. */
void GRAPHdfs(Graph G)
{
	// busca em profundidade

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
void dfsR(Graph G, vertex v)
{
	// busca em largura
	
}
