// Busca em largura
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/bfs.html

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

static int num[1000];

int fila[1000], f_fila, r_fila;

int QUEUEget(void)
{
   return fila[f_fila++];
}

void QUEUEput(int y)
{
   fila[r_fila++] = y;
}

int QUEUEempty(void)
{
   if (f_fila > r_fila)
      return 0;
   return 1;
}

void QUEUEinit(int trash)
{
   f_fila = 0;
   r_fila = 0;
}

void QUEUEfree(void)
{
   f_fila = 0;
   r_fila = 0;
}

void GRAPHbfs(Graph G, vertex s)
{
   int cnt = 0;
   vertex v;
   for (v = 0; v < G->V; ++v)
      num[v] = -1;
   QUEUEinit(G->V);
   num[s] = cnt++; // descoberto!
   printf("Descoberto %d\n", num[s]);
   QUEUEput(s);

   while (QUEUEempty() != 0)
   {
      vertex v = QUEUEget();
      link a;
      for (a = G->adj[v]; a != NULL; a = a->next)
         if (num[a->w] == -1)
         {
            num[a->w] = cnt++; // descoberto!
            printf("Descoberto %d\n", num[a->w]);
            QUEUEput(a->w);
         }
   }
   QUEUEfree();
}

main()
{
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

   //queue            0 1 2 3 4 5
   //0                0 - - - - -
   //  2 3 4          0 - 1 2 3 -
   //    3 4          0 - 1 2 3 -
   //      4 5        0 - 1 2 3 4
   //        5        0 - 1 2 3 4
   //          1      0 5 1 2 3 4
   //                 0 5 1 2 3 4
   Graph G = GRAPHinit(6);
   GRAPHinsertArc(G, 0, 2);
   GRAPHinsertArc(G, 0, 3);
   GRAPHinsertArc(G, 0, 4);
   GRAPHinsertArc(G, 1, 2);
   GRAPHinsertArc(G, 1, 4);
   GRAPHinsertArc(G, 2, 4);
   GRAPHinsertArc(G, 3, 4);
   GRAPHinsertArc(G, 3, 5);
   GRAPHinsertArc(G, 4, 5);
   GRAPHinsertArc(G, 5, 1);
   GRAPHbfs(G, 0);
   //void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
   //void GRAPHshow( Graph G); // implementar
   //void GRAPHshowAll( Graph G); // implementar
}
