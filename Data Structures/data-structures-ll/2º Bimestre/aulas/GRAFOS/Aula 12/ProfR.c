#include <stdio.h>
#include <stdlib.h>
#define vertex int

// -------------- Graph ----------------------
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
// -------------------------------------------


// --------- Pilha ---------------------------
typedef struct no {
	int info;
  struct no* prox;
}No;

typedef struct pilha {
	No* prim;
}Pilha;
// --------------------------------------------.


// --------- TAD PILHA -----------------------
Pilha* criaPilha(void);
No* InsereNoInicio(No* l, int v);
void push(Pilha* p, int v);
int PilhaPop(int v);
int pilha_vazia();
// ------------------------------------------

// -------- TAD GRAPH -----------------------
//static link NEWnode( vertex w, link next)
Graph GRAPHinit( int V);
void GRAPHinsertArc( Graph G, vertex v, vertex w);
int marcado(link v);
void profundidade(Graph G, link v);
void display_AdjList(Graph G, link v);
// -------------------------------------------

// ------------ Pilha -----------------------

Pilha* criaPilha(void)
{
	Pilha* topo = (Pilha*) malloc(sizeof(Pilha));
	topo->prim = NULL;
	return topo;
}

No* InsereNoInicio(No* l, int v)
{
	Pilha* top;
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l; 
	return p;
}

void push(Pilha* p, int v)
{
	p->prim = InsereNoInicio(p->prim, v); // As funções que manipulam a pilha fazem uso dessas funções de lista:
}

int PilhaPop(int v)
{
	Pilha* top;
	Pilha* temp;
	if (top == NULL)
	{
		printf("Pilha vazia");
	}
	else
	{
		temp = top;
		printf("\nElemento deletado %d", temp->prim);
	}
	return 1;
}

int pilha_vazia(){
	No* i;
	Pilha* p;
	if (p->prim == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 1;
}

// ------------------------------------------


static link NEWnode( vertex w, link next)
{ 
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


int marcado(link v)
{
	return v->marcado;
}


/*
proc prof (v:nó)_
    var t, w: nó;
    var p: pilha;
    Início
        execute visite(v);
        execute marque(v);
        execute empilhe(v, p);
        enquanto pilha_vazia(p) faça
              t = topo(p);
              execute desempilha(p);
         para cada w adjacente a t faca
               se marcado(w) então
                    execute visite(w);
                    execute marque(w);
                    execute empilhe(t, p);
                    t = w;
Fim
Fim
Fim
*/
	
void profundidade(Graph G, link v)
{
	link a;
	//link t, w;
	Pilha* p1;
   
   printf(" %d\n", v->w); //execute visite(v);
   v->marcado = 1; //execute marque(v);
   push(p1, v->w); // empilha o vertex
   
   for (a = G->adj[v->w]; a != NULL; a = a->next)
   {
   	if (!marcado(a))
   	{
   		profundidade(G, a);
   	}
   }
   while(pilha_vazia())
   {
		push(p1, v->w); //empilha no topo
		PilhaPop(v->w); //remove do topo
   }
   for (a = G->adj[v->w]; a != NULL; a = a->next)
   {
   	if (!marcado(a))
   	{
			printf(" %d\n", v->w); //execute visite(v);
			v->marcado = 1; //execute marque(v);
			push(p1, v->w); // empilha o vertex
			profundidade(G, a); // faz a recursividade da função
   	}
   }
}


// print all adjacent vertices of given vertex
void display_AdjList(Graph G, link v)
{
	link a;
	for (a = G->adj[v->w]; a != NULL; a = a->next)
	{
		printf("%d, %d\n", G->V, G->A);
	}
	printf("\n");
}


// graph implementation
int main()
{
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
	Pilha* p;
	p = criaPilha();
	
	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 5);
	GRAPHinsertArc(G, 0, 1);
	GRAPHinsertArc(G, 1, 5);
	GRAPHinsertArc(G, 1, 0);
	GRAPHinsertArc(G, 2, 4);
	GRAPHinsertArc(G, 3, 1);
	GRAPHinsertArc(G, 5, 3);
	
	profundidade(G, G->adj[0]);
	display_AdjList(G, G->adj[0]);
	
	//void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
	//void GRAPHshow( Graph G); // implementar
	//void GRAPHshowAll( Graph G); // implementar
}