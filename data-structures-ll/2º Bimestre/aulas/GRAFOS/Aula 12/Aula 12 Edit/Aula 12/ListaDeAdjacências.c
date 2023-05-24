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
   int marcado; // 0 não, 1 marcado
   link next; 
};

typedef struct node *Node;

static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

/*
int marcado(struct node *v)
{
	return v->marcado;
}

void prof(Graph G)
{
	struct node *a = G;
	// execute e visite;
	//printf("%d\n", v);
	a->marcado = 1;
	int v=0;
	while(a != NULL)
	{
		if(!marcado(a))
		{
			printf("%d\n", G->adj[v++]);
			prof(G);
		}
		a = a->next;
	}
	
	for (a = G->adj[v]; a != NULL; a = a->next)
	{
		if(!marcado(w))
		{
			prof(w);
		}
	}
	
}
*/

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

void GRAPHinsertArc( Graph G, vertex v, vertex w)
{ 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next)
   {
   		if (a->w == w)
		{
		   	return;
		}
   }
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}


int marcado(link a)
{
	return a->marcado;
}

void prof(Graph G, vertex v)
{
	link a;
	printf("%d\n", v->w); // visite
	/*
	for (a = G->adj[v]; a != NULL; a = a->next)
	{
		printf("%d", a->w); //visite
		a->marcado = 1;
	}
	*/
	for (a = G->adj[v]; a != NULL; a = a->next)
	{
		if(!marcado(a))
		{
			printf("%d\n", v->w);
			prof(G, v);
		}
	}
}

main() {
//0: 5 1
//1: 5 0
//2: 4
//3: 1
//4:  
//5: 3
	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 1);
	prof(&G->adj[0]);
	
	//void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
	//void GRAPHshow( Graph G); // implementar
	//void GRAPHshowAll( Graph G); // implementar
}
