#include <stdio.h>
#include <stdlib.h>

#define vertex int

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A estrutura graph representa
um grafo. O campo adj é um ponteiro para a matriz de adjacências do grafo.
O campo V contém o número de vértices e o campo A contém o número de arcos
do grafo. */

struct graph {
	int Vertice; // Vertices
	int Aresta; // Arestas
	int **adjacente;
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
	Graph node = (Graph)malloc(sizeof(Graph));
	node->Vertice = V;
	node->Aresta = 0;
	node->adjacente = MATRIXint(V, V, 0);
	return node;
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função MATRIXint() aloca uma
matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe
valor val. */

static int **MATRIXint( int r, int c, int val)
{
	int **matriz = malloc(r * sizeof(int *)); // aloca memória para a matriz
	int i, j;

	for ( i = 0; i < r; i++)
	{
		matriz[i] = malloc(c * sizeof(int)); // aloca memória para a linha
	}

	for ( i = 0; i < r; i++)
	{
		for ( j = 0; j < c; j++)
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

void GRAPHinsertArc( Graph G, vertex v, vertex w)
{

}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHremoveArc()
remove do grafo G o arco v-w. A função supõe que v e w são distintos,
positivos e menores que G->V. Se não existe arco v-w, a função não faz
nada. */

void GRAPHremoveArc( Graph G, vertex v, vertex w)
{

}
