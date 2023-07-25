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
   int marcado;	// 0 nao e 1 marcado
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
      G->adj[v] = NULL;
   return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}

int marcado(link v) {
	return v->marcado;
}

void profr (Graph G, link v) {
   link a;
   
   printf(" %d", v->w); //execute visite(v);
   v->marcado = 1; //execute marque(v);
   
   for (a = G->adj[v->w]; a != NULL; a = a->next) 
      if (!marcado(a))
      	profr(G, a);

	//for (w = G.adj[v]; w != NULL; w = w.next) 
		//se NAO marcado(w) entao execute profr(w)
		//if (!marcado(w))
			//profr(w);

	//para cada w adjacente a v faça
			//se NAO marcado(w) entao execute profr(w)		
}
	

main() {
//0: 5 1
//1: 5 0
//2: 4
//3: 1
//4:  
//5: 3
	//  0 1 2 3 4 5    
	//0 0 1 0 0 0 1
	//1 1 0 0 0 0 1
	//2 0 0 0 0 1 0
	//3 0 1 0 0 0 0
	//4 0 0 0 0 0 0
	//5 0 0 0 1 0 0
	
	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 5);
	GRAPHinsertArc(G, 0, 1);
	GRAPHinsertArc(G, 1, 5);
	GRAPHinsertArc(G, 1, 0);
	GRAPHinsertArc(G, 2, 4);
	GRAPHinsertArc(G, 3, 1);
	GRAPHinsertArc(G, 5, 3);
	
	profr(G, G->adj[0]);
	
	//void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
	//void GRAPHshow( Graph G); // implementar
	//void GRAPHshowAll( Graph G); // implementar
}	
