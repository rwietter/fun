// apresenta a implementa��o atrav�s de vetor de ponteiros.

#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "/home/ghost/Downloads/PED/ESTUDAR_PROVA/LISTAS_DE_EXERCÍCIOS/Lista2.1/QUES4/matrizSimetrica.h"


struct matrizSimetrica
{
	int linha;
	int coluna;
	int** vetmat;
};

#define ordem 2
int i, j;

Matriz* cria(int m, int n){
	int i;
	Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
	if (mat == NULL)
	{
		printf("Não há memória suficiente");
		exit(1);
	}
	mat->linha = m;
	mat->coluna = n;
	mat->vetmat = (int**) malloc(m*sizeof(int*));
	for ( i = 0; i < m; i++)
	{
		mat->vetmat[i] = (int*) malloc(n*sizeof(int)); 
	}
	return mat;
}

Matriz* insere(Matriz* mat, int i, int j, int v){
	if (i<0 || i>=mat->linha || j<0 || j>=mat->coluna)
	{
		printf("Não há memória suficiente");
		exit(1);
	}
	mat->vetmat[i][j] = v;
}

int acessa(Matriz* mat, int i, int j){
	for ( i = 0; i < ordem; i++)
	{
		for ( j = 0; j < ordem; j++)
		{
			if (i==j)
			{
				if (mat->vetmat[i][j] == 1)
				{
					return 1;
					return mat->vetmat[i][j];
				}
			}
			if (i!=j)
			{
				if (mat->vetmat[i][j] == 0)
				{
					return 0;
				}
			}
		}
	}
}

int main() {
	Matriz* m;
	int v, flag;
	m = cria(ordem, ordem);
	for ( i = 0; i < ordem; i++)
	{
		for ( j = 0; j < ordem; j++)
		{
			printf("Entre com o elemento: %i e %i: ", i, j); scanf("%d", &v);
			insere(m, i, j, v);
		}
	}
	for ( i = 0; i < ordem; i++)
	{
		for ( j = 0; j < ordem; j++)
		{
			if (acessa(m,j,i == 1))
			{
				flag = 1;
			}
		}
	}
	if (flag == 1)
	{
		printf("É uma matriz identidade");
	}
	else
	{
		printf("Não é uma matriz identidade");
	}
	return 0;
}

/*
struct matriz {
	int lin;
	int col;
	int** v;
};

Matriz* cria (int m, int n) {
	int i;
	Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
	if (mat == NULL) {
		printf("Mem�ria insuficiente!\n");
		exit(1);
	}
	mat->lin = m;
	mat->col = n;
	mat->v = (int**) malloc(m*sizeof(int*));
	for (i=0; i<m; i++)
		mat->v[i] = (int*) malloc(n*sizeof(int));
	return mat;
}

void libera (Matriz* mat) {
	int i;
	for (i=0; i<mat->lin; i++)
		free(mat->v[i]);
	free(mat->v);
	free(mat);
}

int acessa (Matriz* mat, int i, int j) {
	if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
		printf("Acesso inválido!\n");
		exit(1);
	}
	if (i>=j)
	{
		return mat->v[i][j];
	}
	else
	{
		return mat->v[j][i];
	}
}

void atribui (Matriz* mat, int i, int j, int v) {
	if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
		printf("Atribuição inválida!\n");
		exit(1);
	}
	mat->v[i][j] = v;
}

int linhas (Matriz* mat) {
	return mat->lin;
}

int colunas (Matriz* mat) {
	return mat->col;
}

Matriz *m;
int ordem=2, i, j;
int numero;
int flag;

int main() {
	m = cria (ordem, ordem);
	for(i=0; i<ordem; i++)
		for(j=0; j<ordem; j++) {
			printf("Entre c elemento linha %d coluna %d:", i, j);
			scanf("%d",&numero);
			atribui(m, i, j, numero);
		}
	printf("\nNumero de linhas da matriz %d\n", linhas(m));
	printf("\nNumero de colunas da matriz %d\n", colunas(m));
	puts("\nElementos da matriz:");
	for(i=0; i<ordem; i++){
		for(j=0; j<ordem; j++) {
			if (i!=j)
			{			
				if (acessa(m, i, j) == acessa(m, i, j) )
					{
						flag = 1;
					}
				}
			}
		}		
		if (flag == 1)
		{
			printf("A matriz é simétrica");
		}
		else
		{
			printf("A matriz não é simétrica");
		}
	libera (m);
	return 0;	
}

*/
/*
Problema 4
Usando apenas as operações definidas pelo TAD matriz, implemente uma função que determine se uma matriz
é ou não quadrada simétrica.
*/
