// Matriz simétrica com vetor simples

// Usando um vetor simples para armazenar os elementos da matriz, dimensionamos o vetor
// com apenas s elementos. A estrutura que representa a matriz pode ser dada por:

struct matsim {
	int dim; /* matriz obrigatoriamente quadrada */
	float* v;
};

typedef struct matsim MatSim;

// Uma função para criar uma matriz simétrica pode ser dada por:

MatSim* cria (int n)
{
	int s = n*(n+1)/2;
	MatSim* mat = (MatSim*) malloc(sizeof(MatSim));
	mat->dim = n;
	mat->v = (float*) malloc(s*sizeof(float));
	return mat;
}

// O acesso aos elementos da matriz deve ser feito como se estivéssemos representando a
// matriz inteira. Se for um acesso a um elemento acima da diagonal (i<j), o valor de retorno
// é o elemento simétrico da parte inferior, que está devidamente representado. O
// endereçamento de um elemento da parte inferior da matriz é feito saltando-se os elementos
// das linhas superiores. Assim, se desejarmos acessar um elemento da quinta linha (i=4),
// devemos saltar 1+2+3+4 elementos, isto é, devemos saltar 1+2+...+i elementos, ou seja,
// i*(i+1)/2 elementos. Depois, usamos o índice j para acessar a coluna.

float acessa (MatSim* mat, int i, int j)
{
	int k; /* índice do elemento no vetor */
	if (i<0 || i>=mat->dim || j<0 || j>=mat->dim) {
		printf("Acesso inválido!\n”);
		exit(1);
	}
	if (i>=j)
		k = i*(i+1)/2 + j;
	else
		k = j*(j+1)/2 + i;
	return mat->v[k];
}


