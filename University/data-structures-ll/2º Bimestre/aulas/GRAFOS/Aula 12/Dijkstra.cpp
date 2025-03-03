// Algoritmo de Dijkstra
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dijkstra.html#example-A

#include <stdio.h>
#include <stdlib.h>

/* V�rtices de grafos s�o representados por objetos do tipo vertex. */
#define vertex int
#define INFINITY 1000000000
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
   int cst; // custo!
};

static link NEWnode( vertex w, link next, int cst) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   a->cst = cst;
   return a;                         
}

Graph GRAPHinit( int V) { 
   vertex v;	
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w, int cst) { 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v], cst);
   G->A++;
}

vertex pa[1000];
int dist[1000];

void GRAPHsptD0( Graph G, vertex s) 
{ 
   vertex v;
   for (v = 0; v < G->V; ++v) 
      pa[v] = -1;
   pa[s] = s, dist[s] = 0; 

   while (1) {
      int min = INFINITY;
      vertex x, y;
      vertex v;
      for (v = 0; v < G->V; ++v) {
         if (pa[v] == -1) continue;
         link a;
         for (a = G->adj[v]; a != NULL; a = a->next) {
            if (pa[a->w] != -1) continue;
            if (dist[v] + a->cst < min) {
               min = dist[v] + a->cst;
               x = v, y = a->w;
               //printf("MINIMO entre %d e %d eh %d\n", v, a->w, min);
            }
         }
      }
      if (min == INFINITY) /*A*/ break; /*B*/
      pa[y] = x, dist[y] = min;
      printf("x %d y %d dist %d\n", x, y, min);
   }
   printSolution(dist);
}

void GRAPHsptD1( Graph G, vertex s,vertex *pa, int *dist)
{
   bool tree[1000];
   // inicializa��o:
   for (vertex v = 0; v < G->V; ++v)
      pa[v] = -1, tree[v] = false, dist[v] = INFINITY;
   pa[s] = s, tree[s] = true, dist[s] = 0;
   for (link a = G->adj[s]; a != NULL; a = a->next) 
      pa[a->w] = s, dist[a->w] = a->cst;

   while (true) {
      // c�lculo de y:
      int min = INFINITY;
      vertex y;
      for (vertex z = 0; z < G->V; ++z) {
         if (tree[z]) continue;
         if (dist[z] < min) // A
            min = dist[z], y = z;
      }
      if (min == INFINITY) break;
      tree[y] = true;
      // atualiza��o de dist[] e pa[]:
      for (link a = G->adj[y]; a != NULL; a = a->next) {
         if (tree[a->w]) continue;
         if (dist[y] + a->cst < dist[a->w]) {
            dist[a->w] = dist[y] + a->cst; // B
            pa[a->w] = y;
         }
      }
   }
}


int printSolution(int dist[]) 
{
	vertex V = 3;
    printf("\nVertex\tDistancia para o seu destino\n"); 
    for (int i = 0; i <= V; i++) 
        printf("%d \t\t %d km\n", i, dist[i]); 
}



int distancia_X_tempo(int dist[])
{
	 for (a = G->adj[v]; a != NULL; a = a->next)
}


main() {
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
  
  Graph G = GRAPHinit(4);
	GRAPHinsertArc(G, 0, 1, 427);
	GRAPHinsertArc(G, 0, 2, 487);
	GRAPHinsertArc(G, 0, 3, 503);
	GRAPHsptD0(G, 0);
	GRAPHsptD1(G, 427, 0, 1);
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

/*
Problema 2
Dado o programa Dijkstra.c, implementar uma vers�o que calcule a dist�ncia entre as cidades de FW e 
Porto Alegre, considerando as rotas em azul e cinza, mostradas no mapa abaixo. O programa deve tamb�m 
informar a rota que passa por menos cidades e a rota com menor km.
*/
