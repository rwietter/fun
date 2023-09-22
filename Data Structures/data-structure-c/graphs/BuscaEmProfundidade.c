// Busca em profundidade
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dfs.html

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

static link NEWnode(vertex w, link next)
{
   link a = malloc(sizeof(struct node));
   a->w = w;
   a->next = next;
   return a;
}

Graph GRAPHinit(int V)
{
   vertex v;
   Graph G = malloc(sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = malloc(V * sizeof(link));
   for (v = 0; v < V; ++v)
      G->adj[v] = NULL;
   return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w)
{
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next)
      if (a->w == w)
         return;
   G->adj[v] = NEWnode(w, G->adj[v]);
   G->A++;
}

static int cnt;
int pre[1000];

void GRAPHdfs(Graph G)
{
   cnt = 0;
   vertex v;
   for (v = 0; v < G->V; ++v)
      pre[v] = -1;
   for (v = 0; v < G->V; ++v)
      if (pre[v] == -1)
         dfsR(G, v); // come�a nova etapa
}

void dfsR(Graph G, vertex v)
{
   pre[v] = cnt++; // descoberto!
   printf("Descoberto %d\n", pre[v]);
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next)
   {
      vertex w = a->w;
      if (pre[w] == -1)
         dfsR(G, w);
   }
}

main()
{
   // Por exemplo, eis o vetor de listas de adjac�ncia do grafo
   // cujos arcos s�o  0-1 0-5 1-0 1-5 2-4 3-1 5-3 :

   //	0: 5 1
   //	1: 5 0
   //	2: 4
   //	3: 1
   //	4:
   //	5: 3
   //	Graph G = GRAPHinit(6);
   //	GRAPHinsertArc(G, 0, 5);
   //	GRAPHinsertArc(G, 0, 1);
   //	GRAPHinsertArc(G, 1, 5);
   //	GRAPHinsertArc(G, 1, 0);
   //	GRAPHinsertArc(G, 2, 4);
   //	GRAPHinsertArc(G, 3, 1);
   //	GRAPHinsertArc(G, 5, 3);

   // Exemplo A.  Considere o grafo G definido pelos arcos  0-1 1-2 1-3 2-4 2-5 .
   // Veja a matriz de adjac�ncias (com - no lugar de 0) e as listas de adjac�ncia do grafo:

   // - 1 - - - -    0:  1								0
   // - - 1 1 - -    1:  2 3							1
   // - - - - 1 1    2:  4 5						2		3
   // - - - - - -    3:						4		5
   // - - - - - -    4:
   // - - - - - -    5:
   Graph G = GRAPHinit(6);
   GRAPHinsertArc(G, 0, 1);
   GRAPHinsertArc(G, 1, 2);
   GRAPHinsertArc(G, 1, 3);
   GRAPHinsertArc(G, 2, 4);
   GRAPHinsertArc(G, 2, 5);
   GRAPHdfs(G);
   //void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
   //void GRAPHshow( Graph G); // implementar
   //void GRAPHshowAll( Graph G); // implementar
}
