#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void Dijkstra (TipoGrafo grafo, TipoValorVertice Raiz){
	
	int Antecessor[TipoValorVertice];
	TipoPeso P[TipoValorVertice];
	boolean Itensheap[TipoValorVertice];
	TipoValorVertice Pos[TipoValorVertice];
	Vetor A;
	TipovalorVertice u, v;
/*Entram aqui os operadores de uma das implementações de grafos, bem
como o operador Constroi da implementação de filas de prioridades, assim
como os operadores RefazInd, RetiraMinInd e DiminuiChaveInd do Programa Constroi*/
	for (u= 0; u<Grafo.NumVertices){
		//Constroi o heap com todos os valores igual a Infinito
		Antecessor[u]=−1;
		p[u]=Infinito;
		A[u+1].Chave=u; //Heap a ser construido
		ItensHeap[u]=true;
		Pos[u]=u+1;
	}
	n=Grafo.NumVertices; //Tamanho do heap
	p[Raiz]=0;
	Constroi(A);

/*.
.
.
Projeto de Algoritmos – Cap.7 Algoritmos em Grafos – Seção 7.8 101
Algoritmo de Dijkstra - Implementação
.
.
.*/
	do{ //{enquanto heap nao vazio}

		u=RetiraMinInd(A).Chave;
		ItensHeap[u]=false;
			if (!ListaAdjVazia(u,Grafo)){
				Aux=PrimeiroListaAdj(u,Grafo); 
				FimListaAdj=false; 
				do{
					ProxAdj(u, Grafo, v , Peso, Aux, FimListaAdj);
					if (p[v] > p[u] + Peso){
						p[v]=p[u] + Peso;
						Antecessor[v]=u;
						DiminuiChaveInd(Pos[v] ,p[v] ,A);
						printf("Caminho: v[%d] v[%d] d[%d]", v, Antecessor[v], p[v]);
					}
				}while (!FimListaAdj);
			}
	}while (n >= 1);
}

void VisitaDfs (TipoValorVertice u){

	boolean FimListaAdj;
	TipoPeso Peso;
	Apontador Aux;
	TipoValorVertice v;

	strcpy(Cor[u],cinza);
	Tempo=Tempo + 1; 
	d[u]=Tempo;
	printf("Visita %d   Tempo descoberta:  %d  cinza", u, d[u]);
	if (!ListaAdjVazia(u, Grafo)){
		Aux=PrimeiroListaAdj(u, Grafo); 
		FimListaAdj=false;
		do{
			ProxAdj(u, Grafo, v , Peso, Aux, FimListaAdj);
			if Cor[v] = branco{
				Antecessor[v] := u; VisitaDfs (v );
			}
		}while (!FimListaAdj);
	}
	strcpy(Cor[u],preto);
	Tempo = Tempo + 1; 
	t[u] = Tempo;
	printf("Visita %d  Tempo termino: %d preto", u, t[u]);
}


void BuscaEmProfundidade (TipoGrafo Grafo){
	
	TipoValorTempo Tempo;
	TipoValorVertice x;
	TipoValorTempo d[TipoValorVertice], t[TipoValorVertice];
	TipoCor Cor[TipoValorVertice];
	int	Antecessor[TipoValorVertice ];
	//Entra aqui o procedimento VisitaDFS (a seguir)

	Tempo = 0;
	for (x = 0; x<Grafo.NumVertices-1; x++){
		strcpy(Cor[x], branco);
		Antecessor[x] = −1;
		}
	for (x = 0;  x<Grafo.NumVertices−1; x++){
		if (strcmp(Cor[x], branco){
			VisitaDfs(x);
		}
	}
}

void VisitaBfs (TipoValorVertice u){

	TipoValorVertice v; 
	Apontador Aux;
	boolean FimListaAdj;
	TipoPeso Peso;
	TipoItem Item; 
	TipoFila Fila;

	strcomp(Cor[u], cinza);
	Dist[u] = 0;
	FFVazia( Fila );
	Item.Vertice = u;
	Enfileira (Item, Fila );
	printf("Visita origem %d cor: cinza F: ", u);
	ImprimeFila ( Fila ); //readln; ñ entendi.
	do{
	Desenfileira(Fila , Item ); 
	u =Item.vertice;
		if (!ListaAdjVazia(u, Grafo)){
			Aux=PrimeiroListaAdj(u,Grafo); 
			FimListaAdj = false;
			do{
				ProxAdj(u, v , Peso, Aux, FimListaAdj);
				if (strcomp(Cor[v], branco)){
					strcpy(Cor[v],cinza);
					Dist[v]=Dist[u]+1;
					Antecessor[v]=u;
					Item.Vertice=v;
					Item.Peso=Peso;
					Enfileira (Item , Fila );
				}
			}while(FimListaAdj = false); 
		}
	strcpy(Cor[u],preto);
	printf( "Visita %d, Dist %d, Cor: preto, F: " , u, Dist[u]);
	ImprimeFila(Fila); //readln; ñ entendi.
	}while(!FilaVazia( Fila));
}

void BuscaEmLargura (TipoGrafo Grafo){

	int x = TipoValorVertice;
	int Dist[TipoValorVertice];
	TipoCor	Cor[TipoValorVertice]; //Não sei ao certo o que o tipo cor se refere;
	int Antecessor[TipoValorVertice];
	//Entra aqui o procedimento VisitaBfs (a seguir)
	for (x=0; x<((Grafo.NumVertices)−1); x++){
		strcpy(Cor[x],branco);
		Dist[x]=infinito; 
		Antecessor[x]=−1;
	}
	for (x=0; x<((Grafo.NumVertices)−1); x++){
		if (strcmp(Cor[x],branco){
			VisitaBfs(x);
		}
	}
}

main() {
	

}
