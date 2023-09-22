// Algoritmo de Dijkstra
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dijkstra.html#example-A

#include <stdio.h>
#include <stdlib.h>

#define vertex int
#define INFINITY 1000000000
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
   int cst; // custo!
};

static link NEWnode(vertex w, link next, int cst)
{
   link a = malloc(sizeof(struct node));
   a->w = w;
   a->next = next;
   a->cst = cst;
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

void GRAPHinsertArc(Graph G, vertex v, vertex w, int cst)
{
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next)
      if (a->w == w)
         return;
   G->adj[v] = NEWnode(w, G->adj[v], cst);
   G->A++;
}

vertex pa[1000];
int dist[1000];

void GRAPHsptD0(Graph G, vertex s)
{
   vertex v;
   for (v = 0; v < G->V; ++v)
      pa[v] = -1;
   pa[s] = s, dist[s] = 0;

   while (1)
   {
      int min = INFINITY;
      vertex x, y;
      vertex v;
      for (v = 0; v < G->V; ++v)
      {
         if (pa[v] == -1)
            continue;
         link a;
         for (a = G->adj[v]; a != NULL; a = a->next)
         {
            if (pa[a->w] != -1)
               continue;
            if (dist[v] + a->cst < min)
            {
               min = dist[v] + a->cst;
               x = v, y = a->w;
               //printf("MINIMO entre %d e %d eh %d\n", v, a->w, min);
            }
         }
      }
      if (min == INFINITY) /*A*/
         break;            /*B*/
      pa[y] = x, dist[y] = min;
      printf("x %d y %d dist %d\n", x, y, min);
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

   // Exemplo B.  Queremos encontrar uma SPT com raiz 0 no grafo com custos nos arcos definido a seguir.

   // 0-2 0-3 0-4 2-4 3-4 3-5 4-1 4-5 5-1 1-2
   // 70  50  30  10  10  20   0  30  50  30

   Graph G = GRAPHinit(6);
   GRAPHinsertArc(G, 0, 2, 70);
   GRAPHinsertArc(G, 0, 3, 50);
   GRAPHinsertArc(G, 0, 4, 30);
   GRAPHinsertArc(G, 2, 4, 10);
   GRAPHinsertArc(G, 3, 4, 10);
   GRAPHinsertArc(G, 3, 5, 20);
   GRAPHinsertArc(G, 4, 1, 0);
   GRAPHinsertArc(G, 4, 5, 30);
   GRAPHinsertArc(G, 5, 1, 50);
   GRAPHinsertArc(G, 1, 2, 30);
   GRAPHsptD0(G, 0);
   // MINIMO entre 0 e 4 eh 30
   // MINIMO entre 0 e 3 eh 50
   // MINIMO entre 4 e 1 eh 30
   // MINIMO entre 0 e 3 eh 50
   // MINIMO entre 0 e 2 eh 70
   // MINIMO entre 1 e 2 eh 60
   // MINIMO entre 3 e 5 eh 70
   // MINIMO entre 4 e 5 eh 60
   //void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
   //void GRAPHshow( Graph G); // implementar
   //void GRAPHshowAll( Graph G); // implementar
}
