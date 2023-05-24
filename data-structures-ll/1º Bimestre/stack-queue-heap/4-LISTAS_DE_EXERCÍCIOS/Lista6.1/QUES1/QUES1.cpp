#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

using namespace std;

#define m 2
#define n 2

// Matriz simples
struct mat {
  int lin; // guarda a dimensão de linhas
  int col; // guarda a dimensão de colunas
  int* v; // guarda o vetor
};
typedef struct mat Matriz;

Matriz* cria();
void imprime(Matriz* mat);

int main()
{
  Matriz* mat;
  mat = cria();
  imprime(mat);
  return 0;
}

Matriz* cria(){
  Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
  mat->lin = m;
  mat->col = n;
  mat->v = (int*) malloc(m*n*sizeof(int));
  cout << mat->col << endl;
  cout << mat->lin << endl;
  cout << mat->v << endl;
  return mat;
}

Matriz* insere()
{
  Matriz* p;
  for (p->lin = 0; p->lin < m; p->lin++)
  {
    for (p->col = 0; p->col < n; p->col++)
    {
      p->v[p->col*m+p->lin] = mat[p->lin*n+p->col];
    }
  }
}

void imprime(Matriz* mat){
	int i;
	int j;
	Matriz* p;
	for (p->lin = 0; p->lin < 3; p->lin++)
	{
		for ( p->col = 0; p->col < 3; p->col++){
			printf("%d\n", p->v[p->col*m+p->lin]);
		}
	}
}

/*
Problema 1
Escreva um programa que faça uso das operações de matriz definidas em aula. Note que a estratégia de
implementação não deve alterar o uso das operações
*/
