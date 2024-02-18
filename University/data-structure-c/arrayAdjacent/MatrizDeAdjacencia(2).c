#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNumVertices 100
#define MaxNumArestas 4500

#define TipoValorVertice MaxNumVertices

typedef	int TipoPeso;
typedef struct  {
		TipoPeso Mat[TipoValorVertice][TipoValorVertice];
		int NumVertices[MaxNumVertices];
		int NumArestas[MaxNumArestas];
	} TipoGrafo;
typedef int Apontador;	

void FGVazio(TipoGrafo Grafo) {

	int i, j;

	for (i=0; i<Grafo.NumVertices;i++) 
		for (j=0; j<Grafo.NumVertices;j++) 
			Grafo.Mat[i][j] = 0;
}

void InsereAresta (int V1, int V2, TipoPeso Peso, TipoGrafo Grafo) {
	Grafo.Mat[V1][V2] = Peso;	
}

int ExisteAresta (int Vertice1, int Vertice2, TipoGrafo Grafo) {
	return Grafo.Mat[Vertice1][Vertice2] > 0;
}

int ListaAdjVazia (int Vertice, TipoGrafo Grafo ) {
	Apontador Aux; int ListaVazia;
	ListaVazia = 1 ; Aux = 0;
	while ( (Aux < Grafo.NumVertices) && (ListaVazia == 1) )
		if (Grafo.Mat[Vertice][Aux] > 0) {
			ListaVazia = 0;
			return ListaVazia;
		}
		else 
			Aux = Aux + 1;
	ListaVazia = 1;		
    return ListaVazia;
}

//-----------------------------Busca em profundidade-------------------------------------

typedef char TipoCor;

void PrimeiroListaAdj (TipoValorVertice Vertice, TipoGrafo Grafo)
{
	Apontador Aux;
	int Listavazia;
	
	Listavazia = 1;
	Aux = 0;
	while (Aux<Grafo.NumVertices && Listavazia){
		if (Grafo.Mat[Vertice] > 0){
			PrimeiroListaAdj = aux;
			Listavazia = 0;
		}
		else
			aux = aux + 1;
			if (aux == Grafo.NumVertices)
				printf("Erro : Lista adjacencia vazia");
	}
}

void ProxAdj (TipoValorVertice Vertice, TipoGrafo Grafo, TipoValorVertice Adj, TipoPeso Peso, Apontador Prox, int FimListaAdj)
{
	Adj = Prox;
	Peso = Grafo.Mat[Vertice];
	Prox = Prox + 1;
		while (Prox < Grafo.NumVertices && Grafo.Mat[Vertice] == 0){
			Prox = prox + 1;
			if (Prox == Grafo.NumVertices)
				FimListaAdj = 1;
			}
}

void VisitaDfs (TipoValorVertice u)
{
	int FimListaAdj;
	TipoPeso Peso;
	Apontador Aux;
	TipoValorVertice v;
	
	strcpy(Cor[u], "cinza");
	Tempo = Tempo + 1;
	d[u] = Tempo;
	printf ("Visita: %d Tempo Descoberta: %d Cinza", u, d[u]);
		if (!ListaAdjVazia(u, Grafo)){
			Aux = PrimeiroListaAdj(u, Grafo);
			FimListaAdj = 0;
			while(FimListaAdj == 1){
				ProxAdj (u, Grafo, v, Peso, Aux, FimListaAdj);
				if(strcmp(Cor[v],"branco") ==0 ){
					Antecessor[v] = u;
					VisitaDfs(v);
				}
			}
		}
		strcpy (Cor[u], "preto");
		Tempo = Tempo + 1;
		t[u] = Tempo;
			printf("Visita: %d Tempo Termino: Preto", u, t[u]);
}

void BuscaEmProfundidade (TipoGrafo Grafo)
{
	int Tempo, d[TipoValorVertice], t[TipoValorVertice];
	TipoValorVertice x;
	TipoCor Cor[TipoValorVertice];
	int Antecessor[TipoValorVertice];
	
	Tempo = 0;
	for (x = 0; x < Grafo.NumVertices; x++){
		Cor[x] = "branco";
		Antecessor[x] = 1;
	}
		for (x = 0; x < Grafo.NumVertices; x++){
			if(strcmp(Cor[x], "branco")==0)
				VisitaDfs(x);
		}
}

//---------------------------------------------------------------------------------

//-----------------------------Busca em Largura------------------------------------

int QUEUEget (void) {
   return fila[f_fila++];
}

void QUEUEput (int y) {
   fila[r_fila++] = y;
}

int QUEUEempty (void) {
	if (f_fila > r_fila)
		return 0;
	return 1;	 
}

void QUEUEinit(int trash) {
	f_fila = 0;
	r_fila = 0;
}

void QUEUEfree(void) {
	f_fila = 0;
	r_fila = 0;
} 

void VisitaBfs (TipoValorVertice u)
{
	TipoValorVertice v;
	Apontador Aux;
	int FimListaAdj;
	TipoPeso Peso;
	TipoItem Item;
	
	strcpy(Cor[u], "Cinza");
	Dist[u] = 0;
	QUEUEempty ();
	Item.Vertice = u;
	QUEUEput (Item);
		printf("Visita origem: %d Cor: Cinza",u);
		while (!QUEUEempty()){
			QUEUEget ();
			u = Item.Vertice;
			if (!ListaAdjVazia(u, Grafo)){
				Aux = PrimeiroListaAdj (u, Grafo);
				FimListaAdj = 0;
				while (FimListaAdj == 0){
					ProxAdj (u, v , Peso, Aux, FimListaAdj);
					if (strcmp(Cor[v],"branco")==0){
						strcpy(Cor[v],"cinza");
						Dist[v] = Dist[u] + 1;
						Antecessor[v] = u;
						Item.Vertice = v;
						Item.Peso = Peso;
						QUEUEput (Item);
					}
				}
			}
			strcpy(Cor[u],"preto");
			printf("Visita: %d Dist: % Cor: Preto", u, Dist[u]);
		}
}

void BuscaEmLargura (TipoGrafo Grafo)
{
	TipoValorVertice x;
	int Dist[TipoValorVertice];
	TipoCor Cor[TipoValorVertice];
	int Antecessor[TipoValorVertice];
	
	for (x = 0; x < Grafo.NumVertices; x++){
		strcpy(Cor[x], "branco");
		Dist[x] = 100000000;
		Antecessor[x] = 1;
	}
		for (x = 0; Grafo.NumVertices; x++){
			if (strcmp(Cor[x],"branco")==0)
				VisitaBfs(x);
		}
}

//---------------------------------------------------------------------------------

//-----------------------------Dijkstra--------------------------------------------

void Dijkstra (TipoGrafo Grafo, TipoValorVertice Raiz)
{
	int Antecessor[TipoValorVertice];
	TipoPeso P[TipoValorVertice];
	int Itensheap[TipoValorVertice];
	TipoValorVertice Pos[TipoValorVertice];
	Vetor A;
	TipoValorVertice u, v;
	
	for (u = 0; u < Grafo.NumVertices; u++){
		Antecessor[u] = 1;
		p[u] = 100000000;
		A[u+1].Chave = u;
		Itensheap[u] = 1;
		Pos[u] = u+1;
	}
	n = Grafo.NumVertices;
	p[Raiz] = 0;
	Constroi(A);
		while (n >= 1){
			u = RetiraMinInd(A);
			Itensheap[u] = 0;
				if (!ListaAdjVazia(u, Grafo)){
					Aux = PrimeiroListaAdj(u, Grafo);
					FimListaAdj = 0;
						while (!FimListaAdj){
							ProxAdj(u, Grafo, v , Peso, Aux, FimListaAdj);
							if (p[v] > p[u] + peso){
								p[v] = p[u] + peso;
								Antecessor[v] = u;
								DiminuiChaveInd(Pos, p, A);
								printf("Caminho: %d %d %d ", v[v], v[Antecessor[v]], d[p[v]]);
							}
						}
				}
		}
}

main() {
	
}




