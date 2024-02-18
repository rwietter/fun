#include <stdio.h>
#include <stdlib.h>

//const MaxNumVertices = 100;
//MaxNumArestas = 4500;

#define MaxNumVertices 100
#define MaxNumArestas 4500

//type
//	TipoValorVertice = 0. .MaxNumVertices;
//	TipoPeso = integer ;
//	TipoGrafo = record
//		Mat: array[TipoValorVertice , TipoValorVertice] of TipoPeso;
//		NumVertices: 0. .MaxNumVertices;
//		NumArestas : 0 . .MaxNumArestas;
//	end;
//	Apontador = TipoValorVertice;

//typedef int TipoValorVertice[MaxNumVertices];

#define TipoValorVertice MaxNumVertices

typedef	int TipoPeso;
typedef struct  {
		TipoPeso Mat[TipoValorVertice][TipoValorVertice];
		int NumVertices[MaxNumVertices];
		int NumArestas[MaxNumArestas];
	} TipoGrafo;
typedef int Apontador;	

//procedure FGVazio(var Grafo: TipoGrafo) ;
void FGVazio(TipoGrafo Grafo) {
	//var i , j : integer ;
	int i, j;

	//for i := 0 to Grafo.NumVertices do
	//for j := 0 to Grafo.NumVertices do Grafo.mat[ i , j ] := 0;
	for (i=0; i<Grafo.NumVertices;i++) 
		for (j=0; j<Grafo.NumVertices;j++) 
			Grafo.Mat[i][j] = 0;
}

//procedure InsereAresta (var V1, V2: TipoValorVertice;
// TipoValorVertice V1
// TipoValorVertice V2
void InsereAresta (int V1, int V2, TipoPeso Peso, TipoGrafo Grafo) {
	Grafo.Mat[V1][V2] = Peso;	
}

//function ExisteAresta (Vertice1 , Vertice2 : TipoValorVertice; var Grafo: TipoGrafo) : boolean;
// TipoValorVertice Vertice1
// TipoValorVertice Vertice2
int ExisteAresta (int Vertice1, int Vertice2, TipoGrafo Grafo) {
	// ExisteAresta := Grafo.Mat[Vertice1 , Vertice2] > 0;
	return Grafo.Mat[Vertice1][Vertice2] > 0;
} // { ExisteAresta }

//{....Operador para obter a l ista de adjacentes....}
//function ListaAdjVazia (var Vertice : TipoValorVertice; var Grafo: TipoGrafo) : boolean;
// Vertice : TipoValorVertice
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
} // { ListaAdjVazia }



main() {
	

}
