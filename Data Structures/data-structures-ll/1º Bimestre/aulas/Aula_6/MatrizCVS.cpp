#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

// Matriz com vetor simples

// Usando a estrat�gia com um vetor simples, o tipo matriz pode ser representado por uma
// estrutura que guarda a dimens�o da matriz e o vetor que armazena os elementos.

struct matriz {
	int lin;
	int col;
	float* v;
};

typedef struct matriz Matriz; // Matriz representada por um vetor simples

// A fun��o que cria a matriz dinamicamente deve alocar a estrutura que representa a matriz e
// alocar o vetor dos elementos:

Matriz* cria (int m, int n)
{
	Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
	mat->lin = m;
	mat->col = n;
	mat->v = (float*) malloc(m*n*sizeof(float));
	return mat;
}

// Poder�amos ainda incluir na cria��o uma inicializa��o dos elementos da matriz, por
// exemplo atribuindo-lhes valores iguais a zero.

// A fun��o que libera a mem�ria deve liberar o vetor de elementos e ent�o liberar a estrutura
// que representa a matriz:

void libera (Matriz* mat)
{
	free(mat->v);
	free(mat);
}

// A fun��o de acesso e atribui��o pode fazer um teste adicional para garantir que n�o haja
// invas�o de mem�ria. Se a aplica��o que usa o m�dulo tentar acessar um elemento fora das
// dimens�es da matriz, podemos reportar um erro e abortar o programa. A implementa��o
// destas fun��es pode ser dada por:

float acessa (Matriz* mat, int i, int j)
{
	int k; /* �ndice do elemento no vetor */
	if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
		printf("Acesso inv�lido!\n");
		exit(1);
	}
	k = i*mat->col + j;
	return mat->v[k];
}

void atribui (Matriz* mat, int i, int j, float v)
{
	int k; /* �ndice do elemento no vetor */
	if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
		printf("Atribui��o inv�lida!\n");
	exit(1);
	}
	k = i*mat->col + j;
	mat->v[k] = v;
}
