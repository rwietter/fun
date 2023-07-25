#include <stdio.h>
#include <stdlib.h>
// Os v�rtices de nossos grafos ser�o representados por n�meros inteiros.  
// O conjunto de v�rtices ser�  0 1 2 ... V-1?.  Poder�amos usar o tipo-de-dados 
// int para representar v�rtices, mas � melhor ter um nome espec�fico para esse tipo:
/* V�rtices de grafos s�o representados por objetos do tipo vertex. */
#define vertex int

// A matriz de adjac�ncias de um grafo � uma matriz de 0's e 1's com colunas e linhas indexadas 
// pelos v�rtices.  Se  adj[][]  � uma tal matriz ent�o, para cada v�rtice v e cada v�rtice w,
// adj[v][w] = 1   se v-w � um arco  e
// adj[v][w] = 0   em caso contr�rio.

// Assim, a linha v da matriz adj[][] representa o leque de sa�da do v�rtice v e a coluna w da matriz 
// representa o leque de entrada do v�rtice w.  Por exemplo, veja a matriz de adjac�ncias do grafo cujos 
// arcos s�o  0-1 0-5 1-0 1-5 2-4 3-1 5-3 :
//  0 1 2 3 4 5    
//0 0 1 0 0 0 1
//1 1 0 0 0 0 1
//2 0 0 0 0 1 0
//3 0 1 0 0 0 0
//4 0 0 0 0 0 0
//5 0 0 0 1 0 0

// Como nossos grafos n�o t�m la�os, os elementos da diagonal da matriz de adjac�ncias s�o iguais a 0.  
// Se o grafo for n�o-dirigido, a matriz � sim�trica: adj[v][w] = adj[w][v].
//Um grafo � representado por uma struct graph que cont�m a matriz de adjac�ncias, o n�mero de v�rtices, 
//e o n�mero de arcos do grafo:

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A estrutura graph representa um grafo. O campo adj � um ponteiro 
//para a matriz de adjac�ncias do grafo. O campo V cont�m o n�mero de v�rtices e o campo A cont�m o n�mero de 
//arcos do grafo. */
struct graph {
   int V; // Vertices
   int A; // Arestas
   int **adj; 
};
/* Um Graph � um ponteiro para um graph, ou seja, um Graph cont�m o endere�o de um graph. */
typedef struct graph *Graph;

// Implementa��o dos TADs:
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHinit() constr�i um grafo com v�rtices 0 1 .. V-1 
e nenhum arco. */
static int **MATRIXint( int r, int c, int val);
Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o MATRIXint() aloca uma matriz com linhas 0..r-1 e 
colunas 0..c-1. Cada elemento da matriz recebe valor val. */
static int **MATRIXint( int r, int c, int val) { 
   int **m = malloc( r * sizeof (int *));
   vertex i, j; // do autor...
   for (i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for (i = 0; i < r; ++i)
      for (j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHinsertArc() insere um arco v-w no grafo G. 
A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se o grafo j� tem um arco v-w, 
a fun��o n�o faz nada. */
void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->A++;
   }
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHremoveArc() remove do grafo G o arco v-w. 
A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se n�o existe arco v-w, a fun��o 
n�o faz nada. */
void GRAPHremoveArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->A--;
   }
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHshow() imprime, para cada v�rtice v do grafo G, 
em uma linha, todos os v�rtices adjacentes a v. */
void GRAPHshow( Graph G) { 
   vertex v, w;
   for (v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}

/* Mostra toda a matriz */
void GRAPHshowAll( Graph G) { 
   vertex v, w;
   printf("    ");
   for (v = 0; v < G->V; ++v) 
   	printf( "%2d:", v);
   puts("");
   for (v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (w = 0; w < G->V; ++w)
            printf( " %2d", G->adj[v][w]);
      printf( "\n");
   }
}

main(){
	//  0 1 2 3 4 5    
	//0 0 1 0 0 0 1
	//1 1 0 0 0 0 1
	//2 0 0 0 0 1 0
	//3 0 1 0 0 0 0
	//4 0 0 0 0 0 0
	//5 0 0 0 1 0 0

	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 1);
	GRAPHinsertArc(G, 0, 5);
	GRAPHinsertArc(G, 1, 0);
	GRAPHinsertArc(G, 1, 5);
	GRAPHinsertArc(G, 2, 4);
	GRAPHinsertArc(G, 3, 1);
	GRAPHinsertArc(G, 5, 1);
	GRAPHshow(G);
	puts("");
	GRAPHshowAll(G);
}
