#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

//Matriz com vetor de ponteiros

// O m�dulo de implementa��o usando a estrat�gia de representar a matriz por um vetor de
// ponteiros � apresentado a seguir. O tipo que representa a matriz, neste caso, pode ser dado
// por:

struct matriz {
	int lin;
	int col;
	float** v;
};

typedef struct matriz Matriz;

// As fun��es para criar uma nova matriz e para liberar uma matriz previamente criada podem
// ser dadas por:

Matriz* cria (int m, int n)
{
	int i;
	Matriz mat = (Matriz*) malloc(sizeof(Matriz));
	mat->lin = m;
	mat->col = n;
	mat->v = (float**) malloc(m*sizeof(float*));
	for (i=0; i<m; i++)
		mat->v[i] = (float*) malloc(n*sizeof(float));
	return mat;
}

void libera (Matriz* mat)
{
	int i;
	for (i=0; i<mat->lin; i++)
		free(mat->v[i]);
	free(mat->v);
	free(mat);
}

//As fun��es para acessar e atribuir podem ser implementadas conforme ilustrado abaixo:

float acessa (Matriz* mat, int i, int j)
{
	if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
		printf("Acesso inv�lido!\n");
		exit(1);
	}
	return mat->v[i][j];
}

void atribui (Matriz* mat, int i, int j, float v)
{
	if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
		printf("Atribui��o inv�lida!\n");
		exit(1);
	}
	mat->v[i][j] = v;
}
