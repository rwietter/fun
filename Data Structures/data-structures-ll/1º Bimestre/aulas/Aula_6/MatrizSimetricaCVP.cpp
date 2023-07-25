// Matriz simétrica com vetor de ponteiros

// A estratégia de trabalhar com vetores de ponteiros para matrizes alocadas dinamicamente é
// muito adequada para a representação matrizes simétricas. Numa matriz simétrica, para
// otimizar o uso da memória, armazenamos apenas a parte triangular inferior da matriz. Isto
// significa que a primeira linha será representada por um vetor de um único elemento, a
// segunda linha será representada por um vetor de dois elementos e assim por diante. Como o
// uso de um vetor de ponteiros trata as linhas como vetores independentes, a adaptação desta
// estratégia para matrizes simétricas fica simples.
// O tipo da matriz pode ser definido por:

struct matsim {
	int dim;
	float** v;
};

typedef struct matsim MatSim;

// Para criar a matriz, basta alocarmos um número variável de elementos para cada linha. O
// código abaixo ilustra uma possível implementação:

MatSim* cria (int n)
{
	int i;
	MatSim* mat = (MatSim*) malloc(sizeof(MatSim));
	mat->dim = n;
	mat->v = (float**) malloc(n*sizeof(float*));
	for (i=0; i<n; i++)
		mat->v[i] = (float*) malloc((i+1)*sizeof(float));
	return mat;
}

// O acesso aos elementos é natural, desde que tenhamos o cuidado de não acessar elementos
// que não estejam explicitamente alocados (isto é, elementos com i<j).

float acessa (MatSim* mat, int i, int j)
{
	if (i<0 || i>=mat->dim || j<0 || j>=mat->dim) {
		printf("Acesso inválido!\n”);
		exit(1);
	}
	if (i>=j)
		return mat->v[i][j];
	else
		return mat->v[j][i];
}

//  Finalmente, observamos que exatamente as mesmas técnicas poderiam ser usadas para
// representar uma matriz “triangular”, isto é, uma matriz cujos elementos acima (ou abaixo)
// da diagonal são todos nulos. Neste caso, a principal diferença seria na função acessa, que
// teria como resultado o valor zero em um dos lados da diagonal, em vez acessar o valor
// simétrico.
