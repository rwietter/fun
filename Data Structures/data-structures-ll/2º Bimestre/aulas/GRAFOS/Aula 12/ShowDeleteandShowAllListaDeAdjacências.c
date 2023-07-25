#include <stdio.h>
#include <stdlib.h>

#define vertex int

typedef struct node *link;

struct graph
{
   int Vertice; 
   int Aresta; 
   link *adjacencia; 
};

typedef struct graph *Graph;

struct node
{ 
   vertex wertex; 
   link next; 
};

static link NEWnode(int w, link next)
{
	link a = malloc( sizeof (struct node));
	a->wertex = w;
	printf("Inserido %d; ", a->wertex);
	a->next = next;
	return a;                         
}

Graph GRAPHinit( int Valor) { 
   int v;	
   Graph Grafo = malloc( sizeof * Grafo);
   Grafo->Vertice = Valor; 
   Grafo->Aresta = 0;
   Grafo->adjacencia = malloc( Valor * sizeof (link));
   for (v = 0; v < Valor; ++v)
   {
	   Grafo->adjacencia[v] = NULL;
   }
   return Grafo;
}

void GRAPHinsertArc(Graph G, int v, int w)
{ 
   link a;
   for (a = G->adjacencia[v]; a != NULL; a = a->next) 
   {
   	if (a->wertex == w)
   	{
   		return;
   	}
   }
   G->adjacencia[v] = NEWnode(w, G->adjacencia[v]);
   G->Aresta++;
}

void GRAPHremoveArc( Graph G, int v, int w){
	link a;
	 for (a = G->adjacencia[v]; a != NULL; a = a->next) 
	{
		v++;
		G->adjacencia[v] = NULL;
	}
}

void GRAPHshow (Graph G)
{
	printf("Show graph\n");
	int v, w;
	link a;
   for (v = 0; v < G->Vertice; ++v)
   {
      printf( "%2d:", v);
      for (a = G->adjacencia[v]; a != NULL; a = a->next)
      {
      	printf("%2d ",a->wertex);
      }
   	printf( "\n");
	}
}


void GRAPHshowAll(Graph G)
{
	
	printf("Show All graph\n");
	int v, w;
	printf("    ");
	for (v = 0; v < G->Vertice; ++v)
	{
		printf( "%2d:", v);
	}
	link a;
	puts("");
	for (v = 0; v < G->Vertice; ++v)
	{
		printf( "%2d:", v);
		for (a = G->adjacencia[v]; a != NULL; a = a->next)
		{
            printf( " %2d", a->wertex);
         }
      printf( "\n");
      }
}

int main(void)
{
	system("cls");
	printf("\n\n\n");
	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 1);
	GRAPHinsertArc(G, 0, 5);
	GRAPHinsertArc(G, 1, 0);
	GRAPHinsertArc(G, 1, 5);
	GRAPHinsertArc(G, 2, 4);
	GRAPHinsertArc(G, 3, 1);
	GRAPHinsertArc(G, 5, 3);
	
	GRAPHshow(G);
	//GRAPHremoveArc(G, 0, 5);
	//puts("\n");
	//GRAPHshow(G);
	puts("");
	GRAPHshowAll(G);
	return 0;
}
