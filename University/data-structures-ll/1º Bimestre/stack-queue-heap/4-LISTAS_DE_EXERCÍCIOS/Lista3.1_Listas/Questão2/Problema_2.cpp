#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "/home/ghost/Downloads/EstruturasDeDados/ESTUDAR_PROVA/LISTAS_DE_EXERCÍCIOS/Lista3.1/Questão2/header.h";
using namespace std;

struct lista1
{
  int info;
  struct lista1* prox;
};

struct lista2
{
  int i;
  struct lista2* next;
};


Lista1* inicializa(void)
{
  return NULL;
}

Lista2* inicializa2(void)
{
  return NULL;
}

Lista1* insere (Lista1* l1, int i)
{
  /* inser��o no in�cio: retorna a lista atualizada */
	Lista1* novo = (Lista1*) malloc(sizeof(Lista1));
	
	novo->info = i;
	novo->prox = l1;
	return novo;
}

void imprime (Lista1* l1)
{
  Lista1* p; /* vari�vel auxiliar para percorrer a lista */
	
	for (p = l1; p != NULL; p = p->prox)
  {
		cout << "Lista 1: " << p->info << endl;
  }
}

void imprime2 (Lista2* l2)
{
  Lista2* p; /* vari�vel auxiliar para percorrer a lista */
	
	for (p = l2; p != NULL; p = p->next)
  {
		cout << "Lista 2: " << p->i << endl; 
  }
}

int vazia (Lista1* l1)
{
	if (l1 == NULL)
  {
		return 1;
  }
  else
  {
    return 0;
  }
}

void libera (Lista1* l1)
{
	Lista1* p = l1;

	while (p != NULL) {
		Lista1* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento */
	
		free(p); /* libera a mem�ria apontada por p */
		p = t; /* faz p apontar para o pr�ximo */
	}
}

Lista2* aloca (Lista2* l2, Lista1* l1)
{
  Lista2* nov = (Lista2*) malloc(sizeof(Lista2));
  Lista1* p;
  for ( p=l1; p != NULL; p = p->prox)
  {
    nov->i = l1->info;
  }
  return nov;
}

int main()
{
  Lista2* l2;
  Lista1* l1;
  l1 = inicializa();
  l2 = inicializa2();
  int x = vazia(l1);
  l1 = insere(l1, 28);
  l1 = insere(l1, 22);
  l1 = insere(l1, 12);
  l2 = aloca(l2, l1);
  imprime(l1);
  cout << endl;
  //cout << l2 << endl;
  imprime2(l2);
  libera(l1);

  return 0;
}


/*
Problema 2
Exercício: Implemente uma função que crie uma cópia de uma lista encadeada. O protótipo da função deve
ser dado por:
Lista* copia (Lista* l);
*/
